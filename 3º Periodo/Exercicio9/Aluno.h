#ifndef Aluno_h
#define Aluno_h

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

Aluno * IniciaAluno(int mat, char * nome, float cr);

void ImprimeAluno(Aluno * al);

int RetornaMat(Aluno *al);

char* RetornaNome(Aluno *al);

float RetornaCr(Aluno *al);

void DestroiAluno(Aluno *al);


#endif