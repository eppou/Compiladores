#include "defines.hpp"
#include "comandos.hpp"
#include <unordered_map>
#include <cctype> // Para usar a função tolower
#include <sstream> // Para usar o stringstream
#include <stack>

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

//pega todos os id_structs dentro do mapa de symbols e imprime o valor de cada um e o tipo, se for matriz imprime o numero de linhas e colunas
void show_symbols(std::unordered_map<std::string, id_struct> &symbols) {
    //percorre o map de symbols e imprime os valores
    for (auto const& [key, val] : symbols) {
        std::cout << key << " = ";
        if (val.type == 0){
            std::cout << val.value << " - INT"<< std::endl;
        }else if (val.type == 1){
            std::cout << val.real_value << " - FLOAT" <<std::endl;
        }else if (val.type == 2){
            std::cout << "MATRIZ [" << val.matrix.linhas << "] [" << val.matrix.colunas << "]" << std::endl;
        }
    }
}

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


//------------------------------------------------RPN--------------------------------------------------
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}



int precedence(char c) {
    std:: cout << "c: " << c << std::endl;
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else if(c == 's' || c == 'c' || c == 't')
        return 4;
    else
        return -1;
}

bool isTrigonometricFunction(const std::string &expression, int i) {
    return expression[i] == 's' && expression[i + 1] == 'e' && expression[i + 2] == 'n' ||
           expression[i] == 'c' && expression[i + 1] == 'o' && expression[i + 2] == 's' ||
           expression[i] == 't' && expression[i + 1] == 'g';
}

std::unordered_map<std::string, std::string> rpnEquivalents = {
    {"sen", "SEN"},
    {"cos", "COS"},
    {"tg", "TG"},
    {"pi", "3.141593"},
    {"s", "SEN"},
    {"c", "COS"},
    {"t", "TG"}
};

std::string formatNumber(double number) {
    std::ostringstream stream;
    stream.precision(6);
    stream << std::fixed << number;
    return stream.str();
}

std::string infixToRPN(const std::string &expression) {
    std::stack<char> operatorStack;
    std::string rpnExpression;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        
        if (std::isalpha(c) && !isTrigonometricFunction(expression, i)) {
        
            std::string identifier;
            while (std::isalpha(expression[i])) {
                identifier += expression[i];
                ++i;
            }
            --i; // Decremento i para compensar o incremento adicional no loop

            auto it = rpnEquivalents.find(identifier);
            if (it != rpnEquivalents.end() && identifier == "pi") {
                rpnExpression += it->second;
                rpnExpression += ' ';
            } else if (identifier != "sen" && identifier != "cos" && identifier != "tg" && identifier != "rpn") {
                // Se não encontrarmos um equivalente RPN, consideramos como um identificador
                rpnExpression += identifier;
                rpnExpression += ' ';
            }
        } else if (std::isdigit(c) || c == '.') {
            std::string number;
            while (std::isdigit(expression[i]) || expression[i] == '.') {
                number += expression[i];
                ++i;
            }
            --i; // Decremento i para compensar o incremento adicional no loop
            double num = std::stod(number);
            rpnExpression += formatNumber(num);
            rpnExpression += ' ';
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                if (operatorStack.top() == 's' || operatorStack.top() == 'c' || operatorStack.top() == 't') {
                    // Se for uma função trigonométrica, adicionamos a função em maiúsculo e com nome completo
                    auto it = rpnEquivalents.find(std::string(1, operatorStack.top()));
                    rpnExpression += it->second;
                    rpnExpression += ' ';
                }else{
                    rpnExpression += operatorStack.top();
                    rpnExpression += ' ';
                }
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        } else if (isOperator(c)) {
            std::cout << "c: " << c << std::endl;
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                if(operatorStack.top() == 's' || operatorStack.top() == 'c' || operatorStack.top() == 't'){
                    auto it = rpnEquivalents.find(std::string(1, operatorStack.top()));
                    rpnExpression += it->second;
                    rpnExpression += ' ';
                }else{
                    rpnExpression += operatorStack.top();
                    rpnExpression += ' ';
                }
                operatorStack.pop();
            }
            operatorStack.push(c);
        } else if (isTrigonometricFunction(expression, i)) {
            //lida com as funções trigonométricas sen, cos e tg e coloca na ordem correta
            std::string identifier;
            while (std::isalpha(expression[i])) {
                identifier += expression[i];
                ++i;
            }
            --i; // Decremento i para compensar o incremento adicional no loop
            operatorStack.push(identifier[0]);
        }
        
    }

    while (!operatorStack.empty()) {
        if(operatorStack.top() == 's' || operatorStack.top() == 'c' || operatorStack.top() == 't'){
            auto it = rpnEquivalents.find(std::string(1, operatorStack.top()));
            rpnExpression += it->second;
            rpnExpression += ' ';
        }else{
            rpnExpression += operatorStack.top();
            rpnExpression += ' ';
        }
        operatorStack.pop();
    }

    // Remove o espaço extra no final
    if (!rpnExpression.empty()) {
        rpnExpression.pop_back();
    }

    std::cout << "Expression in RPN format:\n\n" << rpnExpression << std::endl;
    return rpnExpression;
}
//------------------------------------------------MATRIZ------------------------------------------------
bool isNum(char c){
    return c >= '0' && c <= '9';
}

MatrizDinamica criarMatriz(const std::string& entrada) {
    std::vector<std::vector<float>> matriz;
    std::istringstream ss(entrada);
    char buffer;
    char valor;
    int n_colunas = 1;

    // Encontrar o número máximo de colunas
    int maxColunas = 0;


    std::vector<float> linha;
    ss >> valor; // Ler o primeiro valor que está contido na declaração da linha
    std::string numero;


    while (ss >> valor) {
        
        if(isNum(valor) || valor == '-' || valor == '.'){
            //cria uma string que vai recebendo os valores do numero
            //concatena o valor no numero
            numero += valor;
        }
        else if (valor == ','){
            n_colunas++;
            //coloca o valor transformado em float na matriz
            if (numero.size() > 0){
                linha.push_back(std::stof(numero));
                numero.clear();
            }
        }

        if (valor == ']'){
                if (n_colunas > maxColunas){
                    maxColunas = n_colunas;
                }
                n_colunas = 0;
                //adiciona o ultimo valor na linha
                if(numero.size() > 0){
                    linha.push_back(std::stof(numero));
                    numero.clear();

                    //adiciona a linha na matriz
                    matriz.push_back(linha);
                    linha.clear();
                }
                
        }
    }

    //adiciona os zeros na matriz para completar as colunas
    for (int i = 0; i < matriz.size(); i++){
        for (int j = matriz[i].size(); j < maxColunas; j++){
            matriz[i].push_back(0);
        }
    }


    return {matriz, matriz.size(), maxColunas};
}
