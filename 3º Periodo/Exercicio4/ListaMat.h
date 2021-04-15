#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include <stdio.h>
#include "matriz.h"


typedef struct lista Lista;

Lista* IniciaLista();

void InsereLista (Lista* lista, Matriz* m);

void ImprimeLista (Lista * lista);

Matriz* RetiraLista (Lista* lista, int pos);

void DestroiLista (Lista *lista);
//Destroi a Lista e o seu conteudo (Matrizes);

void DestroiListaSemDestruirOConteudo(Lista *lista);  
/* 
Assumindo que o cliente tem responsabilidade
de destuir as matrizes 
*/

#endif