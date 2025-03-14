#ifndef _GERENCIA_H
#define _GERENCIA_H

#include "data.h"

typedef struct Gerencia Gerencia;

Gerencia* criaGerencia();

void insereUsuarioLista(Gerencia *g, Usuario *u);

void insereTecnicoLista(Gerencia *g, Tecnico *t);

void desalocaGerencia(Gerencia *g);

void imprimeBancoDeUsuarios(Gerencia *g);

void imprimeBancoDeTecnicos(Gerencia *g);

int verificaCPFUsuario(Usuario* u, Gerencia* g);

int verificaCPFTecnico(Tecnico* t, Gerencia* g);

char* getSetorUsuarioPorCPF(char* cpf, Gerencia *g);


#endif