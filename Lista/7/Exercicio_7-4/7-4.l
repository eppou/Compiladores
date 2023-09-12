%option noyywrap

%{
    
    int linhas = 1;
    int linha_vazias = 0;
    int comentarios = 0;
    int nb_nc = 0; 
    int ponto_virgula = 0;
    int preprocessor_directives = 0;

    int total_linhas = 0;
    int total_linhas_vazias = 0;
    int total_comentarios = 0;
    int total_nb_nc = 0;
    int total_ponto_virgula = 0;
    int total_preprocessor_directives = 0;
%}

%x COMENTARIO

%%
<INITIAL>{
"/*" { BEGIN(COMENTARIO); }
";" { ponto_virgula++;}
"#include" { preprocessor_directives++;}
"#define" { preprocessor_directives++;}
"//" { comentarios++; }
^[ ]*[\n] { linha_vazias++; linhas++; }
[\n] { linhas++; }
. 
}

<COMENTARIO>{
"*/"    { comentarios++; BEGIN(INITIAL); }
[^*\n]+ 
"*"
[\n] { comentarios++; linhas++; }
}

%%

void resetValues(){
    linhas = 0;
    linha_vazias = 0;
    comentarios = 0;
    nb_nc = 0; 
    ponto_virgula = 0;
    preprocessor_directives = 0;
}

int main(int argc, char* argv[]) {
    char* filename; // Variável temporária para armazenar o nome do arquivo

    printf(" total   blank  lines w/   nb,nc   semi-   preproc. file\n");
    printf(" lines   lines  comments   lines   colons  direct.\n");
    printf("------+--------+--------+--------+--------+--------+----\n");

    if (argc < 2) {
        /* apenas leia a entrada padrão */
        yylex();
        filename = "stdin";
        nb_nc = linhas - linha_vazias - comentarios;
        printf("%d      %d        %d        %d        %d        %d        %s\n", linhas, linha_vazias, comentarios, nb_nc, ponto_virgula, preprocessor_directives, filename);
        return 0;
    }

    int i;
    for (i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");

        if (!f) {
            perror(argv[i]);
            return (1);
        }
        yyrestart(f);
        yylex();
        fclose(f);
        nb_nc = linhas - linha_vazias - comentarios;
        printf("%d      %d        %d        %d        %d        %d        %s\n", linhas, linha_vazias, comentarios, nb_nc, ponto_virgula,preprocessor_directives, argv[i]);
        total_linhas += linhas;
        total_linhas_vazias += linha_vazias;
        total_comentarios += comentarios;
        total_nb_nc += nb_nc;
        total_ponto_virgula += ponto_virgula;
        total_preprocessor_directives += preprocessor_directives;
        resetValues();
    }

    filename = "total";
    printf("%d %d %d %d %d %d %s\n", total_linhas, total_linhas_vazias, total_comentarios, total_nb_nc, total_ponto_virgula, total_preprocessor_directives, filename);
    return 0;
}
