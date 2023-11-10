#ifndef PARSER_HPP
#define PARSER_HPP

#include "libs.hpp"
#include "TokenInfo.hpp"

class parser
{
public:

	//CONSTRUTOR INICIALIZA COM O SIMBOLO INICIAL DA GRAMATICA
	parser() { symbols.push(&parser::S); };
	

	void parse(TokenInfo &fatorando);
	//FIM DA ANALISA SINTATICA E CONSEQUENTEMENTE DO PROGRAMA
	bool fim();

private:

	//PILHA E VETOR PARA AUXILIAR A ANALISE SINTATICA
	std::stack<tipos_token (parser::*)(TokenInfo &)> symbols;
	std::vector<TokenInfo>::iterator cursor;

	//EM CASO DE ERRO SINTATICO IMPRIME A MENSAGEM DE ERRO
	void imprime_erro(TokenInfo &fatorando);

	//FUNCOES DA GRAMATICA
	tipos_token S(TokenInfo &fatorando);
	tipos_token	num_real(TokenInfo &fatorando);
	tipos_token	ponto(TokenInfo &fatorando);
	tipos_token	e(TokenInfo &fatorando);
	tipos_token	ate(TokenInfo &fatorando);
	tipos_token	ou(TokenInfo &fatorando);
	tipos_token	algoritmo(TokenInfo &fatorando);
	tipos_token	para(TokenInfo &fatorando);
	tipos_token	passo(TokenInfo &fatorando);
	tipos_token	procedimento(TokenInfo &fatorando);
	tipos_token	caractere(TokenInfo &fatorando);
	tipos_token	real(TokenInfo &fatorando);
	tipos_token	repita(TokenInfo &fatorando);
	tipos_token	de(TokenInfo &fatorando);
	tipos_token	div(TokenInfo &fatorando);
	tipos_token	barra(TokenInfo &fatorando);
	tipos_token	se(TokenInfo &fatorando);
	tipos_token	senao(TokenInfo &fatorando);
	tipos_token	variaveis(TokenInfo &fatorando);
	tipos_token	verdadeiro(TokenInfo &fatorando);
	tipos_token	tipo(TokenInfo &fatorando);
	tipos_token	nao(TokenInfo &fatorando);
	tipos_token	matriz(TokenInfo &fatorando);
	tipos_token	falso(TokenInfo &fatorando);
	tipos_token	faca(TokenInfo &fatorando);
	tipos_token	fim(TokenInfo &fatorando);
	tipos_token	funcao(TokenInfo &fatorando);
	tipos_token	entao(TokenInfo &fatorando);
	tipos_token	enquanto(TokenInfo &fatorando);
	tipos_token	leia(TokenInfo &fatorando);
	tipos_token	logico(TokenInfo &fatorando);
	tipos_token	imprima(TokenInfo &fatorando);
	tipos_token	inteiro(TokenInfo &fatorando);
	tipos_token	maior(TokenInfo &fatorando);
	tipos_token	menor(TokenInfo &fatorando);
	tipos_token	mais(TokenInfo &fatorando);
	tipos_token	sub(TokenInfo &fatorando);
	tipos_token	mul(TokenInfo &fatorando);
	tipos_token	maior_igual(TokenInfo &fatorando);
	tipos_token	menor_igual(TokenInfo &fatorando);
	tipos_token	string(TokenInfo &fatorando);
	tipos_token	block_comment(TokenInfo &fatorando);
	tipos_token	line_comment(TokenInfo &fatorando);
	tipos_token	whitespace(TokenInfo &fatorando);
	tipos_token	diferente(TokenInfo &fatorando);
	tipos_token	atribuicao(TokenInfo &fatorando);
	tipos_token	igual(TokenInfo &fatorando);
	tipos_token	ponto_virg(TokenInfo &fatorando);
	tipos_token	dois_pontos(TokenInfo &fatorando);
	tipos_token	inicio(TokenInfo &fatorando);
	tipos_token	virg(TokenInfo &fatorando);
	tipos_token	abre_col(TokenInfo &fatorando);
	tipos_token	fecha_col(TokenInfo &fatorando);
	tipos_token	abre_par(TokenInfo &fatorando);
	tipos_token	fecha_par(TokenInfo &fatorando);
	tipos_token	vetor(TokenInfo &fatorando);
	tipos_token	eof_tok(TokenInfo &fatorando);
	tipos_token	Programa(TokenInfo &fatorando);
	tipos_token	ProcedimentoFuncao(TokenInfo &fatorando);
	tipos_token	DeclaraProcedimento(TokenInfo &fatorando);
	tipos_token	DeclaraFuncao(TokenInfo &fatorando);
	tipos_token	Parametros(TokenInfo &fatorando);
	tipos_token	DeclaraParametros(TokenInfo &fatorando);
	tipos_token	BlocoVariaveis(TokenInfo &fatorando);
	tipos_token	Declaracoes_prime(TokenInfo &fatorando);
	tipos_token	Declaracoes(TokenInfo &fatorando);
	tipos_token	DeclaraTipo(TokenInfo &fatorando);
	tipos_token	DeclaraVariaveis(TokenInfo &fatorando);
	tipos_token	DeclaraIdentificador(TokenInfo &fatorando);
	tipos_token	DeclaraIdentificador_prime(TokenInfo &fatorando);
	tipos_token	VetorMatriz(TokenInfo &fatorando);
	tipos_token	Dimensao_prime(TokenInfo &fatorando);
	tipos_token	Dimensao(TokenInfo &fatorando);
	tipos_token	TipoBasico(TokenInfo &fatorando);
	tipos_token	BlocoComandos(TokenInfo &fatorando);
	tipos_token	BlocoComandos_prime(TokenInfo &fatorando);
	tipos_token	ListaComandos_prime(TokenInfo &fatorando);
	tipos_token	ListaComandos(TokenInfo &fatorando);
	tipos_token	Comandos_prime(TokenInfo &fatorando);
	tipos_token	ComandosAux(TokenInfo &fatorando);
	tipos_token	Comandos(TokenInfo &fatorando);
	tipos_token	ComandosFimSeSenao(TokenInfo &fatorando);
	tipos_token	ComandosParaPasso(TokenInfo &fatorando);
	tipos_token	Expressao(TokenInfo &fatorando);
	tipos_token	Expressao_prime(TokenInfo &fatorando);
	tipos_token	ExpressaoSimples(TokenInfo &fatorando);
	tipos_token	ExpressaoSimples_prime(TokenInfo &fatorando);
	tipos_token	Termo(TokenInfo &fatorando);
	tipos_token	Termo_prime(TokenInfo &fatorando);
	tipos_token	Fator(TokenInfo &fatorando);
	tipos_token	FatorAux(TokenInfo &fatorando);
	tipos_token	Variavel_prime(TokenInfo &fatorando);
	tipos_token	Variavel(TokenInfo &fatorando);
	tipos_token	ExprIter_prime(TokenInfo &fatorando);
	tipos_token	ExprIter(TokenInfo &fatorando);
	tipos_token	id(TokenInfo &fatorando);
	tipos_token	num_inteiro(TokenInfo &fatorando);
	
};

#endif