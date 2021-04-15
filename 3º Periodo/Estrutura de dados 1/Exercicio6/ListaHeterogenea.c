#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"
#include "Professor.h"
#include "ListaHeterogenea.h"

#define PROF 0
#define ALUNO 1


typedef struct cel Celula;
struct cel {
    Celula * prox;
    void * conteudo;
    int tipo;
};
struct listaheterogenea{
    Celula*prim;
    Celula * ult;
};

ListaHeterogenea* IniciaListaHeterogenea(){
    ListaHeterogenea *lista = (ListaHeterogenea*)malloc(sizeof(ListaHeterogenea));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void InsereAlunoListaHeterogenea (ListaHeterogenea* lista, Aluno *al){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->conteudo = al;
    nova->tipo = ALUNO;
    nova->prox = lista->prim;
    lista->prim = nova;
    if(lista->ult == NULL){ // Se a lista estava vazia
        lista->ult = nova;
    }
}
void InsereProfessorListaHeterogenea (ListaHeterogenea* lista, Professor *professor){
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->conteudo = professor;
    nova->tipo = PROF;
    nova->prox = lista->prim;
    lista->prim = nova;
    if(lista->ult == NULL){ // Se a lista estava vazia
        lista->ult = nova;
    }
}

void ImprimeListaHeterogenea (ListaHeterogenea * lista){
    Celula *p;

    for(p = lista->prim; p != NULL; p = p->prox){
        if(p->tipo == ALUNO){
            ImprimeAluno(p->conteudo);
        }else if(p->tipo == PROF){
            ImprimeProfessor(p->conteudo);
        }
    }
}

Aluno* RetiraAlunoListaHeterogenea (ListaHeterogenea* lista, char * nome){
    Celula *p = lista->prim;
    Aluno * al;
    Celula *ant = NULL;
    int cont=0;

    while(p != NULL && strcmp(RetornaNome(p->conteudo),nome)){
        ant = p;
        p = p->prox;
        cont++;
    }

    al = p->conteudo;

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

    return al;

}
Professor* RetiraProfessorListaHeterogenea (ListaHeterogenea* lista, char * nome){
    Celula *p = lista->prim;
    Professor * prof;
    Celula *ant = NULL;
    int cont=0;

    while(p != NULL && strcmp(RetornaNomeProf(p->conteudo),nome)){
        ant = p;
        p = p->prox;
        cont++;
    }

    prof = p->conteudo;

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

    return prof;
}

float ValorDoChurrasco (ListaHeterogenea * lista){
    Celula *p = lista->prim;
    float valor = 0.0;

    while(p != NULL){
        if(p->tipo == PROF){
            valor += 0.02*RetornaSalario(p->conteudo);
        }else if(p->tipo == ALUNO){
            valor += 30.0; 
        }
        p = p->prox;
    }
    return valor;
}

void DestroiListaHeterogenea (ListaHeterogenea *lista){
    // sem destruir o conteúdo, a responsabilidade fica para o cliente
    Celula *p = lista->prim;
    Celula *t;

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}