/* Nao usar a biblioteca do flex*/
%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <string.h>
#include "sintatico.yy.hh"
#include "defines.hpp"

int n_linhas = 1;
int n_colunas = 1;
int cmsl=0;  //linha do começo do comentario em bloco
int cmsc=0; //coluna do começo do comentario em bloco
int flag = 1; //flag para nao printar enter na primeira leitura

#define PRINT_ERROR {printf("\nInvalid Symbol: %s", yytext);}
std::string saver;

%}

%%

" " {}
"\n" {return EOL;}
"+" {saver=saver+yytext;return PLUS;}
"-" {saver=saver+yytext;return MINUS;}
"*" {saver=saver+yytext;return MUL;}
"/" {saver=saver+yytext;return DIV;}
"^" {saver=saver+yytext;return POW;}
"%" {saver=saver+yytext;return PORCENT;}
"(" {saver=saver+yytext;return LPAREN;}
")" {saver=saver+yytext;return RPAREN;}
":" {saver=saver+yytext;return COLON;}
"=" {saver=saver+yytext;return EQUALS;}
":=" {saver=saver+yytext;return ASSIGN;}
"," {saver=saver+yytext;return COMMA;}
";" {saver=saver+yytext;return SEMICOLON;}
"[" {saver=saver+yytext;return LBRACKET;}
"]" {saver=saver+yytext;return RBRACKET;}

"sen" {saver=saver+yytext; return SEN;}
"cos" {saver=saver+yytext; return COS;}
"tan" {saver=saver+yytext; return TAN;}
"abs" {saver=saver+yytext; return ABS;}
"pi|Pi|PI|pI" {saver=saver+yytext; return PI;}
"e|E" {saver=saver+yytext; return E;}

"about" {saver=saver+yytext; return ABOUT;}
"float" {saver=saver+yytext; return FLOAT;}
"settings" {saver=saver+yytext; return SETTINGS;}
"h" {saver=saver+yytext; return H;}
"view" {saver=saver+yytext; return VIEW;}
"plot" {saver=saver+yytext; return PLOT;}
"show" {saver=saver+yytext; return SHOW;}
"axis" {saver=saver+yytext; return AXIS;}
"integral" {saver=saver+yytext; return INTEGRAL;}
"integral_steps" {saver=saver+yytext; return INTEGRAL_STEPS;}
"steps" {saver=saver+yytext; return STEPS;}
"precision" {saver=saver+yytext; return PRECISION;}
"solve" {saver=saver+yytext; return SOLVE;}
"connect" {saver=saver+yytext; return CONNECT;}
"dots" {saver=saver+yytext; return DOTS;}
"integrate" {saver=saver+yytext; return INTEGRATE;}
"quit" {saver=saver+yytext; return QUIT;}
"sum" {saver=saver+yytext; return SUM;}
"linear" {saver=saver+yytext; return LINEAR;}
"system" {saver=saver+yytext; return SYSTEM;}
"linear_system" {saver=saver+yytext; return LINEAR_SYSTEM;}
"reset" {saver=saver+yytext; return RESET;}
"symbols" {saver=saver+yytext; return SYMBOLS;}
"determinant" {saver=saver+yytext; return DETERMINANT;}
"matrix" {saver=saver+yytext; return MATRIX;}
"rpn" {saver=saver+yytext; return RPN;}
"e" {saver=saver+yytext; return E;}
"off" {saver=saver+yytext; return OFF;}
"v" {saver=saver+yytext; return V;}
"erase" {saver=saver+yytext; return ERASE;}
"on" {saver=saver+yytext; return ON;}
"set" {saver=saver+yytext; return SET;}
"x" {saver=saver+yytext; return X;}
"h_view" {saver=saver+yytext; return H_VIEW;}
"v_view" {saver=saver+yytext; return V_VIEW;}

[-+]?[0-9]+ {saver=saver+yytext; return NUM_INT;}
[-+]?[0-9]+"."[0-9]+ {saver=saver+yytext; return NUM_REAL;}
[a-zA-Z]+[0-9a-zA-Z]* {saver=saver+yytext; return IDENTIFIER;} 

<<EOF>>                 {return EOFF;}
.                       {PRINT_ERROR;}


 