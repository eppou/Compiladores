#include <queue>
#include <string>
#include <vector>

#include "defs.hpp"
#include "TokenInfo.hpp"

class lexer
{
    public:
        //CONSTRUTOR
        lexer(estado (&state_list)[N_ESTADOS]);
        
        //CRIA E RETORNA SEQUENCIA DE TOKENS E SUAS INFORMAÇOES
        TokenInfo &tokenize(std::istream &src, TokenInfo &l);

        //INICIA A ANALISE LEXICA
        void start_lexing(std::istream &src);

    private:

        //RESETA O ESTADO DO AUTOMATO
        void reset_state(std::istream &src, size_t &line,size_t &column);

        //CONSOME O CARACTERE ATUAL , USEI O MODIFICADOR INLINE PARA MELHORAR A PERFORMANCE
        inline unsigned char consume(int ch);

        //RETORNA ERRO EM CASO DE ERRO LEXICO
        inline void error(char err_ch);

        //ATRIBUI AS TRANSIÇOES E ESTADOS NO COMEÇO DA ANALISE
        void atributeTransitionsAndStates(unsigned char (&matrix)[N_ESTADOS][N_ASCII],estado (&state_list)[N_ESTADOS]);

        std::vector<TokenInfo> tokens;
        std::queue<char> buf;
        unsigned char current,last_final;
        estado states[N_ESTADOS];
        size_t line = 1, column = 1;
};