%{
    #include <stdio.h>
    
    extern int yylex();
    extern char* yytext;
    extern int yychar;
	extern int last_line;
	extern char buffer[1024];
	extern int n_linhas;
	extern int n_colunas;
    void yyerror(void *s);
%}


%token VOID
%token INT
%token CHAR
%token RETURN
%token BREAK
%token SWITCH
%token CASE
%token DEFAULT
%token DO
%token WHILE
%token FOR
%token IF
%token ELSE
%token TYPEDEF
%token STRUCT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token INC
%token DEC
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token BITWISE_XOR
%token NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token LESS_EQUAL
%token GREATER_EQUAL
%token R_SHIFT
%token L_SHIFT
%token ASSIGN
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token L_PAREN
%token R_PAREN
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token TERNARY_CONDITIONAL
%token NUMBER_SIGN
%token POINTER
%token PRINTF
%token SCANF
%token DEFINE
%token EXIT
%token IDENTIFIER
%token NUM_OCTAL
%token NUM_INTEGER
%token NUM_HEXA
%token STRING
%token CHARACTER

%start S

%%
S
    : FuncDec LoopFuncDec {};

FuncDec 
    : Declarations {}
    | Func {};

LoopFuncDec 
    : FuncDec LoopFuncDec {}
    | {};

Declarations 
    : NUMBER_SIGN DEFINE IDENTIFIER Expression {}
    | DeclareVar {}
    | DeclarePrototype {};

Func 
    : Tipo LoopPointers IDENTIFIER Parameters L_CURLY_BRACKET LoopFuncDEC Commands R_CURLY_BRACKET {};

LoopPointers 
    : MULTIPLY LoopPointers {}
    | {};

LoopFuncDEC 
    : DeclareVar LoopFuncDEC {}
    | {};

DeclareVar 
    : Tipo LoopDeclareVar SEMICOLON {};

LoopDeclareVar 
    : LoopPointers IDENTIFIER LoopExpression AssignsValue AnotheDec {};

AssignsValue
    : ASSIGN ExpressionAtribuicao {}
	| {};

AnotheDec
    : COMMA LoopDeclareVar {}
	| {};

LoopExpression 
    : L_SQUARE_BRACKET Expression R_SQUARE_BRACKET LoopExpression {}
    | {};

DeclarePrototype
    : Tipo LoopPointers IDENTIFIER Parameters SEMICOLON {};

Parameters
    : L_PAREN LoopParameters R_PAREN {};

LoopParameters 
    : Tipo LoopPointers IDENTIFIER LoopExpression AnotherParameters {}
    | {};

AnotherParameters
    : COMMA LoopParameters {}
    | {};

Tipo 
    : INT {}
    | CHAR {}
    | VOID {};

Minecraft 
    : L_CURLY_BRACKET Commands R_CURLY_BRACKET {};

Commands
    : CommandsList LoopListCommands{};

LoopListCommands
    : CommandsList LoopListCommands{}
    | {};


CommandsList
    : DO Minecraft WHILE L_PAREN Expression R_PAREN SEMICOLON {}
    | IF L_PAREN Expression R_PAREN Minecraft Advance1 {}
    | WHILE L_PAREN Expression R_PAREN Minecraft {}
    | FOR L_PAREN Advance2 SEMICOLON Advance2 SEMICOLON Advance2 R_PAREN Minecraft {}
    | PRINTF L_PAREN STRING AnotherEXP R_PAREN SEMICOLON {}
    | SCANF L_PAREN STRING COMMA BITWISE_AND R_PAREN SEMICOLON {}
    | EXIT L_PAREN Expression R_PAREN SEMICOLON {}
    | RETURN Advance2 SEMICOLON {}
    | Expression SEMICOLON {}
    | SEMICOLON {}
    | Minecraft {};

Advance1
    : ELSE Minecraft {}
    | {};

Advance2
    : Expression {}
    | {};

AnotherEXP 
    : COMMA Expression {}
    | {};

Expression 
    : ExpressionAtribuicao {}
    | Expression COMMA ExpressionAtribuicao {};

ExpressionAtribuicao 
    : ExpressionCondicional {}
    | ExpressionUN Signs ExpressionAtribuicao {}

