#include "listaMat.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct cel Celula;

struct cel {
    Matriz *m; //Conteudo
    Celula *prox; //Ponteiro para encadear para proxima
};

struct lista{
    Celula *prim;
    Celula *ult;
};

Lista* IniciaLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void InsereLista (Lista* lista, Matriz* m){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->m = m;
    nova->prox = lista->prim;
    lista->prim = nova;

    if(lista->ult == NULL){ // Se a lista estava vazia
        lista->ult = nova;
    }
}

void ImprimeLista (Lista * lista){
    Celula *p;

    for(p = lista->prim; p != NULL; p = p->prox){
        imprimeMatriz(p->m);
    }

    
}

Matriz* RetiraLista (Lista* lista, int pos){
    Celula *p = lista->prim;
    Matriz * mat;
    Celula *ant = NULL;
    int cont=0;

    while(p != NULL && (cont != pos)){
        ant = p;
        p = p->prox;
        cont++;
    }


    mat = p->m;

    if(p == lista->prim && p == lista->ult){ //Era a unica célula da lista
        lista->prim = lista->ult = NULL;//lista fica vazia
    }else if(p == lista->prim){
        lista->prim = p->prox; //Era a primeira célula
    }else if(p == lista->ult){ //Era a ultima célula
        lista->ult = ant;
        lista->ult->prox = NULL;
    }else{ //Caso comum , retirar um célula do meio da lista
        ant->prox = p->prox;
    }

    free(p);

    return mat;

}

void DestroiLista (Lista *lista){ // Destroi a lista e libera o conteudo (Matriz);
    Celula *p = lista-> prim;
    Celula *t;


    //Liberando todas as células e conteudos;
    while(p != NULL){
        t = p->prox;
        destroiMatriz(p->m);
        free(p);
        p = t;
    }

    //Liberando a sentinela
    free(lista);
}

void DestroiListaSemDestruirOConteudo(Lista *lista){
    Celula * p = lista->prim;
    Celula *t;

    //Liberando as celulas mas assumindo que o cliente tem responsabilidade de usar a função destroiMatriz;
    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    
    free(lista);
}


