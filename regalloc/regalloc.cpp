#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <limits>

namespace alocador {

    class Vertice {
        public:
            int id;
            int registrador_atribuido;
            bool imprimir;
            bool ativo;
            bool registrador_virtual;
            std::map<int, Vertice*> interferencias;

            Vertice(int id) {
                this->id = id;
                this->imprimir = false;
                this->ativo = true;
                this->registrador_atribuido = -1;
                this->registrador_virtual = false;
                this->interferencias = std::map<int, Vertice*>();
            }
    };

    class Grafo {
        public:
            int numero;
            int n_registradores_virtuais;
            int registradores_disponiveis;
            std::map<int, Vertice*> vertices;
            int verticeMenosInterferencias();
            int verticeMaisInterferencias();
            bool existePossivelDerramamento(int registradores_disponiveis);

            Grafo(int numero, int registradores_disponiveis) {
                this->numero = numero;
                this->registradores_disponiveis = registradores_disponiveis;
                this->n_registradores_virtuais = 0;
                this->vertices = std::map<int, Vertice*>();
            }
    };

    bool alocacaoDeRegistro(Grafo* grafo, int registradores_disponiveis);

};

int alocador::Grafo::verticeMenosInterferencias() {
    int menosInterferencias = std::numeric_limits<int>::max();
    alocador::Vertice* verticeMenosInterferencias = nullptr;

    for (auto const& [chave, vertice] : this->vertices) {
        if (vertice->ativo && vertice->id >= this->registradores_disponiveis) {
            int interferencias = 0;

            for (auto const& [_, interferencia] : vertice->interferencias) {
                if (interferencia->ativo) {
                    interferencias++;
                }
            }

            if (interferencias < menosInterferencias || (interferencias == menosInterferencias && vertice->id < verticeMenosInterferencias->id)) {
                menosInterferencias = interferencias;
                verticeMenosInterferencias = vertice;
            }
        }
    }

    return verticeMenosInterferencias->id;
}

int alocador::Grafo::verticeMaisInterferencias() {
    
    int maisInterferencias = -1;
    alocador::Vertice* verticeMaisInterferencias = nullptr;

    for (auto const& [chave, vertice] : this->vertices) {

        if (vertice->ativo && vertice->id >= this->registradores_disponiveis) {
            
            int interferencias = 0;

            for (auto const& [chave, interferencia] : vertice->interferencias) {
                if (interferencia->ativo) {
                    interferencias++;
                }
            }

            if (interferencias > maisInterferencias) {
                maisInterferencias = interferencias;
                verticeMaisInterferencias = vertice;
            } else if (interferencias == maisInterferencias) {
                if (vertice->id < verticeMaisInterferencias->id) {
                    verticeMaisInterferencias = vertice;
                }
            }

        }
    }

    return verticeMaisInterferencias->id;

}

bool alocador::Grafo::existePossivelDerramamento(int registradores_disponiveis) {
    
    int interferencias = 0;

    for (auto const& [chave, vertice] : this->vertices) {
        if (vertice->ativo && vertice->id >= this->registradores_disponiveis) {
            for (auto const& [chave, interferencia] : vertice->interferencias) {
                if (interferencia->ativo) {
                    interferencias++;
                }
            }

            if (interferencias < registradores_disponiveis) {
                return false;
            } else {
                interferencias = 0;
            }
        }
    }

    return true;

}

bool alocador::alocacaoDeRegistro(alocador::Grafo* grafo, int registradores_disponiveis) {
    
    std::stack<Vertice*> pilha;

    bool status = true;

    for (int i = 0; i < grafo->n_registradores_virtuais; i++) {

        int idVertice = -1;

        int possivelDerramamento = grafo->existePossivelDerramamento(registradores_disponiveis);

        if (possivelDerramamento) {
            idVertice = grafo->verticeMaisInterferencias();
        } else {
            idVertice = grafo->verticeMenosInterferencias();
        }

        Vertice* vertice = grafo->vertices[idVertice];

        vertice->ativo = false;

        pilha.push(vertice);

        if (vertice->imprimir) {
            std::cout << "Push: " << vertice->id << (possivelDerramamento ? " *" : "") << std::endl;
        }

    }

    for (int i = 0; i < grafo->n_registradores_virtuais; i++) {

        Vertice* vertice = pilha.top();
        pilha.pop();

        vertice->ativo = true;

        bool registrosUsados[registradores_disponiveis] = {0};

        for (auto const& [chave, interferencia] : vertice->interferencias) {
            if (interferencia->ativo && interferencia->registrador_atribuido != -1 && interferencia->registrador_atribuido < registradores_disponiveis) {
                registrosUsados[interferencia->registrador_atribuido] = true;
            }
        }

        bool erro = true;

        for (int j = 0; j < registradores_disponiveis; j++) {
            if (!registrosUsados[j]) {
                vertice->registrador_atribuido = j;
                erro = false;
                break;
            }
        }
        
        if (erro) {

            if (vertice->imprimir) {
                std::cout << "Pop: " << vertice->id << " -> NO COLOR AVAILABLE" << std::endl;
                status = false;
            }

            break;

        } else {

            if (vertice->imprimir) {
                std::cout << "Pop: " << vertice->id << " -> " << vertice->registrador_atribuido << std::endl;
            }

        }

        for (auto const& [chave, interferencia] : vertice->interferencias) {
            interferencia->ativo = true;
        }
        
    }

    for (auto const& [chave, vertice] : grafo->vertices) {

        vertice->ativo = true;

        if (vertice->registrador_virtual) {
            vertice->registrador_atribuido = -1;
        }

    }

    return status;

}
