#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "software.h"

struct Software{
    char nome[MAX_TAM_NOME_SOFTWARE];
    char categoria[MAX_TAM_CAT];
    int impacto;
    char motivo[MAX_TAM_MOTIVO];
    int tempoEstimado;
};


/**
 * @brief Aloca uma estrutura Software na memória e inicializa os parâmetro necessários
 * @param nome Nome do software
 * @param categoria Categoria do software
 * @param impacto Impacto do chamado
 * @param motivo Motivo da abertura do ticket
 * @return  Uma estrutura Software inicializada.
 */
Software *criaSoftware(char *nome, char *categoria, int impacto, char *motivo){
    Software* s = (Software*) malloc (sizeof(Software));
    /*s->nome = (char*) malloc(sizeof(char) * MAX_TAM_NOME_SOFTWARE);
    s->categoria = (char*) malloc(sizeof(char) * MAX_TAM_CAT);
    s->motivo = (char*) malloc(sizeof(char) * MAX_TAM_MOTIVO);*/

    s->impacto = impacto;
    strcpy(s->nome, nome);
    strcpy(s->categoria, categoria);
    strcpy(s->motivo, motivo);

    return s;
}

/**
 * @brief Lê da entrada padrão um  ticket do TIPO software
 * @return  Um chamado do Tipo Software
 */
Software *lerSoftware(){
    Software* s = (Software*) malloc (sizeof(Software));
    /*s->nome = (char*) malloc(sizeof(char) * MAX_TAM_NOME_SOFTWARE);
    s->categoria = (char*) malloc(sizeof(char) * MAX_TAM_CAT);
    s->motivo = (char*) malloc(sizeof(char) * MAX_TAM_MOTIVO);*/

    scanf("%[^\n]\n", s->nome);
    scanf("%[^\n]\n", s->categoria);
    scanf("%d\n", &s->impacto);
    scanf("%[^\n]\n", s->motivo);

    return s;
}

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Software.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Software
 */
void setTempoEstimadoSoftware(Software *s){
    if(strcmp(s->categoria, "BUG") == 0){
        s->tempoEstimado = 3;
    }
    else{
        if(strcmp(s->categoria, "OUTROS") == 0){
            s->tempoEstimado = 2;
        }
        else{
            if(strcmp(s-> categoria, "DUVIDA") == 0){
                s->tempoEstimado = 1;
            }
        }
    }

    s->tempoEstimado += s->impacto;
}

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Software.
 * @param dado  Ticket do tipo Software
 * @return  Tempo estimado para resolver um ticket do tipo Software
 */
int getTempoEstimadoSoftware(void *dado){
    Software* s = (Software*) dado;
    return s->tempoEstimado;
}

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Software
 */
char getTipoSoftware(){
    return 'S';
}

/**
 * @brief  Desaloca um ticket do tipo Software da memória
 * @param s  Ticket do tipo Software
 */
void desalocaSoftware(void *s){
    if(s != NULL){
        Software* sw = (Software*) s;
        /*free(sw->nome);
        free(sw->categoria);
        free(sw->motivo);*/
        free(sw);
    }
}

/**
 * @brief  Imprime um ticket do tipo Software
 * @param dado  Ticket do tipo Software
 */
void notificaSoftware(void *dado){
    Software* s = (Software*) dado;
    printf("- Tipo: Software\n");
    printf("- Nome do software: %s\n", s->nome);
    printf("- Categoria: %s\n", s->categoria);
    printf("- Nível do impacto: %d\n", s->impacto);
    printf("- Motivo: %s\n", s->motivo);
    printf("- Tempo estimado: %dh\n", s->tempoEstimado);
}