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

            char setorSolicitacao[MAX_TAM_SETOR];
            strcpy(setorSolicitacao, getSetorUsuarioPorCPF(cpfSolicitacao, gerencia));

            void* ticket = NULL;
            func_ptr_tempoEstimado tempo = NULL;
            func_ptr_tipo tipo = NULL;
            func_ptr_notifica notifica = NULL;
            func_ptr_desaloca desaloca = NULL;


            if(strcmp(tipoTicket, "SOFTWARE") == 0){
                ticket = lerSoftware();
                setTempoEstimadoSoftware(ticket);
                tempo = getTempoEstimadoSoftware;
                tipo = getTipoSoftware;
                notifica = notificaSoftware;
                desaloca = desalocaSoftware;
            }

            if(strcmp(tipoTicket, "MANUTENCAO") == 0){
                ticket = lerManutencao();
                setTempoEstimadoManutencao(ticket);
                setSetorUsuarioManutencao(ticket, setorSolicitacao);
                tempo = getTempoEstimadoManutencao;
                tipo = getTipoManutencao;
                notifica = notificaManutencao;
                desaloca = desalocaManutencao;
            }

            if(strcmp(tipoTicket, "OUTROS") == 0){
                ticket = lerOutros();
                setTempoEstimadoOutros(ticket);
                tempo = getTempoEstimadoOutros;
                tipo = getTipoOutros;
                notifica = notificaOutros;
                desaloca = desalocaOutros;
            }


            if(getSetorUsuarioPorCPF(cpfSolicitacao, gerencia) != NULL){
                insereTicketFila(fila, cpfSolicitacao, ticket, tempo, tipo, notifica, desaloca);
            }
            
            printf("pronto\n");

            //SE DER PROBLEMA DE VALGRIND, DESALOCAR TICKET
        }

        if(comando == 'E'){
            char acao[20];
            scanf("%[^\n]\n", acao);


        }




    }

    return 0;
}