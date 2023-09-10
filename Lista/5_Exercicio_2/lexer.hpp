#ifndef LEXEP_HPP
#define LEXEP_HPP

#include <string>
#include "transitions.hpp"
#include "states.hpp"

class lexer{

    public:
        void returnToken(std::string str);
    
    private:
        bool consume(states &reconhecedor);
        void reset(states &reconhecedor);
};

#endif