Signs
    : ASSIGN {}
    | ADD_ASSIGN {}
    | MINUS_ASSIGN {};

ExpressionCondicional
    : ExpressionOrLogico Ternary_option {};

Ternary_option 
    : TERNARY_CONDITIONAL Expression COLON ExpressionCondicional {}
    | {};

ExpressionOrLogico 
    : ExpressionAndLogico {}
    | ExpressionOrLogico LOGICAL_OR ExpressionAndLogico {};

ExpressionAndLogico 
    : ExpressionOr {}
    | ExpressionAndLogico LOGICAL_AND ExpressionOr {};

ExpressionOr 
    : ExpressionXor {}
    | ExpressionOr BITWISE_OR ExpressionXor {};

ExpressionXor 
    : ExpressionAnd {}
    | ExpressionXor BITWISE_XOR ExpressionAnd {};

ExpressionAnd 
    : ExpressionEqual {}
    | ExpressionAnd BITWISE_AND ExpressionEqual {};

ExpressionEqual 
    : ExpressionRelacional {}
    | ExpressionEqual EQUAL ExpressionRelacional {}
    | ExpressionEqual NOT_EQUAL ExpressionRelacional {};

ExpressionRelacional 
    : ExpressionShift {}
    | ExpressionRelacional LESS_THAN ExpressionShift {}
    | ExpressionRelacional GREATER_THAN ExpressionShift {}
    | ExpressionRelacional LESS_EQUAL ExpressionShift {}
    | ExpressionRelacional GREATER_EQUAL ExpressionShift {};

ExpressionShift 
    : ExpressionADD {}
    | ExpressionShift L_SHIFT ExpressionADD {}
    | ExpressionShift R_SHIFT ExpressionADD {};

ExpressionADD 
    : ExpressionMUL {}
    | ExpressionADD PLUS ExpressionMUL {}
    | ExpressionADD MINUS ExpressionMUL {};

ExpressionMUL 
    : ExpressionCast {}
    | ExpressionMUL MULTIPLY ExpressionCast {}
    | ExpressionMUL DIV ExpressionCast {}
    | ExpressionMUL REMAINDER ExpressionCast {};

ExpressionCast 
    : ExpressionUN {}
    | L_PAREN Tipo LoopPointers R_PAREN ExpressionCast {};

ExpressionUN 
    : ExpressionPOS {}
    | INC ExpressionUN {}
    | DEC ExpressionUN {}
    | BITWISE_AND ExpressionCast {}
    | MULTIPLY ExpressionCast {}
    | PLUS ExpressionCast {}
    | MINUS ExpressionCast {}
    | NOT ExpressionCast {}
    | BITWISE_NOT ExpressionCast {};

ExpressionPOS
    : Primary_Expression {}
    | ExpressionPOS L_SQUARE_BRACKET Expression R_SQUARE_BRACKET {}
    | ExpressionPOS INC {}
    | ExpressionPOS DEC {}
    | ExpressionPOS L_PAREN SET_Value0 R_PAREN {};

SET_Value0
    : ExpressionAtribuicao SET_Value1 {}
    | {};

SET_Value1
    : COMMA ExpressionAtribuicao SET_Value1
    | {};

Primary_Expression 
    : IDENTIFIER  {}
    | Numero {}
    | CHARACTER {}
    | STRING {}
    | L_PAREN Expression R_PAREN {};

Numero 
    : NUM_INTEGER {}
    | NUM_HEXA {}
    | NUM_OCTAL {};

%%

void yyerror(void *s)
{
    SET_buffer(n_linhas);

    if (yychar == 0){
        printf("error:syntax:%d:%d: expected declaration or statement at end of input\n%s\n", n_linhas, n_colunas, buffer);
    } 
    
    else{
	    n_colunas -= strlen(yytext);
        printf("error:syntax:%d:%d: %s\n%s", n_linhas, n_colunas, yytext,buffer );
    }

	for(int i = 0; i < n_colunas-1 ; i++) {
		printf(" "); //Alinha o ^ com o erro
	}
	printf("^");
	exit(0);
}

int main(int argc, char **argv) {
    yyparse();
	printf("SUCCESSFUL COMPILATION.");
    return 0;
}

