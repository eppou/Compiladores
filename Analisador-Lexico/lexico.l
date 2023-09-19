%option noyywrap

%{
#include <stdio.h>
#include <string.h>

int n_linhas = 1;
int n_colunas = 1;
int cmsl=0;  //linha do começo do comentario em bloco
int cmsc=0; //coluna do começo do comentario em bloco
int flag = 1; //flag para nao printar enter na primeira leitura

char* treatchar(char *str){
    char aux[strlen(str)];

        for (int i = 1; i < strlen(str) - 1; i++) {
            aux[i - 1] = str[i];
        }

        aux[strlen(str) - 2] = '\0';
        strcpy(str,aux);
        return str;
}

#define PRINT_TOKEN(token) {if(flag == 1){printf("%s",token); flag = 0;} else{printf("\n%s",token);}}
#define PRINT_TOKEN_WITH_TEXT(token) {if(flag == 1){printf("%s(%s)",token,yytext); flag = 0;} else{printf("\n%s(%s)",token,yytext);}}
#define PRINT_TOKEN_WITH_TEXT_CHAR(token) {if(flag == 1){printf("%s(%s)",token,treatchar(yytext)); flag = 0;} else{printf("\n%s(%s)",token,treatchar(yytext));}}
#define PRINT_COMMENT_WARNING {printf("\nwarning:%i:%i: '/*' within block comment", n_linhas, n_colunas);}
#define PRINT_ERROR {printf("\nerror:lexical:%i:%i: %s", n_linhas, n_colunas, yytext);}
#define PRINT_ERROR_ID {printf("\nerror:lexical:%i:%i: identifier too long", n_linhas, n_colunas);}
#define PRINT_COMMENT_BLOCK_ERROR {printf("\nerror:lexical:%i:%i: unterminated comment",cmsl,cmsc);}
 
%}

%x BLOCO_COMENTADO
%x LINHA_COMENTADA

%%

