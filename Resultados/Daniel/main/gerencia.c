#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "tecnico.h"
#include "pessoa.h"
#include "usuario.h"
#include "gerencia.h"

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
            desalocaTecnico(g->tecnicos[i]);
        }
        free(g->tecnicos);

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
        if(strcmp(cpf, getCPFUsuario(g->usuarios[i])) == 0){
            return getSetorUsuario(g->usuarios[i]);
        }
    }
    return NULL;
}

int getQtdTecnicos(Gerencia *g){
    return g->qtdTecnicos;
}

int getQtdUsuarios(Gerencia *g){
    return g->qtdUsuarios;
}

Tecnico* getTecnicoNaLista(Gerencia *g, int i){
    return g->tecnicos[i];
}

int comparaTempoTrabalhado(const void *a, const void *b) {
    const Tecnico* tecA = *(const Tecnico**) a;
    const Tecnico* tecB = *(const Tecnico**) b;

    int tempoB = getTempoTrabalhadoTecnico((Tecnico*)tecB);
    int tempoA = getTempoTrabalhadoTecnico((Tecnico*)tecA);

    if(tempoB > tempoA){
        return 1;
    }
    else{
        if(tempoA > tempoB){
            return -1;
        }
        else{
            return strcmp(getNomeTecnico(tecA), getNomeTecnico(tecB));
        }
    }
    

    //return getTempoTrabalhadoTecnico((Tecnico*)tecB) - getTempoTrabalhadoTecnico((Tecnico*)tecA);
}

int comparaNumeroTicketsAbertos(const void *a, const void *b) {
    const Usuario* usuA = *(const Usuario**) a;
    const Usuario* usuB = *(const Usuario**) b;

    int numB = getQtdTicketsUsuario((Usuario*)usuB);
    int numA = getQtdTicketsUsuario((Usuario*)usuA);

    if(numB > numA){
        return 1;
    }
    else{
        if(numA > numB){
            return -1;
        }
        else{
            return strcmp(getNomeUsuario(usuA), getNomeUsuario(usuB));
        }
    }

    //return getQtdTicketsUsuario((Usuario*)usuB) - getQtdTicketsUsuario((Usuario*)usuA);
}



void imprimeRankingTecnicos(Gerencia *g){
    Tecnico** copiaTecnicos = (Tecnico**)malloc(g->qtdTecnicos * sizeof(Tecnico*));
    
    // Copiar os dados do array original para a cópia
    for(int i = 0; i < g->qtdTecnicos; i++){
        copiaTecnicos[i] = g->tecnicos[i];
    }
    
    // Ordenar a cópia pelo tempo trabalhado
    qsort(copiaTecnicos, g->qtdTecnicos, sizeof(Tecnico*), comparaTempoTrabalhado);
    
    // Imprimir os técnicos ordenados
    printf("----- RANKING DE TECNICOS -----\n");

    for(int i = 0; i < g->qtdTecnicos; i++){
        imprimeTecnico(copiaTecnicos[i]);
    }

    printf("-------------------------------\n\n");
    
    // Liberar a memória da cópia
    free(copiaTecnicos);
}

void imprimeRankingUsuarios(Gerencia *g){
    Usuario** copiaUsuarios = (Usuario**)malloc(g->qtdUsuarios * sizeof(Usuario*));
    
    // Copiar os dados do array original para a cópia
    for(int i = 0; i < g->qtdUsuarios; i++){
        copiaUsuarios[i] = g->usuarios[i];
    }
    
    // Ordenar a cópia pelo tempo trabalhado
    qsort(copiaUsuarios, g->qtdUsuarios, sizeof(Usuario*), comparaNumeroTicketsAbertos);
    
    // Imprimir os técnicos ordenados
    printf("----- RANKING DE USUARIOS -----\n");

    for(int i = 0; i < g->qtdUsuarios; i++){
        imprimeUsuario(copiaUsuarios[i]);
    }

    printf("-------------------------------\n\n");
    
    // Liberar a memória da cópia
    free(copiaUsuarios);
}

void atualizaTicketsSolicitados(Gerencia *g, char *cpfSol, char sinal){
    for(int i = 0; i < g->qtdUsuarios; i++){
        if(strcmp(cpfSol, getCPFUsuario(g->usuarios[i])) == 0){
            if(sinal == '+'){
                incrementaTicketsSolicitados(g->usuarios[i]);
            }
        
            if(sinal == '-'){
                diminuiTicketsSolicitados(g->usuarios[i]);
            }
        }
    }
}


int calculaMediaIdadeUsuarios(Gerencia *g){
    float soma = 0;
    for(int i = 0; i < g->qtdUsuarios; i++){
        Data* d = criarData(DIA_BASE, MES_BASE, ANO_BASE);
        Data* nasc = getDataNascimentoUsuario(g->usuarios[i]);

        soma = soma + calcularDiffAnosData(nasc, d);
        desalocaData(d);
    }

    float media = soma / g->qtdUsuarios;

    return ((int) media);
}

int calculaMediaIdadeTecnicos(Gerencia *g){
    float soma = 0;
    for(int i = 0; i < g->qtdTecnicos; i++){
        Data* d = criarData(DIA_BASE, MES_BASE, ANO_BASE);
        Data* nasc = getDataNascimentoTecnico(g->tecnicos[i]);

        soma = soma + calcularDiffAnosData(nasc, d);
        desalocaData(d);
    }

    float media = soma / g->qtdTecnicos;

    return ((int) media);
}

int calculaMediaTrabalhoTecnicos(Gerencia *g){
    float soma = 0;
    for(int i = 0; i < g->qtdTecnicos; i++){
        soma = soma + getTempoTrabalhadoTecnico(g->tecnicos[i]);
    }

    float media = soma / g->qtdTecnicos;

    return ((int) media);
}


void imprimeRelatorio(Gerencia *g, Fila *f){
    printf("----- RELATORIO GERAL -----\n");
    
    int numTickets = getQtdTicketsNaFila(f);
    printf("- Qtd tickets: %d\n", numTickets);

    int numTicketsAbertos = getQtdTicketsPorStatusNaFila(f, 'A');
    printf("- Qtd tickets (A): %d\n", numTicketsAbertos);

    int numTicketsFinalizados = getQtdTicketsPorStatusNaFila(f, 'F');
    printf("- Qtd tickets (F): %d\n", numTicketsFinalizados);

    int numUsuarios = getQtdUsuarios(g);
    printf("- Qtd usuarios: %d\n", numUsuarios);

    int mediaIdadeUsuarios = calculaMediaIdadeUsuarios(g);
    printf("- Md idade usuarios: %d\n", mediaIdadeUsuarios);

    int numTecnicos = getQtdTecnicos(g);
    printf("- Qtd tecnicos: %d\n", numTecnicos);

    int mediaIdadeTecnicos = calculaMediaIdadeTecnicos(g);
    printf("- Md idade tecnicos: %d\n", mediaIdadeTecnicos);

    int mediaTrabalhoTecnicos = calculaMediaTrabalhoTecnicos(g);
    printf("- Md trabalho tecnicos: %d\n", mediaTrabalhoTecnicos);
    
    printf("---------------------------\n");

}
