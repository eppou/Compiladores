#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <cctype> // Para usar a função tolower
#include <sstream> // Para usar o stringstream

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'c' || c == 's' || c == 't';
}

bool isNotTrigo(char c){
    //return c == 's' || c == 'c' || c== 't'
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    //else if (c == 'c' || c == 's' || c == 't') // Operadores trigonométricos
       // return 4;
    else
        return -1;
}

std::unordered_map<std::string, std::string> rpnEquivalents = {
    {"sen", "SEN"},
    {"cos", "COS"},
    {"tg", "TG"},
    {"pi", "3.141593"}
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
        
        if (std::isalpha(c) && isNotTrigo(c)) {
        
            std::string identifier;
            while (std::isalpha(expression[i])) {
                identifier += expression[i];
                ++i;
            }
            --i; // Decremento i para compensar o incremento adicional no loop

            auto it = rpnEquivalents.find(identifier);
            if (it != rpnEquivalents.end()) {
                rpnExpression += it->second;
                rpnExpression += ' ';
            } else {
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
                rpnExpression += operatorStack.top();
                rpnExpression += ' ';
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        } else if (isOperator(c)) {
            std::cout << c;
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(c)) {
                rpnExpression += operatorStack.top();
                rpnExpression += ' ';
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        rpnExpression += operatorStack.top();
        rpnExpression += ' ';
        operatorStack.pop();
    }

    // Remove o espaço extra no final
    if (!rpnExpression.empty()) {
        rpnExpression.pop_back();
    }

    return rpnExpression;
}

int main() {
    std::string expression = "sen(x)*(1+x)+chuchu*pi";
    std::string rpnExpression = infixToRPN(expression);
    std::cout << "Expression in RPN format: " << rpnExpression << std::endl;
    return 0;
}
