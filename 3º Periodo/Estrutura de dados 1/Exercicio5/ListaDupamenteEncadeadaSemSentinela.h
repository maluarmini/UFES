#ifndef ListaDpl_h
#define ListaDpl_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

typedef struct listadpl ListaDpl;

ListaDpl * IniciaLista();

ListaDpl * InsereLista (ListaDpl *lista, Matriz *mat);

ListaDpl * RetiraLista (ListaDpl *lista, int mat);

void imprimeLista (ListaDpl *lista);

void DestroiLista(ListaDpl *lista);

#endif