#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerencia.h"
#include "fila.h"
#include "distribuicao.h"
#include "usuario.h"
#include "tecnico.h"


struct Distribuicao{
    Gerencia *gerencia;
    Fila *fila;
};

Distribuicao *criaDistribuicao(Gerencia *g, Fila *f){
    Distribuicao *d = (Distribuicao*) malloc(sizeof(Distribuicao));

    d->gerencia = g;
    d->fila = f;

    return d;
}

/*void distribuiTickets(Distribuicao *d){
    for(int i = 0; i < getQtdTicketsNaFila(d->fila); i++){
        for(int j = 0; j < getQtdTecnicos(d->gerencia); j++){
            if(getStatusTicket(getTicketNaFila(d->fila, i)) == 'A'){
                if(getTipoTicket(getTicketNaFila(d->fila, i)) == 'S'){
                    if(strcmp(getAreaTecnico(getTecnicoNaLista(d->gerencia, j)), "TI") == 0){
                        if(getDisponibilidadeTecnico(getTecnicoNaLista(d->gerencia, j)) >= getTempoEstimadoTicket(getTicketNaFila(d->fila, i))){
                            finalizaTicket(getTicketNaFila(d->fila, i));
                            diminuiDisponibilidade(getTecnicoNaLista(d->gerencia, j), getTempoEstimadoTicket(getTicketNaFila(d->fila, i)));
                            incrementaTempoTrabalhado(getTecnicoNaLista(d->gerencia, j), getTempoEstimadoTicket(getTicketNaFila(d->fila, i)));
                            break;
                        }
                    }
                }

                else if(getTipoTicket(getTicketNaFila(d->fila, i)) == 'M' || getTipoTicket(getTicketNaFila(d->fila, i)) == 'O'){
                    if(strcmp(getAreaTecnico(getTecnicoNaLista(d->gerencia, j)), "GERAL") == 0){
                        if(getDisponibilidadeTecnico(getTecnicoNaLista(d->gerencia, j)) >= getTempoEstimadoTicket(getTicketNaFila(d->fila, i))){
                            finalizaTicket(getTicketNaFila(d->fila, i));
                            diminuiDisponibilidade(getTecnicoNaLista(d->gerencia, j), getTempoEstimadoTicket(getTicketNaFila(d->fila, i)));
                            incrementaTempoTrabalhado(getTecnicoNaLista(d->gerencia, j), getTempoEstimadoTicket(getTicketNaFila(d->fila, i)));
                            break;
                        }
                    }
                }
            }
        }
    }
}*/

void distribuiTickets(Distribuicao *d){
    for(int i = 0; i < getQtdTicketsNaFila(d->fila); i++){
        void* ticket = getTicketNaFila(d->fila, i);
        if(getStatusTicket(ticket) != 'A') continue;

        char tipo = getTipoTicket(ticket);
        int tempoEstimado = getTempoEstimadoTicket(ticket);

        for(int j = 0; j < getQtdTecnicos(d->gerencia); j++){
            Tecnico* tecnico = getTecnicoNaLista(d->gerencia, j);
            char* area = getAreaTecnico(tecnico);
            int disponibilidade = getDisponibilidadeTecnico(tecnico);

            if((tipo == 'S' && strcmp(area, "TI") == 0) || ((tipo == 'M' || tipo == 'O') && strcmp(area, "GERAL") == 0)){
                if(disponibilidade >= tempoEstimado){
                    finalizaTicket(ticket);
                    diminuiDisponibilidade(tecnico, tempoEstimado);
                    incrementaTempoTrabalhado(tecnico, tempoEstimado);
                    atualizaTicketsSolicitados(d->gerencia, getCPFSolicitanteTicket(ticket), '-'); // SE FOR USAR O OUTRO, LEMBRAR DE PASSAR ISSO PARA LA
                    break;
                }
            }
        }
    }
}


void desalocaDistribuicao(Distribuicao *d){
    if(d != NULL){
        free(d);
    }
}

