#ifndef _TECNICO_H
#define _TECNICO_H

#define MAX_TAM_AREA 7

#include "data.h"

typedef struct Tecnico Tecnico;

Tecnico *criaTecnico(char *nome, char *cpf, Data *dataNascimento, char *telefone, char *genero, char *area, float salario, int disponibilidade);

Tecnico *lerTecnico();

char* getAreaTecnico(Tecnico *t);

void incrementaTempoTrabalhado(Tecnico *t, int tempo);

void diminuiDisponibilidade(Tecnico *t, int tempo);

int getTempoTrabalhadoTecnico(Tecnico *t);

Data* getDataNascimentoTecnico(Tecnico *t);

char getTipoTecnico();

char* getCPFTecnico(Tecnico *t);

int getDisponibilidadeTecnico(Tecnico *t);

char* getNomeTecnico(Tecnico *t);

void desalocaTecnico(void *t);

void imprimeTecnico(void *t);


#endif