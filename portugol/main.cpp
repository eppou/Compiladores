/*
    NOME: Marcos V. Pretti Dias
    Matricula: 202100560401
*/

#include "main_includes.hpp"

int main()
{
    //INSTANCIA O ANALISADOR SINTATICO
    parser sintatico = parser();

    //INSTANCIA AS INFORMAÇOES A RESPEITO DO TOKEN
    TokenInfo cabecalho;

    //INSTANCIA O ANALISADOR LEXICO
    lexer lexico = lexer(states);


    //ENQUANTO NAO TERMINAR DE ANALISAR A ENTRADA CONTINUA ANALISANDO
    while (!sintatico.fim())
    {
        sintatico.parse(lexico.tokenize(std::cin, cabecalho));
    }

    //SE PASSOU POR TODOS OS TESTES E NAO HOUVE ERROS DE SINTAXE OU LEXICO O PROGRAMA ESTA CORRETO
    std::cout << "PROGRAMA CORRETO.";

    return 0;
}