#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manutencao.h"
#include "software.h"
#include "ticket.h"
#include "fila.h"
#include "outros.h"
#include "data.h"
#include "usuario.h"
#include "tecnico.h"
#include "pessoa.h"
#include "gerencia.h"



#define MAX_TAM_TIPO_TICKET 12

int main(){
    Gerencia* gerencia = criaGerencia();
    Fila* fila = criaFila();
    
    while(1){
        char comando;
        scanf("%c\n", &comando);


        if(comando == 'T'){
            Tecnico* t = lerTecnico();
            if(verificaCPFTecnico(t, gerencia)){
                insereTecnicoLista(gerencia, t);
            }
            desalocaTecnico(t);
        }

        if(comando == 'U'){
            Usuario* u = lerUsuario();
            if(verificaCPFUsuario(u, gerencia)){
                insereUsuarioLista(gerencia, u);
            }
            desalocaUsuario(u);
        }

        if(comando == 'A'){
            char cpfSolicitacao[MAX_TAM_CPF];
            scanf("%s\n", cpfSolicitacao);

            char tipoTicket[MAX_TAM_TIPO_TICKET];
            scanf("%s\n", tipoTicket);

            switch(tipoTicket){
                case "SOFTWARE":

                case "MANUTENCAO":

                case "OUTROS":
            }

            char setorSolicitacao[MAX_TAM_SETOR];
            if(getSetorUsuarioPorCPF(cpfSolicitacao, gerencia) != NULL){
                strcpy(setorSolicitacao, getSetorUsuarioPorCPF(cpfSolicitacao, gerencia));

            }


            

            

        }




    }

    return 0;
}