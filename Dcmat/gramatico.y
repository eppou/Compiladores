%{
    //libs de c

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    //libs de c++
    #include <iostream>
    #include <unordered_map>
    #include <string>
    #include <vector>

    //libs minhas
    #include "defines.hpp"
    #include "comandos.cpp"
    
    //variaveis usadas nos trabalhos anteriores ou importadas do flex
    extern int yylex();
    extern char* yytext;
    extern int yychar;
	extern int last_line;
	extern int n_linhas;
	extern int n_colunas;
    extern "C" void yyerror(const char* s);

    //variaveis usadas para o dcmat propriamente
    bool ender_flag = false;



    //-----------------------------------------------------CODIGO EM SI-----------------------------------------------------//

    //estrutura de dados para a analise semantica

    std::unordered_map<std::string, id_struct> symbol_table;

    std::string extrairParteAntesDoCaractere(const std::string& str, char caractere) {
        size_t pos = str.find_first_of(caractere);

        if (pos != std::string::npos) {
            return str.substr(0, pos);
        }else{
            // Retorna uma string vazia se o caractere não for encontrado
            return "";
        }
    }
    
%}

%token PLUS
%token MINUS
%token MUL
%token DIV
%token POW
%token PORCENT
%token LPAREN
%token RPAREN
%token COLON
%token EQUALS
%token ASSIGN
%token COMMA
%token SEMICOLON
%token LBRACKET
%token RBRACKET
%token SEN
%token COS
%token TAN
%token ABS
%token PI
%token E
%token ABOUT
%token FLOAT
%token SETTINGS
%token H
%token VIEW
%token PLOT
%token SHOW
%token AXIS
%token INTEGRAL
%token STEPS
%token INTEGRAL_STEPS
%token PRECISION
%token SOLVE
%token CONNECT
%token DOTS
%token INTEGRATE
%token QUIT
%token SUM
%token LINEAR
%token SYSTEM
%token LINEAR_SYSTEM
%token RESET
%token SYMBOLS
%token DETERMINANT
%token MATRIX
%token RPN
%token OFF
%token V
%token ERASE
%token ON
%token SET
%token X
%token H_VIEW
%token V_VIEW
%token NUM_INT
%token NUM_REAL
%token IDENTIFIER
%token EOL
%token EOFF

%start S 

%%
    S
        :command SEMICOLON EOL {return ENDL;}
        |attribution SEMICOLON EOL {return ENDL;}
        |IDENTIFIER SEMICOLON EOL {return ENDL;}
        |SHOW SYMBOLS SEMICOLON EOL {show_symbols(symbol_table);return ENDL;}
        |function EOL {return ENDL;}
        |MINUS function EOL {return ENDL;}
        |EOL {return ENDL;}
        |EOFF {return ENDL;};

    attribution
        : IDENTIFIER ASSIGN NUM_INT {id_struct aux; aux.type = 0; aux.value = atoi(yytext); symbol_table[extrairParteAntesDoCaractere(saver,':')] = aux;}
        | IDENTIFIER ASSIGN NUM_REAL {id_struct aux; aux.type = 1; aux.real_value = atof(yytext); symbol_table[extrairParteAntesDoCaractere(saver,':')] = aux;}
        | IDENTIFIER ASSIGN matrix {id_struct aux; aux.type = 2;aux.matrix = criarMatriz(saver); symbol_table[extrairParteAntesDoCaractere(saver,':')] = aux;};

    command
        :preSettings SETTINGS {}
        |QUIT {return QUITER;}
        |SET posSet {}
        |ABOUT {}
        |plot {}
        |rpn {infixToRPN(saver);}
        |integrate{}
        |sum{}
        |MATRIX EQUALS matrix{}
        |SHOW MATRIX{}
        |solver{};

    solver
        :SOLVE LINEAR_SYSTEM{}
        |SOLVE DETERMINANT{};

    matrix
        : LBRACKET LBRACKET NUM_INT loop_num RBRACKET loop_matrix RBRACKET{};

    loop_num
        :COMMA NUM_INT loop_num{}
        |{};

    loop_matrix
        :COMMA LBRACKET NUM_INT loop_num RBRACKET loop_matrix{}
        |{};

    preSettings
        :SHOW {show_settings();}
        |RESET {reset_settings();};

    posSet
        :H_VIEW num COLON num {set_h_view(saver);}
        |V_VIEW num COLON num {set_v_view(saver);}
        |AXIS ON{set_axis_on();}
        |AXIS OFF{set_axis_off();}
        |ERASE PLOT binary{}
        |INTEGRAL_STEPS num{set_integral_steps(saver);}
        |FLOAT PRECISION NUM_INT{};


    plot
        :PLOT{}
        |PLOT LPAREN function RPAREN{};

    rpn
        :RPN{}
        |RPN LPAREN function RPAREN{};

    integrate
        :INTEGRATE LPAREN num COLON num COMMA function RPAREN{};

    sum
        :SUM LPAREN IDENTIFIER COMMA num COLON num COMMA function RPAREN{};

    function
        :IDENTIFIER{}
        |SEN LPAREN function RPAREN{}
        |COS LPAREN function RPAREN{}
        |TAN LPAREN function RPAREN{}
        |ABS LPAREN function RPAREN{}
        |LPAREN function RPAREN{}
        |function operator function{}
        |NUM_INT{}
        |NUM_REAL{}
        |X{}
        |PI{}
        |E{};

    operator
        :PLUS{}
        |MINUS{}
        |MUL{}
        |DIV{}
        |POW{}
        |PORCENT{};

    num
        :NUM_INT {}
        |NUM_REAL {};

    binary
        :ON {set_erase_on();}
        |OFF {set_erase_off();}

%%


extern "C" void yyerror(const char *s) {
    std::cerr << "SYNTAX ERROR: [ %s ]\n",yytext;
}

int main(int argc, char **argv) {
    int col = 1;
    while(col != QUITER){
        if (col == ENDL || col != QUITER)
            printf(">");
        col = yyparse();
        saver.clear();
    }

}