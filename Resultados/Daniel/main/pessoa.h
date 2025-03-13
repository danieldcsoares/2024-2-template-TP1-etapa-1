#ifndef _PESSOA_H
#define _PESSOA_H

/**
 * @brief Função de callback para imprimir uma pessoa
 * @param dado um tipo genérico para representar os tipos de pessoas.
 */
typedef void (*func_ptr_imprime)(void *dado);

/**
 * @brief Função de callback para desalocar da memória uma implementação especifica de pessoa
 * @param dado um tipo genérico para representar os tipos de tickets.
 */
typedef void (*func_ptr_desaloca_pessoa)(void *dado);

/**
 * Função de callback para retornar o tipo de uma pessoa
 * @param dado um tipo genérico para representar os tipos de pessoas.
 * @return tipo da pessoa
 */
typedef char (*func_ptr_tipo_pessoa)();



typedef struct Pessoa Pessoa;




#endif