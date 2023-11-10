#include "parser.hpp"

//---------------------------------------------------------------------------ADAPTAÇÃO DA GRAMATICA PARA O ANALISADOR SINTATICO---------------------------------------------------------------------------//

tipos_token parser::S(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ALGORITMO:
		symbols.push(&parser::eof_tok);
		symbols.push(&parser::Programa);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}


tipos_token parser::ListaComandos(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::ListaComandos_prime);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Comandos);
		break;
	case SE:
		symbols.push(&parser::ListaComandos_prime);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Comandos);
		break;
	case ENQUANTO:
		symbols.push(&parser::ListaComandos_prime);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Comandos);
		break;
	case PARA:
		symbols.push(&parser::ListaComandos_prime);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Comandos);
		break;
	case REPITA:
		symbols.push(&parser::ListaComandos_prime);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Comandos);
		break;
	case LEIA:
		symbols.push(&parser::ListaComandos_prime);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Comandos);
		break;
	case IMPRIMA:
		symbols.push(&parser::ListaComandos_prime);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Comandos);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Comandos_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		break;
	case ABRE_PAR:
		symbols.push(&parser::fecha_par);
		symbols.push(&parser::ExprIter);
		symbols.push(&parser::abre_par);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ComandosAux(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		symbols.push(&parser::Comandos_prime);
		break;
	case ABRE_PAR:
		symbols.push(&parser::Comandos_prime);
		break;
	case ABRE_COL:
		symbols.push(&parser::Expressao);
		symbols.push(&parser::atribuicao);
		symbols.push(&parser::Variavel_prime);
		break;
	case ATRIBUICAO:
		symbols.push(&parser::Expressao);
		symbols.push(&parser::atribuicao);
		symbols.push(&parser::Variavel_prime);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Comandos(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::ComandosAux);
		symbols.push(&parser::id);
		break;
	case SE:
		symbols.push(&parser::ComandosFimSeSenao);
		symbols.push(&parser::ListaComandos);
		symbols.push(&parser::entao);
		symbols.push(&parser::Expressao);
		symbols.push(&parser::se);
		break;
	case ENQUANTO:
		symbols.push(&parser::enquanto);
		symbols.push(&parser::fim);
		symbols.push(&parser::ListaComandos);
		symbols.push(&parser::faca);
		symbols.push(&parser::Expressao);
		symbols.push(&parser::enquanto);
		break;
	case PARA:
		symbols.push(&parser::ComandosParaPasso);
		symbols.push(&parser::Expressao);
		symbols.push(&parser::ate);
		symbols.push(&parser::Expressao);
		symbols.push(&parser::de);
		symbols.push(&parser::id);
		symbols.push(&parser::para);
		break;
	case REPITA:
		symbols.push(&parser::Expressao);
		symbols.push(&parser::ate);
		symbols.push(&parser::ListaComandos);
		symbols.push(&parser::repita);
		break;
	case LEIA:
		symbols.push(&parser::fecha_par);
		symbols.push(&parser::Variavel);
		symbols.push(&parser::abre_par);
		symbols.push(&parser::leia);
		break;
	case IMPRIMA:
		symbols.push(&parser::fecha_par);
		symbols.push(&parser::ExprIter);
		symbols.push(&parser::abre_par);
		symbols.push(&parser::imprima);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ComandosFimSeSenao(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case FIM:
		symbols.push(&parser::se);
		symbols.push(&parser::fim);
		break;
	case SENAO:
		symbols.push(&parser::se);
		symbols.push(&parser::fim);
		symbols.push(&parser::ListaComandos);
		symbols.push(&parser::senao);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ComandosParaPasso(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case FACA:
		symbols.push(&parser::para);
		symbols.push(&parser::fim);
		symbols.push(&parser::ListaComandos);
		symbols.push(&parser::faca);
		break;
	case PASSO:
		symbols.push(&parser::para);
		symbols.push(&parser::fim);
		symbols.push(&parser::ListaComandos);
		symbols.push(&parser::faca);
		symbols.push(&parser::Expressao);
		symbols.push(&parser::passo);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Expressao(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case ABRE_PAR:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case NUM_INTEIRO:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case MAIS:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case SUB:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case NAO:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case NUM_REAL:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case VERDADEIRO:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case FALSO:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	case STRING:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Expressao_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		break;
	case FECHA_PAR:
		break;
	case IGUAL:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		symbols.push(&parser::igual);
		break;
	case FECHA_COL:
		break;
	case VIRG:
		break;
	case ENTAO:
		break;
	case FACA:
		break;
	case PASSO:
		break;
	case ATE:
		break;
	case DIFERENTE:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		symbols.push(&parser::diferente);
		break;
	case MENOR:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		symbols.push(&parser::menor);
		break;
	case MENOR_IGUAL:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		symbols.push(&parser::menor_igual);
		break;
	case MAIOR_IGUAL:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		symbols.push(&parser::maior_igual);
		break;
	case MAIOR:
		symbols.push(&parser::Expressao_prime);
		symbols.push(&parser::ExpressaoSimples);
		symbols.push(&parser::maior);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ExpressaoSimples(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	case ABRE_PAR:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	case NUM_INTEIRO:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	case MAIS:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		symbols.push(&parser::mais);
		break;
	case SUB:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		symbols.push(&parser::sub);
		break;
	case NAO:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	case NUM_REAL:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	case VERDADEIRO:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	case FALSO:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	case STRING:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ExpressaoSimples_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		break;
	case FECHA_PAR:
		break;
	case IGUAL:
		break;
	case FECHA_COL:
		break;
	case VIRG:
		break;
	case ENTAO:
		break;
	case FACA:
		break;
	case PASSO:
		break;
	case ATE:
		break;
	case DIFERENTE:
		break;
	case MENOR:
		break;
	case MENOR_IGUAL:
		break;
	case MAIOR_IGUAL:
		break;
	case MAIOR:
		break;
	case MAIS:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		symbols.push(&parser::mais);
		break;
	case SUB:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		symbols.push(&parser::sub);
		break;
	case OU:
		symbols.push(&parser::ExpressaoSimples_prime);
		symbols.push(&parser::Termo);
		symbols.push(&parser::ou);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Programa(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ALGORITMO:
		symbols.push(&parser::ponto);
		symbols.push(&parser::BlocoComandos);
		symbols.push(&parser::ProcedimentoFuncao);
		symbols.push(&parser::BlocoVariaveis);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::id);
		symbols.push(&parser::algoritmo);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ProcedimentoFuncao(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PROCEDIMENTO:
		symbols.push(&parser::ProcedimentoFuncao);
		symbols.push(&parser::DeclaraProcedimento);
		break;
	case FUNCAO:
		symbols.push(&parser::ProcedimentoFuncao);
		symbols.push(&parser::DeclaraFuncao);
		break;
	case INICIO:
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::DeclaraProcedimento(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PROCEDIMENTO:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::BlocoComandos);
		symbols.push(&parser::BlocoVariaveis);
		symbols.push(&parser::DeclaraParametros);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::Parametros);
		symbols.push(&parser::id);
		symbols.push(&parser::procedimento);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::DeclaraFuncao(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case FUNCAO:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::BlocoComandos);
		symbols.push(&parser::BlocoVariaveis);
		symbols.push(&parser::DeclaraParametros);
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::TipoBasico);
		symbols.push(&parser::dois_pontos);
		symbols.push(&parser::Parametros);
		symbols.push(&parser::id);
		symbols.push(&parser::funcao);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Parametros(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		break;
	case DOIS_PONTOS:
		break;
	case ABRE_PAR:
		symbols.push(&parser::fecha_par);
		symbols.push(&parser::DeclaraIdentificador);
		symbols.push(&parser::abre_par);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::DeclaraParametros(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::Declaracoes);
		break;
	case VARIAVEIS:
		break;
	case TIPO:
		symbols.push(&parser::Declaracoes);
		break;
	case INTEIRO:
		symbols.push(&parser::Declaracoes);
		break;
	case REAL:
		symbols.push(&parser::Declaracoes);
		break;
	case CARACTERE:
		symbols.push(&parser::Declaracoes);
		break;
	case LOGICO:
		symbols.push(&parser::Declaracoes);
		break;
	case INICIO:
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::BlocoVariaveis(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PROCEDIMENTO:
		break;
	case VARIAVEIS:
		symbols.push(&parser::Declaracoes);
		symbols.push(&parser::variaveis);
		break;
	case INICIO:
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Declaracoes_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::Declaracoes);
		break;
	case PROCEDIMENTO:
		break;
	case FUNCAO:
		break;
	case VARIAVEIS:
		break;
	case TIPO:
		symbols.push(&parser::Declaracoes);
		break;
	case INTEIRO:
		symbols.push(&parser::Declaracoes);
		break;
	case REAL:
		symbols.push(&parser::Declaracoes);
		break;
	case CARACTERE:
		symbols.push(&parser::Declaracoes);
		break;
	case LOGICO:
		symbols.push(&parser::Declaracoes);
		break;
	case INICIO:
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Declaracoes(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::Declaracoes_prime);
		symbols.push(&parser::DeclaraVariaveis);
		break;
	case TIPO:
		symbols.push(&parser::Declaracoes_prime);
		symbols.push(&parser::DeclaraTipo);
		break;
	case INTEIRO:
		symbols.push(&parser::Declaracoes_prime);
		symbols.push(&parser::DeclaraVariaveis);
		break;
	case REAL:
		symbols.push(&parser::Declaracoes_prime);
		symbols.push(&parser::DeclaraVariaveis);
		break;
	case CARACTERE:
		symbols.push(&parser::Declaracoes_prime);
		symbols.push(&parser::DeclaraVariaveis);
		break;
	case LOGICO:
		symbols.push(&parser::Declaracoes_prime);
		symbols.push(&parser::DeclaraVariaveis);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::DeclaraTipo(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case TIPO:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::TipoBasico);
		symbols.push(&parser::fecha_col);
		symbols.push(&parser::Dimensao);
		symbols.push(&parser::abre_col);
		symbols.push(&parser::VetorMatriz);
		symbols.push(&parser::igual);
		symbols.push(&parser::id);
		symbols.push(&parser::tipo);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::DeclaraVariaveis(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::DeclaraIdentificador);
		symbols.push(&parser::dois_pontos);
		symbols.push(&parser::TipoBasico);
		break;
	case INTEIRO:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::DeclaraIdentificador);
		symbols.push(&parser::dois_pontos);
		symbols.push(&parser::TipoBasico);
		break;
	case REAL:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::DeclaraIdentificador);
		symbols.push(&parser::dois_pontos);
		symbols.push(&parser::TipoBasico);
		break;
	case CARACTERE:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::DeclaraIdentificador);
		symbols.push(&parser::dois_pontos);
		symbols.push(&parser::TipoBasico);
		break;
	case LOGICO:
		symbols.push(&parser::ponto_virg);
		symbols.push(&parser::DeclaraIdentificador);
		symbols.push(&parser::dois_pontos);
		symbols.push(&parser::TipoBasico);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::DeclaraIdentificador_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		break;
	case FECHA_PAR:
		break;
	case VIRG:
		symbols.push(&parser::DeclaraIdentificador);
		symbols.push(&parser::virg);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::DeclaraIdentificador(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::DeclaraIdentificador_prime);
		symbols.push(&parser::id);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::VetorMatriz(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case VETOR:
		symbols.push(&parser::vetor);
		break;
	case MATRIZ:
		symbols.push(&parser::matriz);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Dimensao_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case FECHA_COL:
		break;
	case VIRG:
		symbols.push(&parser::Dimensao);
		symbols.push(&parser::virg);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Dimensao(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case NUM_INTEIRO:
		symbols.push(&parser::Dimensao_prime);
		symbols.push(&parser::num_inteiro);
		symbols.push(&parser::dois_pontos);
		symbols.push(&parser::num_inteiro);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::TipoBasico(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::id);
		break;
	case INTEIRO:
		symbols.push(&parser::inteiro);
		break;
	case REAL:
		symbols.push(&parser::real);
		break;
	case CARACTERE:
		symbols.push(&parser::caractere);
		break;
	case LOGICO:
		symbols.push(&parser::logico);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::BlocoComandos(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case INICIO:
		symbols.push(&parser::fim);
		symbols.push(&parser::ListaComandos);
		symbols.push(&parser::inicio);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ListaComandos_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::ListaComandos);
		break;
	case FIM:
		break;
	case SE:
		symbols.push(&parser::ListaComandos);
		break;
	case SENAO:
		break;
	case ENQUANTO:
		symbols.push(&parser::ListaComandos);
		break;
	case PARA:
		symbols.push(&parser::ListaComandos);
		break;
	case ATE:
		break;
	case REPITA:
		symbols.push(&parser::ListaComandos);
		break;
	case LEIA:
		symbols.push(&parser::ListaComandos);
		break;
	case IMPRIMA:
		symbols.push(&parser::ListaComandos);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Termo(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	case ABRE_PAR:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	case NUM_INTEIRO:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	case NAO:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	case NUM_REAL:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	case VERDADEIRO:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	case FALSO:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	case STRING:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Termo_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		break;
	case FECHA_PAR:
		break;
	case IGUAL:
		break;
	case FECHA_COL:
		break;
	case VIRG:
		break;
	case ENTAO:
		break;
	case FACA:
		break;
	case PASSO:
		break;
	case ATE:
		break;
	case DIFERENTE:
		break;
	case MAIOR:
		break;
	case MENOR:
		break;
	case MAIOR_IGUAL:
		break;
	case MENOR_IGUAL:
		break;
	case MAIS:
		break;
	case SUB:
		break;
	case OU:
		break;
	case MUL:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		symbols.push(&parser::mul);
		break;
	case DIV:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		symbols.push(&parser::div);
		break;
	case BARRA:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		symbols.push(&parser::barra);
		break;
	case E:
		symbols.push(&parser::Termo_prime);
		symbols.push(&parser::Fator);
		symbols.push(&parser::e);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Fator(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::FatorAux);
		symbols.push(&parser::id);
		break;
	case ABRE_PAR:
		symbols.push(&parser::fecha_par);
		symbols.push(&parser::Expressao);
		symbols.push(&parser::abre_par);
		break;
	case NUM_INTEIRO:
		symbols.push(&parser::num_inteiro);
		break;
	case NAO:
		symbols.push(&parser::Fator);
		symbols.push(&parser::nao);
		break;
	case NUM_REAL:
		symbols.push(&parser::num_real);
		break;
	case VERDADEIRO:
		symbols.push(&parser::verdadeiro);
		break;
	case FALSO:
		symbols.push(&parser::falso);
		break;
	case STRING:
		symbols.push(&parser::string);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Variavel_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		break;
	case FECHA_PAR:
		break;
	case IGUAL:
		break;
	case ABRE_COL:
		symbols.push(&parser::fecha_col);
		symbols.push(&parser::ExprIter);
		symbols.push(&parser::abre_col);
		break;
	case FECHA_COL:
		break;
	case VIRG:
		break;
	case ATRIBUICAO:
		break;
	case ENTAO:
		break;
	case FACA:
		break;
	case PASSO:
		break;
	case ATE:
		break;
	case DIFERENTE:
		break;
	case MENOR:
		break;
	case MAIOR:
		break;
	case MENOR_IGUAL:
		break;
	case MAIOR_IGUAL:
		break;
	case MAIS:
		break;
	case SUB:
		break;
	case OU:
		break;
	case MUL:
		break;
	case DIV:
		break;
	case BARRA:
		break;
	case E:
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::Variavel(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::Variavel_prime);
		symbols.push(&parser::id);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ExprIter_prime(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case FECHA_PAR:
		break;
	case FECHA_COL:
		break;
	case VIRG:
		symbols.push(&parser::ExprIter);
		symbols.push(&parser::virg);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::ExprIter(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case ID:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case ABRE_PAR:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case NUM_INTEIRO:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case DIFERENTE:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case MENOR:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case MENOR_IGUAL:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case MAIOR_IGUAL:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case MAIOR:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case MAIS:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case SUB:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case NAO:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case NUM_REAL:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case VERDADEIRO:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case FALSO:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	case STRING:
		symbols.push(&parser::ExprIter_prime);
		symbols.push(&parser::Expressao);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}

tipos_token parser::FatorAux(TokenInfo &fatorando)
{
	switch (fatorando.get_type())
	{
	case PONTO_VIRG:
		symbols.push(&parser::Variavel_prime);
		break;
	case ABRE_PAR:
		symbols.push(&parser::fecha_par);
		symbols.push(&parser::ExprIter);
		symbols.push(&parser::abre_par);
		break;
	case FECHA_PAR:
		symbols.push(&parser::Variavel_prime);
		break;
	case IGUAL:
		symbols.push(&parser::Variavel_prime);
		break;
	case ABRE_COL:
		symbols.push(&parser::Variavel_prime);
		break;
	case FECHA_COL:
		symbols.push(&parser::Variavel_prime);
		break;
	case VIRG:
		symbols.push(&parser::Variavel_prime);
		break;
	case ENTAO:
		symbols.push(&parser::Variavel_prime);
		break;
	case FACA:
		symbols.push(&parser::Variavel_prime);
		break;
	case PASSO:
		symbols.push(&parser::Variavel_prime);
		break;
	case ATE:
		symbols.push(&parser::Variavel_prime);
		break;
	case DIFERENTE:
		symbols.push(&parser::Variavel_prime);
		break;
	case MENOR:
		symbols.push(&parser::Variavel_prime);
		break;
	case MAIOR:
		symbols.push(&parser::Variavel_prime);
		break;
	case MENOR_IGUAL:
		symbols.push(&parser::Variavel_prime);
		break;
	case MAIOR_IGUAL:
		symbols.push(&parser::Variavel_prime);
		break;
	case MAIS:
		symbols.push(&parser::Variavel_prime);
		break;
	case SUB:
		symbols.push(&parser::Variavel_prime);
		break;
	case OU:
		symbols.push(&parser::Variavel_prime);
		break;
	case MUL:
		symbols.push(&parser::Variavel_prime);
		break;
	case BARRA:
		symbols.push(&parser::Variavel_prime);
		break;
	case DIV:
		symbols.push(&parser::Variavel_prime);
		break;
	case E:
		symbols.push(&parser::Variavel_prime);
		break;
	default:
		imprime_erro(fatorando);
		break;
	}
	return NULO;
}


//FIM DAS TRANSIÇOES/SIMBOLOS TERMINAIS
tipos_token parser::id(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ID)
		imprime_erro(fatorando);
	return ID;
}
tipos_token parser::num_inteiro(TokenInfo &fatorando)
{
	if (fatorando.get_type() != NUM_INTEIRO)
		imprime_erro(fatorando);
	return NUM_INTEIRO;
}
tipos_token parser::num_real(TokenInfo &fatorando)
{
	if (fatorando.get_type() != NUM_REAL)
		imprime_erro(fatorando);
	return NUM_REAL;
}
tipos_token parser::ponto(TokenInfo &fatorando)
{
	if (fatorando.get_type() != PONTO)
		imprime_erro(fatorando);
	return PONTO;
}
tipos_token parser::e(TokenInfo &fatorando)
{
	if (fatorando.get_type() != E)
		imprime_erro(fatorando);
	return E;
}
tipos_token parser::ate(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ATE)
		imprime_erro(fatorando);
	return ATE;
}
tipos_token parser::ou(TokenInfo &fatorando)
{
	if (fatorando.get_type() != OU)
		imprime_erro(fatorando);
	return OU;
}
tipos_token parser::algoritmo(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ALGORITMO)
		imprime_erro(fatorando);
	return ALGORITMO;
}
tipos_token parser::para(TokenInfo &fatorando)
{
	if (fatorando.get_type() != PARA)
		imprime_erro(fatorando);
	return PARA;
}
tipos_token parser::passo(TokenInfo &fatorando)
{
	if (fatorando.get_type() != PASSO)
		imprime_erro(fatorando);
	return PASSO;
}
tipos_token parser::procedimento(TokenInfo &fatorando)
{
	if (fatorando.get_type() != PROCEDIMENTO)
		imprime_erro(fatorando);
	return PROCEDIMENTO;
}
tipos_token parser::caractere(TokenInfo &fatorando)
{
	if (fatorando.get_type() != CARACTERE)
		imprime_erro(fatorando);
	return CARACTERE;
}
tipos_token parser::real(TokenInfo &fatorando)
{
	if (fatorando.get_type() != REAL)
		imprime_erro(fatorando);
	return REAL;
}
tipos_token parser::repita(TokenInfo &fatorando)
{
	if (fatorando.get_type() != REPITA)
		imprime_erro(fatorando);
	return REPITA;
}
tipos_token parser::de(TokenInfo &fatorando)
{
	if (fatorando.get_type() != DE)
		imprime_erro(fatorando);
	return DE;
}
tipos_token parser::div(TokenInfo &fatorando)
{
	if (fatorando.get_type() != DIV)
		imprime_erro(fatorando);
	return DIV;
}
tipos_token parser::barra(TokenInfo &fatorando)
{
	if (fatorando.get_type() != BARRA)
		imprime_erro(fatorando);
	return BARRA;
}
tipos_token parser::se(TokenInfo &fatorando)
{
	if (fatorando.get_type() != SE)
		imprime_erro(fatorando);
	return SE;
}
tipos_token parser::senao(TokenInfo &fatorando)
{
	if (fatorando.get_type() != SENAO)
		imprime_erro(fatorando);
	return SENAO;
}
tipos_token parser::variaveis(TokenInfo &fatorando)
{
	if (fatorando.get_type() != VARIAVEIS)
		imprime_erro(fatorando);
	return VARIAVEIS;
}
tipos_token parser::verdadeiro(TokenInfo &fatorando)
{
	if (fatorando.get_type() != VERDADEIRO)
		imprime_erro(fatorando);
	return VERDADEIRO;
}
tipos_token parser::tipo(TokenInfo &fatorando)
{
	if (fatorando.get_type() != TIPO)
		imprime_erro(fatorando);
	return TIPO;
}
tipos_token parser::nao(TokenInfo &fatorando)
{
	if (fatorando.get_type() != NAO)
		imprime_erro(fatorando);
	return NAO;
}
tipos_token parser::matriz(TokenInfo &fatorando)
{
	if (fatorando.get_type() != MATRIZ)
		imprime_erro(fatorando);
	return MATRIZ;
}
tipos_token parser::falso(TokenInfo &fatorando)
{
	if (fatorando.get_type() != FALSO)
		imprime_erro(fatorando);
	return FALSO;
}
tipos_token parser::faca(TokenInfo &fatorando)
{
	if (fatorando.get_type() != FACA)
		imprime_erro(fatorando);
	return FACA;
}
tipos_token parser::fim(TokenInfo &fatorando)
{
	if (fatorando.get_type() != FIM)
		imprime_erro(fatorando);
	return FIM;
}
tipos_token parser::funcao(TokenInfo &fatorando)
{
	if (fatorando.get_type() != FUNCAO)
		imprime_erro(fatorando);
	return FUNCAO;
}
tipos_token parser::entao(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ENTAO)
		imprime_erro(fatorando);
	return ENTAO;
}
tipos_token parser::enquanto(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ENQUANTO)
		imprime_erro(fatorando);
	return ENQUANTO;
}
tipos_token parser::leia(TokenInfo &fatorando)
{
	if (fatorando.get_type() != LEIA)
		imprime_erro(fatorando);
	return LEIA;
}
tipos_token parser::logico(TokenInfo &fatorando)
{
	if (fatorando.get_type() != LOGICO)
		imprime_erro(fatorando);
	return LOGICO;
}
tipos_token parser::imprima(TokenInfo &fatorando)
{
	if (fatorando.get_type() != IMPRIMA)
		imprime_erro(fatorando);
	return IMPRIMA;
}
tipos_token parser::inteiro(TokenInfo &fatorando)
{
	if (fatorando.get_type() != INTEIRO)
		imprime_erro(fatorando);
	return INTEIRO;
}
tipos_token parser::maior(TokenInfo &fatorando)
{
	if (fatorando.get_type() != MAIOR)
		imprime_erro(fatorando);
	return MAIOR;
}
tipos_token parser::menor(TokenInfo &fatorando)
{
	if (fatorando.get_type() != MENOR)
		imprime_erro(fatorando);
	return MENOR;
}
tipos_token parser::mais(TokenInfo &fatorando)
{
	if (fatorando.get_type() != MAIS)
		imprime_erro(fatorando);
	return MAIS;
}
tipos_token parser::sub(TokenInfo &fatorando)
{
	if (fatorando.get_type() != SUB)
		imprime_erro(fatorando);
	return SUB;
}
tipos_token parser::mul(TokenInfo &fatorando)
{
	if (fatorando.get_type() != MUL)
		imprime_erro(fatorando);
	return MUL;
}
tipos_token parser::maior_igual(TokenInfo &fatorando)
{
	if (fatorando.get_type() != MAIOR_IGUAL)
		imprime_erro(fatorando);
	return MAIOR_IGUAL;
}
tipos_token parser::menor_igual(TokenInfo &fatorando)
{
	if (fatorando.get_type() != MENOR_IGUAL)
		imprime_erro(fatorando);
	return MENOR_IGUAL;
}
tipos_token parser::string(TokenInfo &fatorando)
{
	if (fatorando.get_type() != STRING)
		imprime_erro(fatorando);
	return STRING;
}
tipos_token parser::block_comment(TokenInfo &fatorando)
{
	if (fatorando.get_type() != BLOCK_COMMENT)
		imprime_erro(fatorando);
	return BLOCK_COMMENT;
}
tipos_token parser::line_comment(TokenInfo &fatorando)
{
	if (fatorando.get_type() != LINE_COMMENT)
		imprime_erro(fatorando);
	return LINE_COMMENT;
}
tipos_token parser::whitespace(TokenInfo &fatorando)
{
	if (fatorando.get_type() != WHITESPACE)
		imprime_erro(fatorando);
	return WHITESPACE;
}
tipos_token parser::diferente(TokenInfo &fatorando)
{
	if (fatorando.get_type() != DIFERENTE)
		imprime_erro(fatorando);
	return DIFERENTE;
}
tipos_token parser::atribuicao(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ATRIBUICAO)
		imprime_erro(fatorando);
	return ATRIBUICAO;
}
tipos_token parser::igual(TokenInfo &fatorando)
{
	if (fatorando.get_type() != IGUAL)
		imprime_erro(fatorando);
	return IGUAL;
}
tipos_token parser::ponto_virg(TokenInfo &fatorando)
{
	if (fatorando.get_type() != PONTO_VIRG)
		imprime_erro(fatorando);
	return PONTO_VIRG;
}
tipos_token parser::dois_pontos(TokenInfo &fatorando)
{
	if (fatorando.get_type() != DOIS_PONTOS)
		imprime_erro(fatorando);
	return DOIS_PONTOS;
}
tipos_token parser::inicio(TokenInfo &fatorando)
{
	if (fatorando.get_type() != INICIO)
		imprime_erro(fatorando);
	return INICIO;
}
tipos_token parser::virg(TokenInfo &fatorando)
{
	if (fatorando.get_type() != VIRG)
		imprime_erro(fatorando);
	return VIRG;
}
tipos_token parser::abre_col(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ABRE_COL)
		imprime_erro(fatorando);
	return ABRE_COL;
}
tipos_token parser::fecha_col(TokenInfo &fatorando)
{
	if (fatorando.get_type() != FECHA_COL)
		imprime_erro(fatorando);
	return FECHA_COL;
}
tipos_token parser::abre_par(TokenInfo &fatorando)
{
	if (fatorando.get_type() != ABRE_PAR)
		imprime_erro(fatorando);
	return ABRE_PAR;
}
tipos_token parser::fecha_par(TokenInfo &fatorando)
{
	if (fatorando.get_type() != FECHA_PAR)
		imprime_erro(fatorando);
	return FECHA_PAR;
}
tipos_token parser::vetor(TokenInfo &fatorando)
{
	if (fatorando.get_type() != VETOR)
		imprime_erro(fatorando);
	return VETOR;
}
tipos_token parser::eof_tok(TokenInfo &fatorando)
{
	if (fatorando.get_type() != EOF_TOK)
		imprime_erro(fatorando);
	return EOF_TOK;
}