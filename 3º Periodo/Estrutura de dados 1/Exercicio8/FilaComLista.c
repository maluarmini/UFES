#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ListaComSentinela.h"

struct fila{
    Lista *lista;
};


Fila * iniciaFila(void){
    Fila * f = (Fila *)malloc(sizeof(Fila));
    f->lista = IniciaLista();
    return f;
}

void insereFila(Fila * f, Aluno *al){
    InsereLista(f->lista,al);
}

Aluno * retiraFila(Fila *f){
    return RetiraLista(f->lista,0);
}

void imprimeFila(Fila * f){
    ImprimeLista(f->lista);
}

void destroiFila(Fila *f){
    DestroiLista(f->lista);
    free(f);
}