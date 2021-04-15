#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Fila.h"

int main(){ 
    Aluno *a1 = IniciaAluno(1,"Maria",10.0);
    Aluno *a2 = IniciaAluno(2,"Patricia",10.0);
    Aluno *a3 = IniciaAluno(3,"Joao",8.5);
    Aluno *a4 = IniciaAluno(4,"Tiago",2.0);
    Aluno *a5 = IniciaAluno(5,"Ana",7.9);
    Aluno *a6 = IniciaAluno(6,"Amanda",9.0);

    Fila *f = iniciaFila();

    Fila *f2 = iniciaFila();

    // first in first out - FIFO

    printf("\nImprimindo a fila 1:\n\n");
    insereFila(f,a1);
    insereFila(f,a2);
    insereFila(f,a3);
    insereFila(f,a4);
    insereFila(f,a5);
    insereFila(f,a6);
    
    imprimeFila(f);


    printf("\nImprimindo a fila 2:\n\n");
    imprimeFila(f2);

   
    // Maria foi a primeira a entrar e a primeira a sair
    insereFila(f2, retiraFila(f));
    printf("\nImprimindo a fila 1:\n\n");
    imprimeFila(f);


    printf("\nImprimindo a fila 2:\n\n");
    imprimeFila(f2);
     
    // inserindo varios alunos da fila 1 na fila2
    printf("\nInserindo varios alunos da fila 1 na fila 2\n\n");

    insereFila(f2, retiraFila(f));
    insereFila(f2, retiraFila(f));
    insereFila(f2, retiraFila(f));
    insereFila(f2, retiraFila(f));
    printf("\nImprimindo a fila 1:\n\n");
    imprimeFila(f);


    printf("\nImprimindo a fila 2:\n\n");
    imprimeFila(f2);

    insereFila(f2, retiraFila(f));
    printf("\nImprimindo a fila 1:\n\n");
    imprimeFila(f);


    printf("\nImprimindo a fila 2:\n\n");
    imprimeFila(f2);
    

    printf("\nRetirando alunos da lista 2 e colocando na lista1\n");

    insereFila(f, retiraFila(f2));
    insereFila(f, retiraFila(f2));
    

    printf("\nImprimindo a fila 1:\n\n");
    imprimeFila(f);


    printf("\nImprimindo a fila 2:\n\n");
    imprimeFila(f2);

    //Liberando a memoria
    DestroiAluno(a1);
    DestroiAluno(a2);
    DestroiAluno(a3);
    DestroiAluno(a4);
    DestroiAluno(a5);
    DestroiAluno(a6);

    destroiFila(f);
    destroiFila(f2);
    
    //FIM

    return 0;
}