#include <stdio.h>
#include <stdlib.h>
#include "abb.h"
#include "Aluno.h"

struct arv{
    Aluno *info;
    Arv *esq;
    Arv *dir;
};

Arv * abb_cria (void){
    return NULL;
}

void abb_imprime (Arv *a){
    if(a != NULL){
        abb_imprime(a->esq);
        ImprimeAluno(a->info);
        abb_imprime(a->dir);
    }
}

Arv * abb_busca(Arv *r, int chave){
    if(r == NULL){
        return NULL;
    }else if(RetornaMat(r->info) > chave){
        return abb_busca(r->esq, chave);
    }else if(RetornaMat(r->info) < chave){
        return abb_busca(r->dir, chave);
    }else{
        return r;
    }
}

Arv * abb_insere(Arv *r, Aluno *al){
    if(r == NULL){
        r = (Arv *)malloc(sizeof(Arv));
        r->info = al;
        r->esq = r->dir = NULL;
    }else if(RetornaMat(al) < RetornaMat(r->info)){
        r->esq = abb_insere(r->esq, al);
    }else{
        r->dir = abb_insere(r->dir, al);
    }
    return r;
}

Arv * abb_retira(Arv * r, int v){
    if(r == NULL)
        return NULL;
    else if(RetornaMat(r->info) > v)
        r->esq = abb_retira(r->esq, v);
    else if(RetornaMat(r->info) < v)
        r->dir = abb_retira(r->dir, v);
    else{
        if(r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }else if(r->esq == NULL){
            Arv * t = r;
            r = r->dir;
            free(t);
        }else if(r->dir == NULL){
            Arv *t = r;
            r=r->esq;
            free(t);
        }else{
            Arv *f = r->esq;
            while(f->dir != NULL){
                f = f->dir;
            } 
            Aluno *t = r->info;
            r->info = f->info;
            f->info = t;
            r->esq = abb_retira(r->esq,v);
        }
    }
    return r;
}

Arv * abb_libera (Arv* a){
    if(a != NULL){
        //libera toda a parte da esquerda.
        abb_libera(a->esq);
        //depois direita
        abb_libera(a->dir);
        //e por fim destroi a arvore por completo
        free(a);
    }
    return NULL;
}