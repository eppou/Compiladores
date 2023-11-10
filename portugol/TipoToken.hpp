#ifndef TIPO_TOKEN_HPP
#define TIPO_TOKEN_HPP

// ENUM PARA DEFINIR OS TIPOS POSSIVEIS DA TOKEM

typedef enum tokens
{
	NULO,
	ID,
	NUM_INTEIRO,
	NUM_REAL,
	PONTO,
	E,
	ATE,
	OU,
	ALGORITMO,
	PARA,
	PASSO,
	PROCEDIMENTO,
	CARACTERE,
	REAL,
	REPITA,
	DE,
	DIV,
	BARRA,
	SE,
	SENAO,
	VARIAVEIS,
	VERDADEIRO,
	TIPO,
	NAO,
	MATRIZ,
	FALSO,
	FACA,
	FIM,
	FUNCAO,
	ENTAO,
	ENQUANTO,
	LEIA,
	LOGICO,
	IMPRIMA,
	INTEIRO,
	MAIOR,
	MENOR,
	MAIS,
	SUB,
	MUL,
	MAIOR_IGUAL,
	MENOR_IGUAL,
	STRING,
	BLOCK_COMMENT,
	LINE_COMMENT,
	WHITESPACE,
	DIFERENTE,
	ATRIBUICAO,
	IGUAL,
	PONTO_VIRG,
	DOIS_PONTOS,
	INICIO,
	VIRG,
	ABRE_COL,
	FECHA_COL,
	ABRE_PAR,
	FECHA_PAR,
	VETOR,
	EOF_TOK
} tipos_token;

#endif