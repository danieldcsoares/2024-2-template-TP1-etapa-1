#include <stdio.h>
#include "data.h"
#include <stdlib.h>

struct Data{
    int dia;
    int mes;
    int ano;
};


Data *lerData(){
    Data* d = (Data*) malloc(sizeof(Data));
    scanf("%d/%d/%d\n", &d->dia,&d->mes,&d->ano);
    return d;
}

void imprimeData(Data *d){
    printf("%d/%d/%d\n", d->dia,d->mes,d->ano);
}

int comparaData(Data *d1, Data *d2){
    return (d1->dia == d2->dia && d1->mes == d2->mes && d1->ano == d2->ano);
}

int calcularDiffAnosData(Data *inicio, Data *fim){
    if(inicio->mes > fim->mes){
        return (fim->ano - inicio->ano - 1);
    }
    else{
        if(inicio->mes < fim->mes){
            return (fim->ano - inicio->ano);
        }
        else{
            if(inicio->dia < fim->dia){
                return (fim->ano - inicio->ano - 1);
            }
            else{
                return (fim->ano - inicio->ano);
            }
        }
    }
}

void desalocaData(Data* d){
    if(d != NULL){
        free(d);
    }
}