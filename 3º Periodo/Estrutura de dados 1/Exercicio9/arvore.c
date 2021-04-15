#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Aluno.h"
#include "arvore.h"

struct arv{
    Aluno * info;
    struct arv * esq;
    struct arv * dir;
};

Arv * arv_criavazia(void){
    return NULL;
};

Arv *arv_cria(Aluno * al, Arv * e, Arv *d){
    Arv * p = (Arv *)malloc(sizeof(Arv));
    p->info = al;
    p->esq = e;
    p->dir = d;
    return p;
}

Arv * arv_libera(Arv * a){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_vazia(Arv *a){
    return a==NULL;
}

int arv_pertence(Arv *a, char * nome){
    if(arv_vazia(a)){
        return 0;
    }else{
        return !strcmp(RetornaNome(a->info),nome) || arv_pertence(a->esq,nome) || arv_pertence(a->dir,nome);
    }
}


void arv_imprime(Arv *a){
    printf("<");
    if(!arv_vazia(a)){
        ImprimeAluno(a->info);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");

}

//Arv * arv_pai(Arv * a, char * nome);

int folhas(Arv * a){
    if(arv_vazia(a->esq) && arv_vazia(a->dir))
        return 1;
    else if(!arv_vazia(a->esq) &&arv_vazia(a->dir))
        return folhas(a->esq);
    else if(arv_vazia(a->esq) && !arv_vazia(a->dir))
        return folhas(a->dir);
    return folhas(a->esq) + folhas(a->dir);
}

int ocorrencias(Arv * a,char *nome){
    if(arv_vazia(a))
        return 0;
        if(!strcmp(RetornaNome(a->info),nome))
            return (1 + ocorrencias (a->esq,nome) + ocorrencias(a->dir,nome));

            return (ocorrencias (a->esq, nome) + ocorrencias(a->dir,nome));
}

// maior caminho da raiz ate as folhas
int altura(Arv * a){
    if(a == NULL){
        return -1;
    }else{
        //altura esquerda
        int hesquerda = altura(a->esq);
        //altura direita
        int hdireita = altura(a->dir);
        //compara as duas
        if(hesquerda < hdireita){
            return hdireita+1;
        }else{
            return hesquerda+1;
        }
    }
}


Aluno* info (Arv *a){
    if(!arv_vazia(a)){
        return a->info;
    }
    return NULL;
}