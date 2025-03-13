#include <stdio.h>
#include <stdlib.h>
#include "ticket.h"
#include <string.h>

struct Ticket{
    char cpf[MAX_TAM_CPF];
    char id[MAX_TAM_ID];
    void* dado;
    func_ptr_tempoEstimado tempo;
    func_ptr_tipo tipo;
    func_ptr_notifica notifica;
    func_ptr_desaloca desaloca;
    char status;
};


/**
 * @brief Aloca uma estrutura Ticket na memória e inicializa os parâmetro necessários
 * @param cpfSol CPF de quem está solicitando a abertura do ticket
 * @param dado   Um ticket genérico  (considerando que existe mais de um tipo de ticket)
 * @param getTempo  Função de callback que retorna o tempo para aquele ticket ser resolvido
 * @param getTipo   Função de callback que retorna o tipo do ticket ser resolvido
 * @param notifica  Função de callback de notificação  (impressãode um ticket
 * @param desaloca  Função de callback que irá desalocar  um ticket da memória
 * @return  Uma estrutura Ticket inicializada.
 */
Ticket *criaTicket(char *cpfSol, void *dado, func_ptr_tempoEstimado getTempo, func_ptr_tipo getTipo, func_ptr_notifica notifica, func_ptr_desaloca desaloca){
    
    Ticket* t = (Ticket*) malloc(sizeof(Ticket));
    /*t->cpf = (char*) malloc (MAX_TAM_CPF * sizeof(char));
    t->id = (char*) malloc(MAX_TAM_ID * sizeof(char));*/
    //t->dado = (void*) malloc(sizeof(void));
    
    strcpy(t->cpf, cpfSol);
    t->tempo = getTempo;
    t->tipo = getTipo;
    t->notifica = notifica;
    t->desaloca = desaloca;
    t->dado = dado;
    t->status = 'A';

    return t;

}

/**
 * @brief Atribui um ID a um ticket
 * @param d Ticket inicializado
 * @param id ID a ser atribuido ao ticket
 */
void setIDTicket(Ticket *d, char *id){
    strcpy(d->id, id);
}

/**
 * @brief Finaliza um ticket
 * @param t Ticket inicializado
 */
void finalizaTicket(Ticket *t){
    t->status = 'F';
}

/**
 * @brief Recupera o CPF de quem solicitou a abertura do ticket
 * @param t Ticket inicializado
 * @return CPF de quem solicitou a abertura do ticket
 */
char *getCPFSolicitanteTicket(Ticket *t){
    return t->cpf;
}

/**
 * @brief Recupera o tempo estimado para resolver um ticket
 * @param t Ticket inicializado
 * @return tempo estimado para resolver um ticket
 */
int getTempoEstimadoTicket(Ticket *t){
    return t->tempo(t->dado);
}

/**
 * @brief Recupera o tipo de um ticket
 * @param t Ticket inicializado
 * @return tipo do Ticket
 */
char getTipoTicket(Ticket *t){
    return t->tipo(t->dado);
}

/**
 * @brief Recupera o status de um ticket
 * @param t Ticket inicializado
 * @return status do Ticket
 */
char getStatusTicket(Ticket *t){
    return t->status;
}

/**
 * @brief  Desaloca um ticket da memória
 * @param doc estrutura do tipo Ticket que deve ser liberada da memória
 */
void desalocaTicket(Ticket *doc){
    if(doc != NULL){
        /*free(doc->cpf);
        free(doc->id);*/
        free(doc->dado);
        doc->desaloca(doc);
    }
}

/**
 * @brief  Notifica (imprime) um ticket
 * @param doc Ticket a ser notificado
 */
void notificaTicket(Ticket *doc){
    printf("---------TICKET-----------\n");
    printf("- ID: %s\n", doc->id);
    printf("- Usuario solicitante: %s\n", doc->cpf);
    
    doc->notifica(doc->dado);

    printf("- Status: ");
    if(doc->status == 'A'){
        printf("Aberto\n");
    }
    else{
        printf("Finalizado\n");
    }
    printf("-------------------------\n\n");
}