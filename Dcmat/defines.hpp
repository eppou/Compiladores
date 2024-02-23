#ifndef DEFINES_H
#define DEFINES_H

#define ENDL -9998
#define QUITER -9999

//cria um buffer no caso string de C++ para receber a entrada do usuário
#include <iostream>
#include <string>
#include <iterator>
extern std::string saver;

extern float h_view_lo;
extern float h_view_hi;
extern float v_view_lo;
extern float v_view_hi;
extern int float_precision;
extern int integral_steps;

extern bool Draw_Axis;
extern bool Erase_Plot;
extern bool Connect_Dots;

#endif // DEFINES_H