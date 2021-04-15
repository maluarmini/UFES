#ifndef Arvore_h
#define Arvore_h

#include <stdio.h>
#include "Aluno.h"

typedef struct arv Arv;

Arv * arv_criavazia(void);

Arv *arv_cria(Aluno * al, Arv * e, Arv *d);

Arv * arv_libera(Arv * a);

int arv_vazia(Arv *a);

int arv_pertence(Arv *a, char * nome);

void arv_imprime(Arv *a);

//Arv * arv_pai(Arv * a, char * nome);

int folhas(Arv * a);

int ocorrencias(Arv * a,char *nome);

int altura(Arv * a);

Aluno* info (Arv *a);

#endif