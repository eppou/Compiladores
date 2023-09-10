#include "lexer.hpp"
#include <iostream>

void lexer::returnToken(std::string str){
    std::cout << "\n";
    std:: string::iterator it = str.begin();
    std:: string::iterator it_buffer = it;
    std::string token;
    states reconhecedor;
    reconhecedor.entrada_atual = *it;
    reconhecedor.atual_estado = 0;
    reconhecedor.ultimo_final = -1;

    while (true){
        if(consume(reconhecedor)){
            ++it;
            reconhecedor.entrada_atual = *it;
        }
        else{
            if(reconhecedor.ultimo_final == -1){
                token.assign("ERRO");
                ++it;
                reconhecedor.entrada_atual = *it;
                it_buffer = it;
                std::cout << token;
                std::cout << "\n";
            }
            else{
                token.assign(it_buffer, it);
                it_buffer = it;
                std::cout << token;
                std::cout << "\n";
                if(*it == '\n'){
                    it++;
                    it_buffer = it;
                    reconhecedor.entrada_atual = *it;
                }
            }

            if(*it == EOF){
                break;
            }
            reset(reconhecedor);
        }
    }
}

bool lexer::consume(states &rcd){
    char c = rcd.entrada_atual;

    rcd.atual_estado = edges[rcd.atual_estado][(int)c]; 
        if(rcd.atual_estado == -1){
            return false;
        }
        else if(final_states[rcd.atual_estado] == true){
            rcd.ultimo_final = rcd.atual_estado;
        }
    return true;
     
}

void lexer::reset(states &reconhecedor){
    reconhecedor.atual_estado = 0;
    reconhecedor.ultimo_final = -1;
}