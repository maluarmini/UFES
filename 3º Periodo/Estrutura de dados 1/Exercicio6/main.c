#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"
#include "Professor.h"
#include "ListaHeterogenea.h"

int main(){
    Aluno *a1 = IniciaAluno(1,"Maria", 10);
    Aluno *a2 = IniciaAluno(2,"Luana", 9);
    Aluno *a3 = IniciaAluno(3,"Tiago", 3);
    Aluno *a4 = IniciaAluno(4,"Patricia", 10);
    Aluno *a5 = IniciaAluno(5,"Claudio", 9.5);
    Professor *p1 = IniciaProfessor(123,"Roberto",9599.0);
    Professor *p2 = IniciaProfessor(456,"Ana",12599.0);

    ListaHeterogenea * lista = IniciaListaHeterogenea();

    InsereAlunoListaHeterogenea(lista,a1);
    InsereProfessorListaHeterogenea(lista,p2);
    InsereAlunoListaHeterogenea(lista,a2);
    InsereAlunoListaHeterogenea(lista,a3);
    InsereAlunoListaHeterogenea(lista,a4);
    InsereAlunoListaHeterogenea(lista,a5);
    InsereProfessorListaHeterogenea(lista,p1);

    ImprimeListaHeterogenea(lista);

    printf("\n");
    printf("O valor arrecadado pro churrasco foi de: %.2f\n", ValorDoChurrasco(lista));

    printf("Maria cancelou a presença no churrasco\n");
    RetiraAlunoListaHeterogenea(lista, "Maria");
    ImprimeListaHeterogenea(lista);
    printf("O valor arrecadado pro churrasco foi de: %.2f\n", ValorDoChurrasco(lista));
    printf("Maria é indecisa e confirmou a presença de novo\n");
    InsereAlunoListaHeterogenea(lista,a1);
    ImprimeListaHeterogenea(lista);
    printf("O valor arrecadado pro churrasco foi de: %.2f\n", ValorDoChurrasco(lista));
    
    printf("O professor roberto terá um compromisso\n");
    RetiraProfessorListaHeterogenea(lista, "Roberto");
    ImprimeListaHeterogenea(lista);
    printf("O valor arrecadado pro churrasco foi de: %.2f\n", ValorDoChurrasco(lista));
    DestroiListaHeterogenea(lista);
    DestroiAluno(a1);
    DestroiAluno(a2);
    DestroiAluno(a3);
    DestroiAluno(a4);
    DestroiAluno(a5);

    DestroiProfessor(p1);
    DestroiProfessor(p2);
}