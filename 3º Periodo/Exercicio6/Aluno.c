#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

struct aluno {
    int mat;
    char * nome;
    float cr;

};


Aluno * IniciaAluno(int mat, char * nome, float cr){
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    aluno->mat = mat;
    aluno->cr = cr;
    aluno->nome = strdup(nome);
    return aluno;
}

void ImprimeAluno(Aluno * al){
    printf("Nome: %s, Matricula: %d, CR: %.2f\n",al->nome,al->mat,al->cr);
}

int RetornaMat(Aluno *al){
    return al->mat;
}