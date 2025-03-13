#ifndef _MANUTENCAO_H
#define _MANUTENCAO_H

#define MAX_TAM_NOME_MANUTENCAO 100
#define MAX_TAM_LOCAL_MANUTENCAO 100
#define MAX_TAM_ESTADO 10
#define MAX_TAM_SETOR 12

/**
 * Estrutura de um Ticket Manutencao contendo os parametros especificos de um ticket do tipo Manutencao
 */
typedef struct Manutencao Manutencao;

/**
 * @brief Aloca uma estrutura Manutencao na memória e inicializa os parâmetro necessários
 * @param nome Nome da Manutencao
 * @param local Local da Manutencao
 * @param estado 
 * @return  Uma estrutura Manutencao inicializada.
 */
Manutencao *criaManutencao(char *nome, char *local, char* estado);

/**
 * @brief Lê da entrada padrão um  ticket do TIPO Manutencao
 * @return  Um chamado do Tipo Manutencao
 */
Manutencao *lerManutencao();

void setSetorUsuarioManutencao(Manutencao *m, char *setor);

/**
 * @brief  Calcula o tempo estimado para resolver um ticket do tipo Manutencao.
 * Tempo estimado depende da categoria e impacto
 * @param s  Ticket do tipo Manutencao
 */
void setTempoEstimadoManutencao(Manutencao *m);

/**
 * @brief  Retorna o tempo estimado para resolver um ticket do tipo Manutencao.
 * @param dado  Ticket do tipo Manutencao
 * @return  Tempo estimado para resolver um ticket do tipo Manutencao
 */
int getTempoEstimadoManutencao(void *dado);

/**
 * @brief  Retorna o tipo do ticket
 * @return  'S' para Manutencao
 */
char getTipoManutencao();

/**
 * @brief  Desaloca um ticket do tipo Manutencao da memória
 * @param s  Ticket do tipo Manutencao
 */
void desalocaManutencao(void *m);

/**
 * @brief  Imprime um ticket do tipo Manutencao
 * @param dado  Ticket do tipo Manutencao
 */
void notificaManutencao(void *dado);




#endif