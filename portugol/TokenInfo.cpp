#include <iostream>

#include "TokenInfo.hpp"

static const char *nomes_token[59]{
	"NULO",
	"ID",
	"NUM_INTEIRO",
	"NUM_REAL",
	"PONTO",
	"E",
	"ATE",
	"OU",
	"ALGORITMO",
	"PARA",
	"PASSO",
	"PROCEDIMENTO",
	"CARACTERE",
	"REAL",
	"REPITA",
	"DE",
	"DIV",
	"BARRA",
	"SE",
	"SENAO",
	"VARIAVEIS",
	"VERDADEIRO",
	"TIPO",
	"NAO",
	"MATRIZ",
	"FALSO",
	"FACA",
	"FIM",
	"FUNCAO",
	"ENTAO",
	"ENQUANTO",
	"LEIA",
	"LOGICO",
	"IMPRIMA",
	"INTEIRO",
	"MAIOR",
	"MENOR",
	"MAIS",
	"SUB",
	"MUL",
	"MAIOR_IGUAL",
	"MENOR_IGUAL",
	"STRING",
	"BLOCK_COMMENT",
	"LINE_COMMENT",
	"WHITESPACE",
	"DIFERENTE",
	"ATRIBUICAO",
	"IGUAL",
	"PONTO_VIRG",
	"DOIS_PONTOS",
	"INICIO",
	"VIRG",
	"ABRE_COL",
	"FECHA_COL",
	"ABRE_PAR",
	"FECHA_PAR",
	"VETOR",
	"FIM_DE_ARQUIVO"
};

TokenInfo::TokenInfo(std::string &content, tipos_token type, size_t line,size_t column)
{
	this->content.assign(content);
	this->type_T = type;
	this->line = line;
	this->column = column;
}

TokenInfo::TokenInfo(tipos_token tok, size_t line, size_t column)
{
	this->content.clear();
	this->type_T = tok;
	this->line = line;
	this->column = column;
}

void TokenInfo::print(bool print_whitespaces)
{
	if (type_T == WHITESPACE)
	{
		if (print_whitespaces)
			std::cout << nomes_token[type_T];
	}
	else
	{
		std::cout << nomes_token[type_T];

		if (type_T == ID || type_T == NUM_INTEIRO || type_T == NUM_REAL || type_T == STRING)
		{
			std::cout << '(' << content << ')';
		}

		std::cout << ':' << line << ':' << column << std::endl;
	}
}

// getters
tipos_token TokenInfo::get_type()
{
	return type_T;
}

std::string TokenInfo::get_content()
{
	return content;
}

size_t TokenInfo::get_line()
{
	return line;
}

size_t TokenInfo::get_column()
{
	return column;
}
// setters
void TokenInfo::set_tok(tipos_token tt)
{
	this->type_T = tt;
}

void TokenInfo::set_content(std::string &content)
{
	this->content.assign(content);
}

void TokenInfo::set_line(size_t line)
{
	this->line = line;
}

void TokenInfo::set_column(size_t column)
{
	this->column = column;
}