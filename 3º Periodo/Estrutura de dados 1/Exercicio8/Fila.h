#ifndef FILA_H
#define FILA_H
#include "Aluno.h"

typedef struct fila Fila;

Fila * iniciaFila(void);

void insereFila(Fila * f, Aluno *al);

Aluno * retiraFila(Fila *f);

void imprimeFila(Fila * f);

void destroiFila(Fila *f);

#endif