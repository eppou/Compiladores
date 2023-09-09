/* ALUNO:   MARCOS VINICIUS PRETTI DIAS
 * Nº:      202100560401
 */

#include "lexer.hpp"
#include "libs.hpp"

int main(){

    lexer analise_lexica;
    std::string str;
    char ch = 0;
    while((ch = getc(stdin))){

        str.append(1, ch);

        if(ch == EOF){
            break;
        }
    }

    analise_lexica.returnToken(str);
}