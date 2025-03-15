#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "data.h"


struct Pessoa{
    /*func_ptr_imprime imprime;
    func_ptr_desaloca_pessoa desaloca;
    func_ptr_tipo_pessoa tipo;
    void* dado;*/
    char nome[MAX_TAM_NOME];
    char cpf[MAX_TAM_CPF];
    Data* dataNascimento;
    char telefone[MAX_TAM_TELEFONE];
    char genero[MAX_TAM_GENERO];
};


Pessoa *criaPessoa(char *nome, char *cpf, Data* data, char* telefone, char *genero /*void *dado, func_ptr_imprime imprime, func_ptr_tipo_pessoa tipo,func_ptr_desaloca_pessoa desaloca*/){
    
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    
    strcpy(p->cpf, cpf);
    strcpy(p->nome, nome);
    strcpy(p->telefone, telefone);
    strcpy(p->genero, genero);
    p->dataNascimento = data;
    /*p->tipo = tipo;
    p->imprime = imprime;
    p->desaloca = desaloca;
    p->dado = dado;*/

    return p;

}

Pessoa *lerPessoa(){
    Pessoa* p = (Pessoa*) malloc (sizeof(Pessoa));

    scanf("%[^\n]\n", p->nome);
    scanf("%[^\n]\n", p->cpf);
    p->dataNascimento = lerData();
    scanf("%[^\n]\n", p->telefone);
    scanf("%[^\n]\n", p->genero);

    return p;
}

/**
 * @brief Recupera o CPF da Pessoa
 * @param t Pessoa inicializada
 * @return CPF da Pessoa
 */
char *getCPFPessoa(Pessoa *p){
    return p->cpf;
}

Data* getDataNascimentoPessoa(Pessoa *p){
    return p->dataNascimento;
}

char* getNomePessoa(Pessoa *p){
    return p->nome;
}


/**
 * @brief  Desaloca um Pessoa da memória
 * @param doc estrutura do tipo Pessoa que deve ser liberada da memória
 */
void desalocaPessoa(Pessoa *doc){
    if(doc != NULL){
        /*free(doc->cpf);
        free(doc->id);
        free(doc->dado);*/
        desalocaData(doc->dataNascimento);
        //doc->desaloca(doc);
        free(doc);
    }
}

/**
 * @brief  Notifica (imprime) um Pessoa
 * @param doc Pessoa a ser notificado
 */
void imprimePessoa(Pessoa *doc){
    printf("--------------------\n");
    printf("- Nome: %s\n", doc->nome);
    printf("- CPF: %s\n", doc->cpf);
    printf("- Data de Nascimento: ");
    imprimeData(doc->dataNascimento);
    printf("- Telefone: %s\n", doc->telefone);
    printf("- Genero: %s\n", doc->genero);
}
