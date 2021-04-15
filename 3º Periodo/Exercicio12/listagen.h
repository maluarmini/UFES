#ifndef listagen_H_
#define listagen_H_

#include <stdio.h>

typedef struct listagen ListaGen;

//cria lista
ListaGen *criaLista();

//insere lista
ListaGen *insereLista(ListaGen *lista,void *item);

ListaGen *retiraLista(ListaGen *lista, int (*cb)(void *, void *), void *chave);

int percorreLista(ListaGen *lista, int (*cb)(void *, void *), void *dado);

void liberaLista(ListaGen *lista);

#endif 