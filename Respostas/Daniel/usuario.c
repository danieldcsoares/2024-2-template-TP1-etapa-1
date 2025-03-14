#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "usuario.h"
#include "pessoa.h"

struct Usuario{
    /*char* nome;
    char* cpf;
    Data* dataNascimento;
    char* telefone;
    char* genero;*/
    char setor[MAX_TAM_SETOR];
    int ticketsSolicitados;
    Pessoa* pessoa;
};


Usuario *criaUsuario(char *nome, char *cpf, Data *dataNascimento, char *telefone, char *genero, char *setor){
    Usuario* u = (Usuario*) malloc (sizeof(Usuario));

    /*strcpy(u->nome, nome);
    strcpy(u->cpf, cpf);
    u->dataNascimento = dataNascimento;
    strcpy(u->telefone, telefone);
    strcpy(u->genero, genero);*/

    u->pessoa = criaPessoa(nome,cpf,dataNascimento,telefone,genero);
    strcpy(u->setor, setor);

    u->ticketsSolicitados = 0;

    return u;
}


Usuario *lerUsuario(){
    Usuario* u = (Usuario*) malloc (sizeof(Usuario));
    /*u->nome = (char*) malloc(sizeof(char) * MAX_TAM_NOME_USUARIO);
    u->cpf = (char*) malloc(sizeof(char) * MAX_TAM_CPF);
    u->telefone = (char*) malloc(sizeof(char) * MAX_TAM_TELEFONE);
    u->genero = (char*) malloc(sizeof(char) * MAX_TAM_GENERO);
    u->setor = (char*) malloc(sizeof(char) * MAX_TAM_SETOR);*/

    /*scanf("%[^\n]\n", u->nome);
    scanf("%[^\n]\n", u->cpf);
    u->dataNascimento = lerData();
    scanf("%[^\n]\n", u->telefone);
    scanf("%[^\n]\n", u->genero);*/

    u->pessoa = lerPessoa();

    scanf("%[^\n]\n", u->setor);

    u->ticketsSolicitados = 0;

    return u;
}


char* getSetorUsuario(Usuario *u){
    return u->setor;
}


void incrementaTicketsSolicitados(Usuario *u){
    u->ticketsSolicitados++;
}


char getTipoUsuario(){
    return 'U';
}

char* getCPFUsuario(Usuario *u){
    return u->cpf;
}

void desalocaUsuario(void *u){
    if(u != NULL){
        Usuario* usuario = (Usuario*) u;
        //free(usuario->nome);
        //free(usuario->cpf);
        //desalocaData(usuario->dataNascimento);
        //free(usuario->telefone);
        //free(usuario->genero);
        //free(usuario->setor);

        desalocaPessoa(usuario->pessoa);
        free(usuario);
    }
}


void imprimeUsuario(void *usuario){
    Usuario* u = (Usuario*) usuario;

    /*printf("- Nome: %s\n", u->nome);
    printf("- CPF: %s\n", u->cpf);
    printf("- Data de Nascimento: ");
    imprimeData(u->dataNascimento);
    printf("- Telefone: %s\n", u->telefone);
    printf("- Genero: %s\n", u->genero);*/

    imprimePessoa(u->pessoa);

    printf("- Setor: %s\n", u->setor);
    printf("- Tickets solicitados: %d\n", u->ticketsSolicitados);
}




