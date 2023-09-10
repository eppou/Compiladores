#ifndef TRANSITIONS_HPP
#define TRANSITIONS_HPP 1
#include <string>

extern bool final_states[22];
extern int edges[22][128];
extern std::string tokens[22];

void treatToken(std::string &token, int last_final, std::string::iterator &it_buffer, std::string::iterator &it);

#endif