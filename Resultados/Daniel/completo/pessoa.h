#ifndef _PESSOA_H
#define _PESSOA_H

#define MAX_TAM_NOME 100
#define MAX_TAM_CPF 15
#define MAX_TAM_TELEFONE 15
#define MAX_TAM_GENERO 10

#include "data.h"

/**
 * @brief Função de callback para imprimir uma pessoa
 * @param dado um tipo genérico para representar os tipos de pessoas.
 */
//typedef void (*func_ptr_imprime)(void *dado);

/**
 * @brief Função de callback para desalocar da memória uma implementação especifica de pessoa
 * @param dado um tipo genérico para representar os tipos de tickets.
 */
//typedef void (*func_ptr_desaloca_pessoa)(void *dado);

/**
 * Função de callback para retornar o tipo de uma pessoa
 * @param dado um tipo genérico para representar os tipos de pessoas.
 * @return tipo da pessoa
 */
//typedef char (*func_ptr_tipo_pessoa)();

typedef struct Pessoa Pessoa;

Pessoa *criaPessoa(char *nome, char *cpf, Data* data, char* telefone, char *genero);

Pessoa *lerPessoa();

char *getCPFPessoa(Pessoa *p);

Data* getDataNascimentoPessoa(Pessoa *p);

char* getNomePessoa(Pessoa *p);

void desalocaPessoa(Pessoa *doc);

void imprimePessoa(Pessoa *doc);



#endif