<INITIAL>{
("\n"|"\r")                 {n_linhas++; n_colunas=1;}
" "                         {n_colunas++;}
0[1-7][0-7]*                 {n_colunas+=yyleng; PRINT_TOKEN_WITH_TEXT("NUM_OCTAL"); }
0[xX][0-9a-fA-F]+      {n_colunas+=yyleng; PRINT_TOKEN_WITH_TEXT("NUM_HEXA"); }
[0-9]+                  {n_colunas+=yyleng; PRINT_TOKEN_WITH_TEXT("NUM_INTEGER"); }
"//"                    { n_colunas += 2; BEGIN(LINHA_COMENTADA);}
"/*"                    {cmsc = n_colunas;cmsl=n_linhas; n_colunas += 2;BEGIN(BLOCO_COMENTADO);}
"void"                  {n_colunas+=yyleng; PRINT_TOKEN("VOID"); }
"int"                   {n_colunas+=yyleng; PRINT_TOKEN("INT"); }
"char"                  {n_colunas+=yyleng; PRINT_TOKEN("CHAR"); }
"return"                {n_colunas+=yyleng; PRINT_TOKEN("RETURN"); }
"break"                 {n_colunas+=yyleng; PRINT_TOKEN("BREAK"); }
"switch"                {n_colunas+=yyleng; PRINT_TOKEN("SWITCH"); }
"case"                  {n_colunas+=yyleng; PRINT_TOKEN("CASE"); }
"default"               {n_colunas+=yyleng; PRINT_TOKEN("DEFAULT"); }
"do"                    {n_colunas+=yyleng; PRINT_TOKEN("DO"); }
"while"                 {n_colunas+=yyleng; PRINT_TOKEN("WHILE"); }
"for"                   {n_colunas+=yyleng; PRINT_TOKEN("FOR"); }
"if"                    {n_colunas+=yyleng; PRINT_TOKEN("IF"); }
"else"                  {n_colunas+=yyleng; PRINT_TOKEN("ELSE"); }
"typedef"               {n_colunas+=yyleng; PRINT_TOKEN("TYPEDEF"); }
"struct"                {n_colunas+=yyleng; PRINT_TOKEN("STRUCT"); }
"+"                     {n_colunas+=yyleng; PRINT_TOKEN("PLUS"); }
"-"                     {n_colunas+=yyleng; PRINT_TOKEN("MINUS"); }
"*"                     {n_colunas+=yyleng; PRINT_TOKEN("MULTIPLY"); }
"/"                     {n_colunas+=yyleng; PRINT_TOKEN("DIV"); }
"%"                     {n_colunas+=yyleng; PRINT_TOKEN("REMAINDER"); }
"++"                    {n_colunas+=yyleng; PRINT_TOKEN("INC"); }
"--"                    {n_colunas+=yyleng; PRINT_TOKEN("DEC"); }
"&"                     {n_colunas+=yyleng; PRINT_TOKEN("BITWISE_AND"); }
"|"                     {n_colunas+=yyleng; PRINT_TOKEN("BITWISE_OR"); }
"~"                     {n_colunas+=yyleng; PRINT_TOKEN("BITWISE_NOT"); }
"^"                     {n_colunas+=yyleng; PRINT_TOKEN("BITWISE_XOR"); }
"!"                     {n_colunas+=yyleng; PRINT_TOKEN("NOT"); }
"&&"                    {n_colunas+=yyleng; PRINT_TOKEN("LOGICAL_AND"); }
"||"                    {n_colunas+=yyleng; PRINT_TOKEN("LOGICAL_OR"); }
"=="                    {n_colunas+=yyleng; PRINT_TOKEN("EQUAL"); }
"!="                    {n_colunas+=yyleng; PRINT_TOKEN("NOT_EQUAL"); }
"<"                     {n_colunas+=yyleng; PRINT_TOKEN("LESS_THAN"); }
">"                     {n_colunas+=yyleng; PRINT_TOKEN("GREATER_THAN"); }
"<="                    {n_colunas+=yyleng; PRINT_TOKEN("LESS_EQUAL"); }
">="                    {n_colunas+=yyleng; PRINT_TOKEN("GREATER_EQUAL"); }
">>"                    {n_colunas+=yyleng; PRINT_TOKEN("R_SHIFT"); }
"<<"                    {n_colunas+=yyleng; PRINT_TOKEN("L_SHIFT"); }
"="                     {n_colunas+=yyleng; PRINT_TOKEN("ASSIGN"); }
"+="                    {n_colunas+=yyleng; PRINT_TOKEN("ADD_ASSIGN"); }
"-="                    {n_colunas+=yyleng; PRINT_TOKEN("MINUS_ASSIGN"); }
";"                     {n_colunas+=yyleng; PRINT_TOKEN("SEMICOLON"); }
","                     {n_colunas+=yyleng; PRINT_TOKEN("COMMA"); }
":"                     {n_colunas+=yyleng; PRINT_TOKEN("COLON"); }
"("                     {n_colunas+=yyleng; PRINT_TOKEN("L_PAREN"); }
")"                     {n_colunas+=yyleng; PRINT_TOKEN("R_PAREN"); }
"{"                     {n_colunas+=yyleng; PRINT_TOKEN("L_CURLY_BRACKET"); }
"}"                     {n_colunas+=yyleng; PRINT_TOKEN("R_CURLY_BRACKET"); }
"["                     {n_colunas+=yyleng; PRINT_TOKEN("L_SQUARE_BRACKET"); }
"]"                     {n_colunas+=yyleng; PRINT_TOKEN("R_SQUARE_BRACKET"); }
"?"                     {n_colunas+=yyleng; PRINT_TOKEN("TERNARY_CONDITIONAL"); }
"#"                     {n_colunas+=yyleng; PRINT_TOKEN("NUMBER_SIGN"); }
"->"                    {n_colunas+=yyleng; PRINT_TOKEN("POINTER"); }
"printf"                {n_colunas+=yyleng; PRINT_TOKEN("PRINTF"); }
"scanf"                 {n_colunas+=yyleng; PRINT_TOKEN("SCANF"); }
"define"                {n_colunas+=yyleng; PRINT_TOKEN("DEFINE"); }
"exit"                  {n_colunas+=yyleng; PRINT_TOKEN("EXIT"); }

\"(\\.|[^"\\])*\"	        {n_colunas+=yyleng;PRINT_TOKEN_WITH_TEXT_CHAR("STRING"); }
'([^'\\\n]|\\.)'            {n_colunas+=yyleng;PRINT_TOKEN_WITH_TEXT_CHAR("CHARACTER"); }

[a-zA-Z_][a-zA-Z0-9_]*  { if (yyleng > 255){PRINT_ERROR_ID;} else{PRINT_TOKEN_WITH_TEXT("IDENTIFIER");}}
.                       {n_colunas+=yyleng; PRINT_ERROR;}
}

<BLOCO_COMENTADO>{
    
"/"*"*/"                {BEGIN(INITIAL); n_colunas += yyleng;}
"/*"                    {PRINT_COMMENT_WARNING; n_colunas +=2;}

"\n"                    {n_colunas = 1; n_linhas++;}

<<EOF>>                 {PRINT_COMMENT_BLOCK_ERROR; return 0;}

.                       {n_colunas++;}

}

<LINHA_COMENTADA>{

"\n"                    {n_colunas = 1; BEGIN(INITIAL);}

.                       {n_colunas++;}

}

%%

int main() {
    yylex();
    return 0;
}
