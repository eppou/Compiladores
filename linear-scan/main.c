#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_REGISTERS 900000 // Define o número máximo de registradores virtuais

typedef struct RegistradorVirtual{
    int reg_virtual; // Registrador virtual
    int start; // Tempo de início do intervalo de vida
    int end;   // Tempo de fim do intervalo de vida
    int alocacao; //registrador no qual foi alocado 
}rv;

// ordena os intervalos de vida por tempo de inicio
void insertion_sort(rv *ativos[], int k) {
    for (int i = 1; i < k; i++) {
        if (ativos[i] == NULL) {
            continue; // Pula os elementos NULL
        }
        rv *key = ativos[i];
        int j = i - 1;

        while (j >= 0 && ativos[j] != NULL && ativos[j]->start > key->start) {
            ativos[j + 1] = ativos[j];
            j = j - 1;
        }
        ativos[j + 1] = key;
    }
}


//pega o maior intervalo no vetor de ativos
rv *maior_intervalo(rv *ativos[], int k){
    int maior = 0;

    for (int i = 0; i < k; i++) {
        if (ativos[i] != NULL){
            if (ativos[i]->end > ativos[maior]->end) {
                maior = i;
            }
            else if (ativos[i]->end == ativos[maior]->end) {
                if (ativos[i]->end - ativos[i]->start < ativos[maior]->end - ativos[maior]->start) {
                    maior = i;
                }
                else if (ativos[i]->end - ativos[i]->start == ativos[maior]->end - ativos[maior]->start) {
                    if (ativos[i]->reg_virtual > ativos[maior]->reg_virtual) {
                        maior = i;
                    }
                }
            }
        }
    }

    return ativos[maior];
}

void spill(rv *ativos[], int k, rv *intervalo){
    rv *maior = maior_intervalo(ativos, k);
    if (intervalo->end < maior->end) {

        intervalo->alocacao = maior->alocacao;
        maior->alocacao = -666;
        ativos[intervalo->alocacao] = intervalo;

    }
    else if (intervalo->end == maior->end){
        if (intervalo->end - intervalo->start > maior->end - maior->start) {   
            intervalo->alocacao = maior->alocacao;
            maior->alocacao = -666;
            ativos[intervalo->alocacao] = intervalo;
        }
        else if (intervalo->end - intervalo->start == maior->end - maior->start) {
            if (intervalo->reg_virtual < maior->reg_virtual) {
                intervalo->alocacao = maior->alocacao;
                maior->alocacao = -666;
                ativos[intervalo->alocacao] = intervalo;  
            } 
            else {
                intervalo->alocacao = -666;
            }         
        }
        else{
            intervalo->alocacao = -666;
        }
    }
    else {
        intervalo->alocacao = -666;
    }
}

bool linear_scan(int k, rv *intervalos[], int num_registradores_virtuais, int matriz_spils[]) {
    // Vetor de intervalos de vida ativos
    rv **ativos = calloc(k, sizeof(rv*));

    // Itera sobre todos os intervalos de vida
    for (int i = 0; i < num_registradores_virtuais; i++) {
        rv *intervalo = intervalos[i];


        // Verifica os intervalos de vida ativos
        for (int j = 0; j < k; j++) {
            if (ativos[j] != NULL && ativos[j]->end <= intervalo->start) {
                // Intervalo de vida expirado, remove-o dos ativos
                ativos[j] = NULL;
            }
        }


        // Procura um registrador vazio
        int posicao = -1;
        for (int j = 0; j < k; j++) {
            if (ativos[j] == NULL) {
                posicao = j;
                break;
            }
        }
        

        // Se não encontrou um registrador vazio, realiza o spill
        if (posicao == -1) {
            matriz_spils[i] = i;
            spill(ativos, k, intervalo);
             // Ordena os intervalos de vida ativos
            //insertion_sort(ativos, k);
        } else {
            // Alocando o registrador vazio encontrado
            intervalo->alocacao = posicao;
            ativos[posicao] = intervalo;
        }

    }

    // Verifica se todos os intervalos de vida foram alocados
    bool todos_alocados = false;
    for (int i = 0; i < num_registradores_virtuais; i++) {
        if (intervalos[i]->alocacao == -666) {
            todos_alocados = true;
            break;
        }
    }

    return todos_alocados;
}


bool loop_registradores(int k, rv *intervalos[], int num_registradores_virtuais,int matriz_spils[]){
    //aplica o algoritmo de linear scan para alocar os registradores
    bool retorno = linear_scan(k, intervalos, num_registradores_virtuais, matriz_spils);

    //imprime os registradores alocados
    for (int i = 0; i < num_registradores_virtuais; i++) {
        if (intervalos[i]->alocacao != -666)
            printf("vr%d: %d\n", intervalos[i]->reg_virtual, intervalos[i]->alocacao);
        else{
            printf("vr%d: SPILL\n", intervalos[i]->reg_virtual);
        }
        intervalos[i]->alocacao = -99;
    }

    return retorno;
}

int main() {
    int num_registradores_fisicos,start,end;
    scanf("K=%d", &num_registradores_fisicos);

    int num_registradores_virtuais = 0;
    //cria um vetor de ponteiros para intervalos de vida de tamanho MAX_REGISTERS
    struct RegistradorVirtual **intervalos = (struct RegistradorVirtual**) malloc(MAX_REGISTERS * sizeof(struct RegistradorVirtual*));

    char vr[10];
    // Leitura da entrada no formato vr%d --> %d %d
     while (scanf("%9s --> %d %d", vr, &start, &end) == 3) {
        num_registradores_virtuais++;
        // Alloca uma nova estrutura de intervalo de vida e insere num vetor dinamico
        // de intervalos de vida
        struct RegistradorVirtual *intervalo = (struct RegistradorVirtual*) malloc(sizeof(struct RegistradorVirtual));
        intervalo->reg_virtual = num_registradores_virtuais;
        intervalo->start = start;
        intervalo->end = end;
        intervalo->alocacao = -99;
        
        
        // Adiciona o intervalo de vida ao vetor de intervalos
        intervalos[num_registradores_virtuais - 1] = intervalo;
    }

    bool retornos[num_registradores_fisicos];
    int matriz_spils[num_registradores_fisicos+1][num_registradores_virtuais];
    for (int i = 0; i <= num_registradores_fisicos; i++) {
        for (int j = 0; j < num_registradores_virtuais; j++) {
            matriz_spils[i][j] = 0;
        }
    }

    // Realiza a alocação de registradores de k até 1
    for (int k = num_registradores_fisicos; k >= 2; k--) {
        printf("K = %d\n\n",k);
        retornos[k] = loop_registradores(k, intervalos, num_registradores_virtuais, matriz_spils[k]);
        printf("----------------------------------------\n");
    }


    printf("----------------------------------------");
    for (int i = num_registradores_fisicos; i >= 2; i--) {
        if(retornos[i]){
            printf("\nK = %d: SPILL on interation(s): ", i);
            //passa por todos os registradores virtuais e imprime os que foram alocados em SPILL
            bool comma_flag = false;
            for (int j = 0; j < num_registradores_virtuais; j++) {
                if (matriz_spils[i][j] != 0){
                    if (comma_flag){
                        printf(", %d", matriz_spils[i][j]);
                    }
                    else{
                        printf("%d", matriz_spils[i][j]);
                        comma_flag = true;
                    }
                }
            }
            
        }
        else
            printf("\nK = %d: Successful Allocation",i);
    }


    return 0;
}
