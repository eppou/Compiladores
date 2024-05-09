%{
    #include "regalloc.cpp"
    extern int yylex(void);
    extern char* yytext;
    extern int yychar;
    extern int yydebug;
    extern void yyerror(char *s);
    extern void yylex_destroy(void);
    int current_vertex_index = -1;
    std::vector<int> interferencias;
    std::vector<bool> results;

    //inicializa o grafo
    alocador::Grafo* graph = new alocador::Grafo(0,0);
%}

%union {
    int integer_token;
}

%token GRAFO
%token K_TOKEN
%token ARROW
%token<integer_token> NUM_INTEGER
%token NEWLINE
%token COLON
%token EQUAL

%type <integer_token> N_grafo
%type <integer_token> registradores_disponiveis

%start Programa

%%

Programa: primeira_definicao Loop;

Loop 
    :Interferences NEWLINE Loop { };
    | Interferences { };

primeira_definicao
    : N_grafo NEWLINE registradores_disponiveis NEWLINE {graph->numero = $1; graph->registradores_disponiveis = $3;};


N_grafo
    : GRAFO NUM_INTEGER COLON { $$ = $2; };

registradores_disponiveis
    : K_TOKEN EQUAL NUM_INTEGER { $$ = $3; };

Interferences
    : NUM_INTEGER ARROW LoopInteger {
    // Verifica se o vértice já existe
if (graph->vertices[$1] == nullptr) {
        
    alocador::Vertice* vertice = new alocador::Vertice($1);
    graph->vertices[$1] = vertice;

}

graph->vertices[$1]->imprimir = true;

// Para cada interferência, adicione reciprocamente
for (auto interferencia : interferencias) {

    if (graph->vertices[interferencia] == nullptr) {
        
        alocador::Vertice* vertice = new alocador::Vertice(interferencia);
        graph->vertices[interferencia] = vertice;
    
    }

    // Verifica se a interferência já está em graph->vertices[$1]->interferencias
    int adicionar = 1;

    for (auto const& [chave, vertice] : graph->vertices[$1]->interferencias) {
        if (chave == interferencia) {
            adicionar = 0;
            break;
        }
    }

    if (adicionar) graph->vertices[$1]->interferencias[interferencia] = graph->vertices[interferencia];

    adicionar = 1;

    // Verifica se $1 já está em graph->vertices[interferencia]->interferencias
    for (auto const& [chave, vertice] : graph->vertices[interferencia]->interferencias) {
        if (chave == $1) {
            adicionar = 0;
            break;
        }
    }

    if (adicionar) graph->vertices[interferencia]->interferencias[$1] = graph->vertices[$1];

}

interferencias.clear();
    
};

LoopInteger
    : NUM_INTEGER LoopInteger {interferencias.push_back($1);};
    | {};

%%

int main(int argc, char **argv) {

    yyparse();

    std::cout << "Graph " << graph->numero << " -> Physical Registers: " << graph->registradores_disponiveis << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    for(int i = graph->registradores_disponiveis; i > 1; i--) {

        int virtual_registers = 0;

        for (auto const& [key, vertex] : graph->vertices) {
                
            if(vertex->id > graph->registradores_disponiveis) {
                virtual_registers++;
                vertex->registrador_virtual = true;
            } else {
                vertex->registrador_atribuido = vertex->id;
            }

        }

        graph->n_registradores_virtuais = virtual_registers;

        std::cout << "K = " << i << std::endl;
        std::cout << std::endl;

        bool allocation_result = alocador::alocacaoDeRegistro(graph, i);

        if (allocation_result) {
            results.push_back(true);
        } else {
            results.push_back(false);
        }

        std::cout << "----------------------------------------" << std::endl;

    }

    std::cout << "----------------------------------------" << std::endl;

    for (int i = 0; i < results.size(); i++) {

        int space = graph->registradores_disponiveis - i < 10 ? true : false;

        if (results[i]) {

            if (space) {
                std::cout << "Graph " << graph->numero << " -> K =  " << graph->registradores_disponiveis - i << ": Successful Allocation";
            } else {
                std::cout << "Graph " << graph->numero << " -> K = " << graph->registradores_disponiveis - i << ": Successful Allocation";
            }
        } else {
            if (space) {
                std::cout << "Graph " << graph->numero << " -> K =  " << graph->registradores_disponiveis - i << ": SPILL";
            } else {
                std::cout << "Graph " << graph->numero << " -> K = " << graph->registradores_disponiveis - i << ": SPILL";
            }
        }

        if (i + 1 < results.size()) {
            std::cout << std::endl;
        }
    }


    for (int i = 0; i < graph->vertices.size(); i++) delete graph->vertices[i];


    yylex_destroy();

}