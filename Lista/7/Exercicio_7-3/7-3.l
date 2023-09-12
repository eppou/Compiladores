%option noyywrap

%{
#include <stdio.h>

// Declaração das funções que representam as ações
void action1();
void action2();
void action3();
%}

%%

(aba)+   { action1(); }
(a(b*)a) { action2(); }
(a|b)   { action3(); }

%%

int main() {
    yylex();
    return 0;
}

// Implementação das ações
void action1() {
    printf("(action 1)\n");
}

void action2() {
    printf("(action 2)\n");
}

void action3() {
    printf("(action 3)\n");
}