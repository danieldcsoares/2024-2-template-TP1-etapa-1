#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "tecnico.h"
#include "pessoa.h"
#include "usuario.h"

struct Gerencia{
    Usuario** usuarios;
    int qtdUsuarios;
    int qtdUsuAlocados;

    Tecnico** tecnicos;
    int qtdTecnicos;
    int qtdTecAlocados;
};

Gerencia* criaGerencia(){
    Gerencia* g = (Gerencia*) malloc(sizeof(Gerencia));

    g->qtdUsuarios = 0;
    g->qtdTecnicos = 0;

    g->qtdUsuAlocados = 1;
    g->qtdTecAlocados = 1;

    g->usuarios = (Usuario**) malloc(g->qtdUsuAlocados * sizeof(Usuario*));
    g->tecnicos = (Tecnico**) malloc(g->qtdTecAlocados * sizeof(Tecnico*));

    return g;
}

void insereUsuarioLista(Gerencia *g, Usuario *u){    
    if(g->qtdUsuarios == g->qtdUsuAlocados){
        g->qtdUsuAlocados+=2;
        g->usuarios = realloc(g->usuarios, g->qtdUsuAlocados * sizeof(Usuario*));
    }

    g->usuarios[g->qtdUsuarios] = u;
    g->qtdUsuarios++;
}

void insereTecnicoLista(Gerencia *g, Tecnico *t){   
    if(g->qtdTecnicos == g->qtdTecAlocados){
        g->qtdTecAlocados+=2;
        g->tecnicos = realloc(g->tecnicos, g->qtdTecAlocados * sizeof(Tecnico*));
    }

    g->tecnicos[g->qtdTecnicos] = t;
    g->qtdTecnicos++;
}

void desalocaGerencia(Gerencia *g){
    if(g != NULL){
        for(int i = 0; i < g->qtdUsuarios; i++){
            desalocaUsuario(g->usuarios[i]);
        }
        free(g->usuarios);

        for(int i = 0; i < g->qtdTecnicos; i++){
            desalocaTecnico(g->tecnico[i]);
        }
        free(g->tecnico);

        free(g);
    }
}

void imprimeBancoDeUsuarios(Gerencia *g){
    printf("----- BANCO DE USUARIOS -----\n");
    for(int i = 0 ; i < g->qtdUsuarios; i++){
        imprimeUsuario(g->usuarios[i]);
    }
    printf("----------------------------\n\n");
}

void imprimeBancoDeTecnicos(Gerencia *g){
    printf("----- BANCO DE TECNICOS -----\n");
    for(int i = 0 ; i < g->qtdTecnicos; i++){
        imprimeTecnico(g->tecnicos[i]);
    }
    printf("----------------------------\n\n");
}

int verificaCPFUsuario(Usuario* u, Gerencia* g){
    for(int i = 0; i < g->qtdUsuarios; i++){
        if(strcmp(getCPFUsuario(u), getCPFUsuario(g->usuarios[i])) == 0){
            return 0;
        }
    }
    return 1;
}

int verificaCPFTecnico(Tecnico* t, Gerencia* g){
    for(int i = 0; i < g->qtdTecnicos; i++){
        if(strcmp(getCPFTecnico(t), getCPFTecnico(g->tecnicos[i])) == 0){
            return 0;
        }
    }
    return 1;
}

char* getSetorUsuarioPorCPF(char* cpf, Gerencia *g){
    for(int i = 0; i < g->qtdUsuarios; i++){
        if(strcmp(getCPFUsuario(u), getCPFUsuario(g->usuarios[i])) == 0){
            return getSetorUsuario(g->usuarios[i]);
        }
    }
    return NULL;
}