#ifndef listaaluno_h
#define listaaluno_h

#include <stdio.h>
#include "listagen.h"
#include "aluno.h"

ListaGen *retiraAluno(ListaGen *lista, int matricula);

int pertenceAluno(ListaGen *lista, int matricula);

void imprimeListaAlunos(ListaGen *lista);

float mediaTurma(ListaGen *lista);

#endif 