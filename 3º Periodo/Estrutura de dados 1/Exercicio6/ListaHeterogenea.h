#ifndef listaheterogenea_h
#define listaheterogenea_h

#include <stdio.h>
#include <stdlib.h>
#include "Professor.h"
#include "Aluno.h"

typedef struct listaheterogenea ListaHeterogenea;

ListaHeterogenea* IniciaListaHeterogenea();

void InsereAlunoListaHeterogenea (ListaHeterogenea* lista, Aluno *al);
void InsereProfessorListaHeterogenea (ListaHeterogenea* lista, Professor *professor);

void ImprimeListaHeterogenea (ListaHeterogenea * lista);

Aluno* RetiraAlunoListaHeterogenea (ListaHeterogenea* lista, char * nome);
Professor* RetiraProfessorListaHeterogenea (ListaHeterogenea* lista, char * nome);

float ValorDoChurrasco (ListaHeterogenea * lista);

void DestroiListaHeterogenea (ListaHeterogenea *lista);

#endif