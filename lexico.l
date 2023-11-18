%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <sintatico.tab.h>

int n_linhas = 1;
int n_colunas = 1;
int cmsl=0;  //linha do começo do comentario em bloco
int cmsc=0; //coluna do começo do comentario em bloco
int flag = 1; //flag para nao printar enter na primeira leitura
char buffer[1024]; //buffer para armazenar o que foi lido
int last_line = 0; //ultima linha lida

char* treatchar(char *str){
    char aux[strlen(str)];

        for (int i = 1; i < strlen(str) - 1; i++) {
            aux[i - 1] = str[i];
        }

        aux[strlen(str) - 2] = '\0';
        strcpy(str,aux);
        return str;
}

#define PRINT_TOKEN(token) {return token;}
#define PRINT_TOKEN_WITH_TEXT(token) {return token;}
#define PRINT_TOKEN_WITH_TEXT_CHAR(token) {return token;}
#define PRINT_COMMENT_WARNING {printf("warning:%i:%i: '/*' within block comment\n", n_linhas, n_colunas);}
#define PRINT_ERROR {printf("error:lexical:%i:%i: %s\n", n_linhas, n_colunas, yytext);exit(EXIT_FAILURE);}
#define PRINT_ERROR_ID {printf("error:lexical:%i:%i: identifier too long\n", n_linhas, n_colunas);exit(EXIT_FAILURE);}
#define PRINT_COMMENT_BLOCK_ERROR {printf("error:lexical:%i:%i: unterminated comment\n",cmsl,cmsc);exit(EXIT_FAILURE);}
#define COUNT_ERROR(n_colunas) {while(yytext[n_colunas] != '\0'){if(yytext[n_colunas] == '.'){n_colunas--;break;} n_colunas++;}}
 
%}

%x BLOCO_COMENTADO
%x LINHA_COMENTADA

%%

