%option noyywrap

%{
    #define PRINT_TEXT {printf("\n%s",yytext);}
    #define ERRO_TEXT {printf("\n%s","ERRO");}
%}

%%

"+"                         { PRINT_TEXT }
"-"                         { PRINT_TEXT }
"\n"
"\r"  
[a-z][a-z0-9]*              { PRINT_TEXT }
[0-9]+                      { PRINT_TEXT }
[0-9]+"e"("+"|"-")?[0-9]+   { PRINT_TEXT }
.                           { ERRO_TEXT }

%%

int main(int argc, char** argv){

    yylex();

    return 0;
}

