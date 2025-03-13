#ifndef _TECNICO_H
#define _TECNICO_H

#define MAX_TAM_AREA 7

typedef struct Tecnico Tecnico;

Tecnico *criaTecnico(char *nome, char *cpf, Data *dataNascimento, char *telefone, char *genero, char *area, float salario, int disponibilidade);

Tecnico *lerTecnico();

char* getSetorTecnico(Tecnico *t);

void incrementaTempoTrabalhado(Tecnico *t);

char getTipoTecnico();

void desalocaTecnico(void *t);

void imprimeTecnico(void *t);


#endif