#ifndef LEXEME_H
#define LEXEME_H

#include <string>

#include "defs.hpp"
#include "TipoToken.hpp"

typedef struct informacao_estado
{
    const char *cc;
    tipos_token tt;
    bool is_final;
}estado;

class TokenInfo
{
public:
	TokenInfo(){};

	//GETTERS AND SETTERS
	std::string get_content();
	tipos_token get_type();
	size_t get_line();
	size_t get_column();
	void set_content(std::string &content);
	void set_tok(tipos_token tok);
	void set_line(size_t line);
	void set_column(size_t column);
	void print(bool print_whitespaces = false);
	
	//INICIA COM CONTEUDO
	TokenInfo(std::string &content, tipos_token tok, size_t line, size_t column);
	//INICIA SEM CONTEUDO
	TokenInfo(tipos_token tok, size_t line, size_t column);
	
private:

	//VARIAVEIS
	std::string content;
	size_t line, column;
	tipos_token type_T;

};

#endif