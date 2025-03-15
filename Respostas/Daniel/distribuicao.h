#ifndef _DISTRIBUICAO_H
#define _DISTRIBUICAO_H

#include "gerencia.h"
#include "fila.h"

typedef struct Distribuicao Distribuicao;

Distribuicao* criaDistribuicao(Gerencia *g, Fila *f);

void distribuiTickets(Distribuicao *d);

void desalocaDistribuicao(Distribuicao *d);

#endif