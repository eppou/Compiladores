#include <iostream>
#include <vector>
#include <sstream>

struct MatrizDinamica {
    std::vector<std::vector<int>> dados;
    int linhas;
    int colunas;
};

MatrizDinamica criarMatriz(const std::string& entrada) {
    std::vector<std::vector<int>> matriz;
    std::istringstream ss(entrada);
    char buffer;
    char valor;
    int n_colunas = 0;

    // Encontrar o número máximo de colunas
    int maxColunas = 0;

    while (ss >> buffer) {
        if (buffer == '[') {

            std::vector<int> linha;
            ss >> valor; // Ler o primeiro valor que está contido na declaração da linha
            
            while (ss >> valor) {
                std::cout << "valor: " << valor << "n linhas: " << n_colunas << std::endl;
                if(valor != ',' ){
                    //cria uma string que vai recebendo os valores do numero
                    std::string numero;
                    //concatena o valot no numero
                    numero += valor;

                    if (buffer == ']'){
                        if (n_colunas > maxColunas){
                            maxColunas = n_colunas;
                        }
                        n_colunas = 0;
                        break;
                    }
                }
                else{
                    n_colunas++;
                    //coloca o valor transformado em float na matriz
                    linha.push_back(std::stof(numero));
                }
            }

        }
    }

    std::cout << "maxColunas" << maxColunas << std::endl;
    // Preencher as linhas com zeros
    for (auto& linha : matriz) {
        linha.resize(maxColunas, 0);
    }
    return {matriz, static_cast<int>(matriz.size()), maxColunas};
}

int main() {
    std::string entrada = "a := [[3,3,3],[32,2,1,22,17],[1,2,5,4]];";
    MatrizDinamica minhaMatriz = criarMatriz(entrada);

    // Imprimir a matriz resultante
    for (const auto& linha : minhaMatriz.dados) {
        for (int valor : linha) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}