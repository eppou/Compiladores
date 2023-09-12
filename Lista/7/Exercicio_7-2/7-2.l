%option noyywrap

%{
    #define PRINT_TEXT_IF {printf("\n%s IF",yytext);}
    #define PRINT_TEXT_ID {printf("\n%s ID",yytext);}
    #define PRINT_TEXT_NUM {printf("\n%s NUM",yytext);}
    #define PRINT_TEXT_REAL {printf("\n%s REAL",yytext);}
    #define PRINT_TEXT_COMMENT {printf("\n%s comment",yytext);}
    #define PRINT_TEXT_WHITESPACE {printf("\nwhite space");}
    #define ERRO_TEXT {printf("\n%s error", yytext);}
%}

%%

"if"                         { PRINT_TEXT_IF } 
"--"[a-z]+                   { PRINT_TEXT_COMMENT}
"\n"
"\r"
" "*                        { PRINT_TEXT_WHITESPACE}  
[a-z][a-z0-9]*              { PRINT_TEXT_ID } 
[0-9]*"."[0-9]+             { PRINT_TEXT_REAL} 
[0-9]+                      { PRINT_TEXT_NUM } 
.                           { ERRO_TEXT }

%%

int main(int argc, char** argv){

    yylex();

    return 0;
}

