#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outros.h"

struct Outros{
    char* descricao;
    char* local;
    int nivel;
    int tempoEstimado;
};

/**
 * @brief Aloca uma estrutura Outros na memória e inicializa os parâmetro necessários
 * @param descricao Descicao de Outros
 * @param local Local de Outros
 * @return  Uma estrutura Outros inicializada.
 */
Outros *criaOutros(char *descricao, char *local, int nivel){
    Outros* o = (Outros*) malloc(sizeof(Outros));

    strcpy(o->descricao, descricao);
    strcpy(o->local, local);
    o->nivel = nivel;

    return o;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Outros
 * @return  Um chamado do Tipo Outros
 */
Outros *lerOutros(){
    Outros* o = (Outros*) malloc (sizeof(Outros));
    o->descricao = (char*) malloc(sizeof(char) * MAX_TAM_DESCRICAO);
    o->local = (char*) malloc(sizeof(char) * MAX_TAM_LOCAL_OUTROS);

    scanf("%[^\n]\n", o->descricao);
    scanf("%[^\n]\n", o->local);
    scanf("%d\n", &o->nivel);

    return o;
}


/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Outros.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Outros
 */
void setTempoEstimadoOutros(Outros *o){
    o->tempoEstimado = o->nivel;
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Outros.
 * @param dado  Ticket do tipo Outros
 * @return  Tempo estimado para resolver um ticket do tipo Outros
 */
int getTempoEstimadoOutros(void *dado){
    Outros* o = (Outros*) dado;
    return o->tempoEstimado;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Outros
 */
char getTipoOutros(){
    return 'O';
}

/**
 * @brief  Desaloca um ticket do tipo Outros da memória
 * @param s  Ticket do tipo Outros
 */
void desalocaOutros(void *o){
    if(o != NULL){
        Outros* outros = (Outros*) o;
        free(outros->descricao);
        free(outros->local);
        free(outros);
    }
}

/**
 * @brief  Imprime um ticket do tipo Outros
 * @param dado  Ticket do tipo Outros
 */
void notificaOutros(void *dado){
    Outros* o = (Outros*) dado;
    printf("- Tipo: Outros\n");
    printf("- Descricao: %s\n", o->descricao);
    printf("- Local: %s\n", o->local);
    printf("- Nivel de dificuldade: %d\n", o->nivel);
    printf("- Tempo estimado: %dh\n", o->tempoEstimado);
}