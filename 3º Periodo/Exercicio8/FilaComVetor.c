#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Aluno.h"

#define TAM 10

struct fila{
    int ini;
    int n;
    Aluno * alunos[TAM];    
};

Fila * iniciaFila(void){
    Fila * f = (Fila *)malloc(sizeof(Fila));
    f->ini = 0;
    f->n = 0;
    return f;
}

// insere sempre no final da fila

void insereFila(Fila * f, Aluno *al){
    if(!f || f->n >= TAM ||!al){
        printf("\nFila cheia ou invalida!\n");
        return;
    }
    //encontrar o final da fila
    int pos = (f->ini + f->n)%TAM;
    f->alunos[pos] = al;
    f->n++;
}

Aluno * retiraFila(Fila *f){
    if(!f || f->n == 0){
        printf("\nFila vazia ou invalida!\n");
        return NULL; 
    }


    Aluno *al = f->alunos[f->ini];
    f->ini = (f->ini+1)%TAM;
    f->n--;
    return al;
}

void imprimeFila(Fila * f){
    int pos = 0;
    if(!f){
        return;
    }
    for(int i=0; i<f->n;i++){
        pos = (f->ini+i)%TAM;
        ImprimeAluno(f->alunos[pos]);
    }
}

void destroiFila(Fila *f){
    if(!f){
        return;
    }

    free(f);
}