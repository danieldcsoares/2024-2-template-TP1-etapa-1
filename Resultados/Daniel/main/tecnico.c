#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "tecnico.h"
#include "pessoa.h"

struct Tecnico{
    /*char* nome;
    char* cpf;
    Data* dataNascimento;
    char* telefone;
    char* genero;*/
    char area[MAX_TAM_AREA];
    float salario;
    int disponibilidade;
    int tempoTrabalhado;
    Pessoa* pessoa;
};


Tecnico *criaTecnico(char *nome, char *cpf, Data *dataNascimento, char *telefone, char *genero, char *area, float salario, int disponibilidade){
    Tecnico* t = (Tecnico*) malloc (sizeof(Tecnico));

    /*strcpy(t->nome, nome);
    strcpy(t->cpf, cpf);
    t->dataNascimento = dataNascimento;
    strcpy(t->telefone, telefone);
    strcpy(t->genero, genero);*/

    t->pessoa = criaPessoa(nome,cpf,dataNascimento,telefone,genero);
    strcpy(t->area, area);

    t->salario = salario;
    t->disponibilidade = disponibilidade;

    t->tempoTrabalhado = 0;

    return t;
}

Tecnico *lerTecnico(){
    Tecnico* t = (Tecnico*) malloc (sizeof(Tecnico));
    /*t->nome = (char*) malloc(sizeof(char) * MAX_TAM_NOME_TECNICO);
    t->cpf = (char*) malloc(sizeof(char) * MAX_TAM_CPF);
    t->telefone = (char*) malloc(sizeof(char) * MAX_TAM_TELEFONE);
    t->genero = (char*) malloc(sizeof(char) * MAX_TAM_GENERO);
    t->area = (char*) malloc(sizeof(char) * MAX_TAM_AREA);*/

    /*scanf("%[^\n]\n", t->nome);
    scanf("%[^\n]\n", t->cpf);
    t->dataNascimento = lerData();
    scanf("%[^\n]\n", t->telefone);
    scanf("%[^\n]\n", t->genero);*/

    t->pessoa = lerPessoa();

    scanf("%[^\n]\n", t->area);
    scanf("%d\n", &t->disponibilidade);
    scanf("%f\n", &t->salario);

    t->tempoTrabalhado = 0;

    return t;
}

char* getAreaTecnico(Tecnico *t){
    return t->area;
}

void incrementaTempoTrabalhado(Tecnico *t, int tempo){
    t->tempoTrabalhado += tempo;
}

void diminuiDisponibilidade(Tecnico *t, int tempo){
    t->disponibilidade -= tempo;
}

int getTempoTrabalhadoTecnico(Tecnico *t){
    return t->tempoTrabalhado;
}

Data* getDataNascimentoTecnico(Tecnico *t){
    return getDataNascimentoPessoa(t->pessoa);
}

char getTipoTecnico(){
    return 'T';
}

char* getCPFTecnico(Tecnico *t){
    return getCPFPessoa(t->pessoa);
}

int getDisponibilidadeTecnico(Tecnico *t){
    return t->disponibilidade;
}

char* getNomeTecnico(Tecnico *t){
    return getNomePessoa(t->pessoa);
}

void desalocaTecnico(void *t){
    if(t != NULL){
        Tecnico* tec = (Tecnico*) t;
        /*free(tec->nome);
        free(tec->cpf);*/
        //desalocaData(tec->dataNascimento);
        /*free(tec->telefone);
        free(tec->genero);
        free(tec->area);*/

        desalocaPessoa(tec->pessoa);
        free(tec);
    }
}

void imprimeTecnico(void *t){
    Tecnico* tec = (Tecnico*) t;

    /*printf("- Nome: %s\n", tec->nome);
    printf("- CPF: %s\n", tec->cpf);
    printf("- Data de Nascimento: ");
    imprimeData(tec->dataNascimento);
    printf("- Telefone: %s\n", tec->telefone);
    printf("- Genero: %s\n", tec->genero);*/

    imprimePessoa(tec->pessoa);

    printf("- Area de Atuacao: %s\n", tec->area);
    printf("- Salario: %.2f\n", tec->salario);
    printf("- Disponibilidade: %dh\n", tec->disponibilidade);
    printf("- Tempo Trabalhado: %dh\n", tec->tempoTrabalhado);
}