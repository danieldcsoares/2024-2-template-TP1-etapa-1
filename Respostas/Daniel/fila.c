#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "ticket.h"

struct Fila{
    int qtdTickets;
    int qtdAlocados;
    Ticket** tickets;
};


/**
 * @brief Aloca uma estrutura Fila na memória e inicializa os parâmetro necessários
 * @return  Uma Fila inicializada.
 */
Fila *criaFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila));

    f->qtdTickets = 0;
    f->qtdAlocados = 1;

    f->tickets = (Ticket**) malloc(f->qtdAlocados * sizeof(Ticket*));

    return f;
}

/**
 * @brief  Desaloca uma fila da memória
 * @param f estrutura do tipo Fila que deve ser liberada da memória
 * @return (void)
 */
void desalocaFila(Fila *f){
    if(f != NULL){
        for(int i = 0; i < f->qtdTickets; i++){
            desalocaTicket(f->tickets[i]);
        }
        free(f->tickets);
        free(f);
    }
}

/**
 * @brief  Insere um ticket na fila de processamento. Um ticket deve ser inserido sempre na última posição.
 * Obviamente, essa função também faz a manipulação de memória necessária para alocar um novo ticket.
 * @param f  Fila que receberá o novo ticket
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido (ver ticket.h)
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido (ver ticket.h)
 * @param notifica  Função de callback de notificação de um ticket (ver ticket.h)
 * @param desaloca  Função de callback que desaloca  um ticket da memória (ver ticket.h)
 */
void insereTicketFila(Fila *f, char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo,
                      func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
                        
                        Ticket* t = criaTicket(cpfSol,dado,getTempo,getTipo,notifica,desaloca);

                        if(f->qtdTickets == f->qtdAlocados){
                            f->qtdAlocados+=2;
                            f->tickets = realloc(f->tickets, f->qtdAlocados * sizeof(Ticket*));
                        }

                        f->tickets[f->qtdTickets] = t;
                        
                        char* id = (char*) malloc(10 * sizeof(char));
                        sprintf(id, "Tick-%d", f->qtdTickets + 1);
                        setIDTicket(f->tickets[f->qtdTickets], id);
                        free(id);
                        f->qtdTickets++;

                      }


/**
 * @brief Recupera a quantidade de tickets  em uma fila
 * @param f  Estrutura Fila inicializada.
 * @return Quantidade de Tickets na fila
 */
int getQtdTicketsNaFila(Fila *f){
    return f->qtdTickets;
}

/**
 * @brief Recupera a quantidade de tickets em uma fila com um determinado status
 * @param f  Estrutura Fila inicializada.
 * @param status Status do ticket
 * @return Quantidade de Tickets na fila com o status informado
 */
int getQtdTicketsPorStatusNaFila(Fila *f, char status){
    int qtdStatus = 0;
    for(int i = 0; i < f->qtdTickets; i++){
        if(getStatusTicket(f->tickets[i]) == status){
            qtdStatus++;
        }
    }
    return qtdStatus;
}

/**
 * @brief Recupera um ticket na fila de processamento. Um ticket deve ser recuperado sempre na i-ésima posição.
 * @param f  Fila que contém o ticket
 * @param i  Posição do ticket na fila
 * @return  Ticket recuperado da fila
 */
Ticket *getTicketNaFila(Fila *f, int i){
    return f->tickets[i];
}

/**
 * @brief A função notificaFila imprime todos os tickets na Fila f
 * @param f  Fila inicializada contendo zero ou mais tickets.
 */
void notificaFila(Fila *f){
    for(int i = 0; i < f->qtdTickets; i++){
        notificaTicket(f->tickets[i]);
    }
}