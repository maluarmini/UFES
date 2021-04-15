#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arv.h"

struct arv{
    struct arv * esq;
    struct arv * dir;
};

Arv * arv_criavazia(void){
    return NULL;
};

int arv_vazia(Arv *a){
    return a==NULL;
}

void arv_imprime(Arv *a){
    printf("<");
    if(!arv_vazia(a)){
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");

}
