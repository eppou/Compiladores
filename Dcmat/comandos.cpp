#include "defines.hpp"
#include "comandos.hpp"

float h_view_lo = -6.5;
float h_view_hi = 6.5;
float v_view_lo = -3.5;
float v_view_hi = 3.5;
int float_precision = 6;
int integral_steps = 1000;

bool Draw_Axis = true;
bool Erase_Plot = true;
bool Connect_Dots = false;



//------------------------------------------------SETTINGS------------------------------------------------
void show_settings() {
    std::cout << "\n";
    std::cout << "h_view_lo: " << h_view_lo << std::endl;
    std::cout << "h_view_hi: " << h_view_hi << std::endl;
    std::cout << "v_view_lo: " << v_view_lo << std::endl;
    std::cout << "v_view_hi: " << v_view_hi << std::endl;
    std::cout << "float precision: " << float_precision << std::endl;
    std::cout << "integral_steps: " << integral_steps << std::endl;

    if (Draw_Axis) {
        std::cout << "Draw_Axis: ON" << std::endl;
    } else {
        std::cout << "Draw_Axis: OFF" << std::endl;
    }

    if (Erase_Plot) {
        std::cout << "Erase_Plot: ON" << std::endl;
    } else {
        std::cout << "Erase_Plot: OFF" << std::endl;
    }

    if (Connect_Dots) {
        std::cout << "Connect_Dots: ON" << std::endl;
    } else {
        std::cout << "Connect_Dots: OFF" << std::endl;
    }
    std::cout << "\n";
}

//------------------------------------------------RESET SETTINGS------------------------------------------------
void reset_settings() {
    h_view_lo = -6.5;
    h_view_hi = 6.5;
    v_view_lo = -3.5;
    v_view_hi = 3.5;
    float_precision = 6;
    integral_steps = 1000;
    Draw_Axis = true;
    Erase_Plot = true;
    Connect_Dots = false;
}

//------------------------------------------------SET SETTINGS------------------------------------------------
void set_h_view(std::string &buffer) {

    // Encontrar a posição de "seth_view"
    size_t pos = buffer.find("seth_view");

    if (pos != std::string::npos) {
        // Avançar para a posição após "seth_view"
        pos += 9; // comprimento de "seth_view"

        // Encontrar os dois números após "seth_view"
        size_t colonPos = buffer.find(":", pos);

        if (colonPos != std::string::npos) {
            // Extrair os números como strings
            std::string num1 = buffer.substr(pos, colonPos - pos);
            std::string num2 = buffer.substr(colonPos + 1);

            // Converter as strings para números (opcional)
            h_view_lo = std::stod(num1);
            h_view_hi = std::stod(num2);

            // Agora você pode usar number1 e number2 conforme necessário
            std::cout << "Número 1: " << h_view_lo << std::endl;
            std::cout << "Número 2: " << h_view_hi << std::endl;
        } else {
            std::cout << "Dois números não encontrados após seth_view" << std::endl;
        }
    } else {
        std::cout << "Substring 'seth_view' não encontrada na string" << std::endl;
    }
}

void set_v_view(std::string &buffer) {

    // Encontrar a posição de "seth_view"
    size_t pos = buffer.find("setv_view");

    if (pos != std::string::npos) {
        // Avançar para a posição após "seth_view"
        pos += 9; // comprimento de "seth_view"

        // Encontrar os dois números após "seth_view"
        size_t colonPos = buffer.find(":", pos);

        if (colonPos != std::string::npos) {
            // Extrair os números como strings
            std::string num1 = buffer.substr(pos, colonPos - pos);
            std::string num2 = buffer.substr(colonPos + 1);

            // Converter as strings para números (opcional)
            v_view_lo = std::stod(num1);
            v_view_hi = std::stod(num2);

            // Agora você pode usar number1 e number2 conforme necessário
            std::cout << "Número 1: " << v_view_lo << std::endl;
            std::cout << "Número 2: " << v_view_hi << std::endl;
        } else {
            std::cout << "Dois números não encontrados após seth_view" << std::endl;
        }
    } else {
        std::cout << "Substring 'seth_view' não encontrada na string" << std::endl;
    }

}

void set_axis_on() {
    Draw_Axis = true;
}

void set_axis_off() {
    Draw_Axis = false;
}

void set_erase_on() {
    Erase_Plot = true;
}

void set_erase_off() {
    Erase_Plot = false;
}

void set_integral_steps(std::string &buffer) {
    // Encontrar a posição de "seth_view"
    size_t pos = buffer.find("setintegral_steps");

    if (pos != std::string::npos) {
        // Avançar para a posição após "seth_view"
        pos += 17; // comprimento de "seth_view"

        // Extrair o número como string
        std::string num = buffer.substr(pos);
        std::cout << "Número: " << buffer << std::endl;
        // Converter a string para número (opcional)
        integral_steps = std::stoi(num);

    }
}
//------------------------------------------------PLOT's------------------------------------------------

void about(){
    std::cout <<"+----------------------------------------------+\n"
              "|                                              |\n"
              "|                 202100560401                 |\n"
              "|             Marcos V. Pretti Dias            |\n"
              "|                                              |\n"
              "+----------------------------------------------+" << std::endl;
}
