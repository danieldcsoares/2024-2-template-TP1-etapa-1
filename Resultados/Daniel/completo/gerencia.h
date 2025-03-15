#ifndef _GERENCIA_H
#define _GERENCIA_H

#include "data.h"
#include "usuario.h"
#include "tecnico.h"
#include "fila.h"

#define DIA_BASE 18
#define MES_BASE 02
#define ANO_BASE 2025

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

int getQtdTecnicos(Gerencia *g);

int getQtdUsuarios(Gerencia *g);

Tecnico* getTecnicoNaLista(Gerencia *g, int i);

int comparaTempoTrabalhado(const void *a, const void *b);

int comparaNumeroTicketsAbertos(const void *a, const void *b);

void atualizaTicketsSolicitados(Gerencia *g, char *cpfSol, char sinal);

void imprimeRankingTecnicos(Gerencia *g);

void imprimeRankingUsuarios(Gerencia *g);

int calculaMediaIdadeUsuarios(Gerencia *g);

int calculaMediaIdadeTecnicos(Gerencia *g);

int calculaMediaTrabalhoTecnicos(Gerencia *g);

void imprimeRelatorio(Gerencia *g, Fila *f);

#endif