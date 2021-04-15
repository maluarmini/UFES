#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "ListaDuplamenteEncadeadaSemSentinela.h"

struct listadpl {
    Matriz *mat;
    ListaDpl * prox;
    ListaDpl * ant;
};

ListaDpl * IniciaLista(){
    return NULL;
}

ListaDpl * InsereLista (ListaDpl *lista, Matriz *mat){
    ListaDpl * nova = (ListaDpl *)malloc(sizeof(ListaDpl));

    nova->mat = mat;
    nova->ant = NULL;
    nova->prox = lista;//encadeamento pra direita
    
    if(lista != NULL){ //encadeamento para a esquerda
        lista->ant = nova;
    }
    return nova;

}

ListaDpl * RetiraLista (ListaDpl *lista, int pos){
    ListaDpl *p;
    int cont = 0;
    p = lista;
    //Encontrar quem eu quero retirar pela chave de busca (Matricula)
    while(p != NULL && (cont != pos)){
        p->ant = p;
        p = p->prox;
        cont++;
    }

    if(p == NULL){ //Não achou ou a lista é vazia
        return lista;//retorna a lista inalterada
    }

    //Possibilidades do retira a serem analisadas;
    if(lista == p){//primeiro
        lista = p->prox;
    }else{
        p->ant->prox = p->prox;
    }

    if(p->prox != NULL){ //Não é a ultima
        p->prox->ant = p->ant;
    }else{
        p->ant->prox = NULL;  
    }

    free(p);

    return lista; //retornando o novo endereço da lista;
}

void imprimeLista (ListaDpl *lista){
    ListaDpl * p;
    for(p = lista; p != NULL; p = p->prox){
        imprimeMatriz(p->mat);
    }
}

void DestroiLista(ListaDpl *lista){
    /*
        Função destroi que não destoi as matrizes, assumindo que o cliente
        terá a responsabilidade de destruir as matrizes!
    */
    ListaDpl *p = lista;
    ListaDpl *t;
    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
}