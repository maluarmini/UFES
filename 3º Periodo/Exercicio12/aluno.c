#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "aluno.h"

struct aluno
{
    char *nome;
    float cr;
    int matricula;
};

Aluno *IniciaAluno(int matricula, char *nome, float cr)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    aluno->cr = cr;
    aluno->matricula = matricula;
    aluno->nome = strdup(nome);
    return aluno;
}

void ImprimeAluno(Aluno *aluno)
{
    printf(" Matricula: %d, Nome: %s, Cr: %.2f\n", aluno->matricula, aluno->nome, aluno->cr);
}

int RetornaMat(Aluno *aluno)
{
    return aluno->matricula;
}

char *RetornaNome(Aluno *aluno)
{
    return aluno->nome;
}

float RetornaCr(Aluno *aluno)
{
    return aluno->cr;
}

void DestroiAluno(Aluno *aluno)
{
    if (aluno)
    {
        free(aluno->nome);
        free(aluno);
    }
}