#ifndef _USUARIO_H
#define _USUARIO_H

#define MAX_TAM_SETOR 12

#include "data.h"

typedef struct Usuario Usuario;

Usuario *criaUsuario(char *nome, char *cpf, Data *dataNascimento, char *telefone, char *genero, char *setor);

Usuario *lerUsuario();

char* getSetorUsuario(Usuario *u);

void incrementaTicketsSolicitados(Usuario *u);

char getTipoUsuario();

void desalocaUsuario(void *u);

void imprimeUsuario(void *usuario);


#endif