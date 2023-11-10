#include <iostream>
#include <string>

#include "parser.hpp"

void parser::imprime_erro(TokenInfo &l)
{
        l.set_column(l.get_column() - l.get_content().length() );
		std::cout << "ERRO DE SINTAXE. Linha: " << l.get_line()<< " Coluna: " << l.get_column() << " -> '" << l.get_content() << '\'';
		exit(1);
}

void parser::parse(TokenInfo &l)
{
    tipos_token expected_type;  // Tipo de token esperado

    while (!symbols.empty())
    {
        // Obtém o próximo símbolo da gramática a ser analisado
        tipos_token (parser::*next_symbol)(TokenInfo &) = symbols.top();
        symbols.pop();

        // Chama a função que representa o próximo símbolo com o token atual
        expected_type = (this->*next_symbol)(l);

        // Se o tipo de token retornado pela função corresponder ao tipo do token atual,
        // a análise está correta, e a função retorna.
        if (expected_type == l.get_type())
            return;
    }
}

bool parser::fim()
{
    return symbols.empty();
}