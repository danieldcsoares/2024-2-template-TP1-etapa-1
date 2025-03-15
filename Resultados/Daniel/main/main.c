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
#include "distribuicao.h"



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
        }

        if(comando == 'U'){
            Usuario* u = lerUsuario();
            if(verificaCPFUsuario(u, gerencia)){
                insereUsuarioLista(gerencia, u);
            }
        }

        if(comando == 'A'){
            char cpfSolicitacao[MAX_TAM_CPF];
            scanf("%[^\n]\n", cpfSolicitacao);

            char tipoTicket[MAX_TAM_TIPO_TICKET];
            scanf("%[^\n]\n", tipoTicket);

            char setorSolicitacao[MAX_TAM_SETOR] = "";
            /*if(getSetorUsuarioPorCPF(cpfSolicitacao, gerencia) != NULL){
                strcpy(setorSolicitacao, getSetorUsuarioPorCPF(cpfSolicitacao, gerencia));
            }*/
            char *setor = getSetorUsuarioPorCPF(cpfSolicitacao, gerencia);
            if(setor != NULL) {
                strcpy(setorSolicitacao, setor);
            }

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


            if(setor != NULL){
                insereTicketFila(fila, cpfSolicitacao, ticket, tempo, tipo, notifica, desaloca);
                atualizaTicketsSolicitados(gerencia, cpfSolicitacao, '+');
            }
            else {
                desaloca(ticket);
            }

        }

        if(comando == 'E'){
            char acao[20];
            scanf("%[^\n]\n", acao);

            if(strcmp(acao, "DISTRIBUI") == 0){
                Distribuicao *d = criaDistribuicao(gerencia,fila);
                distribuiTickets(d);
                desalocaDistribuicao(d);
            }

            if(strcmp(acao, "NOTIFICA") == 0){
                printf("----- FILA DE TICKETS -----\n");
                notificaFila(fila);
                printf("---------------------------\n\n");
            }

            if(strcmp(acao, "USUARIOS") == 0){
                imprimeBancoDeUsuarios(gerencia);
            }

            if(strcmp(acao, "TECNICOS") == 0){
                imprimeBancoDeTecnicos(gerencia);
            }

            if(strcmp(acao, "RANKING USUARIOS") == 0){
                imprimeRankingUsuarios(gerencia);
            }

            if(strcmp(acao, "RANKING TECNICOS") == 0){
                imprimeRankingTecnicos(gerencia);
            }

            if(strcmp(acao, "RELATORIO") == 0){
                imprimeRelatorio(gerencia, fila);
            }

        }


        if(comando == 'F'){
            desalocaGerencia(gerencia);
            desalocaFila(fila);
            break;
        }

    }

    return 0;
}