#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manutencao.h"

struct Manutencao{
    char* nome;
    char* local;
    char* estado;
    int tempoEstimado;
    char* setor;
};

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetro necessários
 * @param nome Nome da Manutencao
 * @param local Local da Manutencao
 * @param estado 
 * @return  Uma estrutura Manutencao inicializada.
 */
Manutencao *criaManutencao(char *nome, char *local, char* estado){
    Manutencao* m = (Manutencao*) malloc (sizeof(Manutencao));

    strcpy(m->nome, nome);
    strcpy(m->local, local);
    strcpy(m->estado, estado);

    return m;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao(){
    Manutencao* m = (Manutencao*) malloc (sizeof(Manutencao));
    m->nome = (char*) malloc(sizeof(char) * MAX_TAM_NOME_MANUTENCAO);
    m->local = (char*) malloc(sizeof(char) * MAX_TAM_LOCAL_MANUTENCAO);
    m->estado = (char*) malloc(sizeof(char) * MAX_TAM_ESTADO);

    scanf("%[^\n]\n", m->nome);
    scanf("%[^\n]\n", m->estado);
    scanf("%[^\n]\n", m->local);

    return m;
}

void setSetorUsuarioManutencao(Manutencao *m, char *setor){
    m->setor = (char*) malloc(sizeof(char) * MAX_TAM_SETOR);
    strcpy(m->setor,setor);
}


/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende do estado e setor
 * @param s  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *m){
    if(strcmp(m->estado, "RUIM") == 0){
        m->tempoEstimado = 3;
    }
    else{
        if(strcmp(m->estado, "REGULAR") == 0){
            m->tempoEstimado = 2;
        }
        else{
            if(strcmp(m->estado, "BOM") == 0){
                m->tempoEstimado = 1;
            }
        }
    }

    int fator;
    if(strcmp(m->setor, "RH") == 0){
        fator = 2;
    }
    else{
        if(strcmp(m->setor, "FINANCEIRO") == 0){
            fator = 3;
        } 
        else{
            if((strcmp(m->setor, "P&D") == 0) || (strcmp(m->setor, "VENDAS") == 0) || (strcmp(m->setor, "MARKETING") == 0)){
                fator = 1;
            }
        }
    }

    m->tempoEstimado = m->tempoEstimado * fator;
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado){
    Manutencao* m = (Manutencao*) dado;
    return m->tempoEstimado;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'M' para Manutencao
 */
char getTipoManutencao(){
    return 'M';
}

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param s  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *m){
    if(m != NULL){
        Manutencao* man = (Manutencao*) m;
        free(man->nome);
        free(man->local);
        free(man->estado);
        free(man->setor);
        free(man);
    }
}

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado){
    Manutencao* m = (Manutencao*) dado;
    printf("- Tipo: Manutencao\n");
    printf("- Nome do item: %s\n", m->nome);
    printf("- Estado de conservacao: %s\n", m->estado);
    printf("- Local: %s\n", m->local);
    printf("- Tempo estimado: %dh\n", m->tempoEstimado);
}