<INITIAL>{
("\n"|"\r")                 {n_linhas++; n_colunas=1;}
" "                         {n_colunas++;}
0[1-7][0-7]*                 {n_colunas+=yyleng; return NUM_OCTAL; }
0[xX][0-9a-fA-F]+      {n_colunas+=yyleng; return NUM_HEXA; }
[0-9]+                  {n_colunas+=yyleng; return NUM_INTEGER; }
"//"                    { n_colunas += 2; return LINHA_COMENTADA;}
"/*"                    {last_line = n_linhas;cmsc = n_colunas;cmsl=n_linhas; n_colunas += 2;BEGIN(BLOCO_COMENTADO);}
"void"                  {n_colunas+=yyleng; return VOID; }
"int"                   {n_colunas+=yyleng; return INT; }
"char"                  {n_colunas+=yyleng; return CHAR; }
"return"                {n_colunas+=yyleng; return RETURN; }
"break"                 {n_colunas+=yyleng; return BREAK; }
"switch"                {n_colunas+=yyleng; return SWITCH; }
"case"                  {n_colunas+=yyleng; return CASE; }
"default"               {n_colunas+=yyleng; return DEFAULT; }
"do"                    {n_colunas+=yyleng; return DO; }
"while"                 {n_colunas+=yyleng; return WHILE; }
"for"                   {n_colunas+=yyleng; return FOR; }
"if"                    {n_colunas+=yyleng; return IF; }
"else"                  {n_colunas+=yyleng; return ELSE; }
"typedef"               {n_colunas+=yyleng; return TYPEDEF; }
"struct"                {n_colunas+=yyleng; return STRUCT; }
"+"                     {n_colunas+=yyleng; return PLUS; }
"-"                     {n_colunas+=yyleng; return MINUS; }
"*"                     {n_colunas+=yyleng; return MULTIPLY; }
"/"                     {n_colunas+=yyleng; return DIV; }
"%"                     {n_colunas+=yyleng; return REMAINDER; }
"++"                    {n_colunas+=yyleng; return INC; }
"--"                    {n_colunas+=yyleng; return DEC; }
"&"                     {n_colunas+=yyleng; return BITWISE_AND; }
"|"                     {n_colunas+=yyleng; return BITWISE_OR; }
"~"                     {n_colunas+=yyleng; return BITWISE_NOT; }
"^"                     {n_colunas+=yyleng; return BITWISE_XOR; }
"!"                     {n_colunas+=yyleng; return NOT; }
"&&"                    {n_colunas+=yyleng; return LOGICAL_AND; }
"||"                    {n_colunas+=yyleng; return LOGICAL_OR; }
"=="                    {n_colunas+=yyleng; return EQUAL; }
"!="                    {n_colunas+=yyleng; return NOT_EQUAL; }
"<"                     {n_colunas+=yyleng; return LESS_THAN; }
">"                     {n_colunas+=yyleng; return GREATER_THAN; }
"<="                    {n_colunas+=yyleng; return LESS_EQUAL; }
">="                    {n_colunas+=yyleng; return GREATER_EQUAL; }
">>"                    {n_colunas+=yyleng; return R_SHIFT; }
"<<"                    {n_colunas+=yyleng; return L_SHIFT; }
"="                     {n_colunas+=yyleng; return ASSIGN; }
"+="                    {n_colunas+=yyleng; return ADD_ASSIGN; }
"-="                    {n_colunas+=yyleng; return MINUS_ASSIGN; }
";"                     {n_colunas+=yyleng; return SEMICOLON; }
","                     {n_colunas+=yyleng; return COMMA; }
":"                     {n_colunas+=yyleng; return COLON; }
"("                     {n_colunas+=yyleng; return L_PAREN; }
")"                     {n_colunas+=yyleng; return R_PAREN; }
"{"                     {n_colunas+=yyleng; return L_CURLY_BRACKET; }
"}"                     {n_colunas+=yyleng; return R_CURLY_BRACKET; }
"["                     {n_colunas+=yyleng; return L_SQUARE_BRACKET; }
"]"                     {n_colunas+=yyleng; return R_SQUARE_BRACKET; }
"?"                     {n_colunas+=yyleng; return TERNARY_CONDITIONAL; }
"#"                     {n_colunas+=yyleng; return NUMBER_SIGN; }
"->"                    {n_colunas+=yyleng; return POINTER; }
"printf"                {n_colunas+=yyleng; return PRINTF; }
"scanf"                 {n_colunas+=yyleng; return SCANF; }
"define"                {n_colunas+=yyleng; return DEFINE; }
"exit"                  {n_colunas+=yyleng; return EXIT; }

\"(\\.|[^"\\])*\"	        {n_colunas+=yyleng;return STRING; }
'([^'\\\n]|\\.)'            {n_colunas+=yyleng;return CHARACTER; }

[a-zA-Z_][a-zA-Z0-9_]*  { if (yyleng > 255){PRINT_ERROR_ID;} else{n_colunas+=yyleng;return IDENTIFIER;}}
.                       {PRINT_ERROR;}
}

<BLOCO_COMENTADO>{
    
"/"*"*/"                {last_line = n_linhas ;BEGIN(INITIAL); n_colunas += yyleng;}
"/*"                    {last_line = n_linhas ;PRINT_COMMENT_WARNING; n_colunas +=2;}

"\n"                    {n_colunas = 1; n_linhas++;}

<<EOF>>                 {PRINT_COMMENT_BLOCK_ERROR; return 0;}

.                       {n_colunas++;}

}

<LINHA_COMENTADA>{

"\n"                    {n_colunas = 1; BEGIN(INITIAL);}

.                       {n_colunas++;}

}

%%

void SET_buffer(int total_lines)
{
    //Seta o buffer para o inicio do arquivo
    fseek(stdin, 0, SEEK_SET);

    //For 
    for(int i = 0; i < total_lines; i++)
    {
        fgets(buffer, 1000, stdin);
    }
}
