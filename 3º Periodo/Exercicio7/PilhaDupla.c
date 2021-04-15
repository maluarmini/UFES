#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"
#define tam 100

typedef int TipoItem;

// Pilha de numeros inteiros, os pares vão para um lado e os impares para outro

typedef struct{
    int Topo,Base;
}IndicePilha;

struct tipopilhadupla{
    int Item[tam];
    IndicePilha Pilha1,Pilha2;
};

TipoPilhaDupla * IniciaPilha(void){
    TipoPilhaDupla * p = (TipoPilhaDupla*)malloc(sizeof(TipoPilhaDupla));
    p->Pilha1.Base = 0;
    p->Pilha1.Topo = -1;
    p->Pilha2.Base = tam-1;
    p->Pilha2.Topo = tam;
    return p;
}

void push (TipoPilhaDupla * pilha, int item){
    if(!pilha || pilha->Pilha1.Topo == pilha->Pilha2.Topo-1){
        printf("\nPilha cheia.\n");
        return;
    }
    if(item % 2 == 0){
        pilha->Item[pilha->Pilha1.Topo+1] = item;
        pilha->Pilha1.Topo++;
    }else{
        pilha->Item[pilha->Pilha2.Topo-1] = item;
        pilha->Pilha2.Topo--;
    }
}

int pop(TipoPilhaDupla * pilha){
    int num;
    if(!pilha || (pilha->Pilha1.Topo==-1 && pilha->Pilha2.Topo==tam)){
        printf("\nPilha vazia\n");
        return -0;
    }
    if(pilha->Pilha1.Topo != -1){
        num = pilha->Item[pilha->Pilha1.Topo+1];
        pilha->Pilha1.Topo--;
        return num;
    }
    if(pilha->Pilha1.Topo == -1){
        num = pilha->Item[pilha->Pilha2.Topo-1];
        pilha->Pilha2.Topo++;
    }
    return num;
}

void imprime(TipoPilhaDupla * pilha){
    int i=0;
    if(!pilha){
        return;
    }
    printf("\nPILHA 1 - Pares\n");
    for(i=(pilha->Pilha1.Topo);i>=0;i--){
        printf("%d ", pilha->Item[i]);
    }
    printf("\nPILHA 2- Impares\n");
    for(i=(pilha->Pilha2.Topo);i<=pilha->Pilha2.Base;i++){
        printf("%d ", pilha->Item[i]);
    }
}

//Destroi a pilha;
void destroi(TipoPilhaDupla * pilha){
    if(!pilha){
        return;
    }
    free(pilha);
}