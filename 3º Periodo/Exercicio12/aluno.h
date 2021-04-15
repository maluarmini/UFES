#ifndef ALUNO_H
#define ALUNO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *IniciaAluno(int matricula, char *nome, float cr);

int RetornaMat(Aluno *aluno);

void ImprimeAluno(Aluno *aluno);

float RetornaCr(Aluno *aluno);

char *RetornaNome(Aluno *aluno);

void DestroiAluno(Aluno *aluno);

#endif 