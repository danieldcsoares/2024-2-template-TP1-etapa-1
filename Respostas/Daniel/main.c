#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manutencao.h"
#include "software.h"
#include "ticket.h"
#include "fila.h"
#include "outros.h"
#include "data.h"

int main(){
    /*Manutencao* man;
    man = lerManutencao();
    setSetorUsuarioManutencao(man, "RH");
    setTempoEstimadoManutencao(man);
    notificaManutencao(man);
    desalocaManutencao(man);*/

    /*Outros* o = lerOutros();
    setTempoEstimadoOutros(o);
    notificaOutros(o);
    desalocaOutros(o);*/

    Data* d = lerData();
    imprimeData(d);
    desalocaData(d);

    return 0;
}