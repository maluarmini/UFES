#include <stdio.h>
#include "listaalunos.h"

int main(int argc, char const *argv[])
{
    ListaGen *lista = criaLista();

    Aluno *a1 = IniciaAluno(1, "Maria", 9.0);
    Aluno *a2 = IniciaAluno(2, "Gabriel", 9.0);
    Aluno *a3 = IniciaAluno(3, "Emerson", 9.0);
    Aluno *a4 = IniciaAluno(4, "Gabriela", 10.0);
    Aluno *a5 = IniciaAluno(5, "Faria", 10.0);
    Aluno *a6 = IniciaAluno(6, "Luiza", 10.0);
    Aluno *a7 = IniciaAluno(7, "Bruno", 10.0);

    lista = insereLista(lista, a1);
    lista = insereLista(lista, a2);
    lista = insereLista(lista, a3);
    lista = insereLista(lista, a4);
    lista = insereLista(lista, a5);
    lista = insereLista(lista, a6);
    lista = insereLista(lista, a7);


    imprimeListaAlunos(lista);

    lista = retiraAluno(lista, 10);

    printf("\nTestando a insere\n\n");
    imprimeListaAlunos(lista);

    printf("Testanto função pertence - usando a matricula da Maria\n\n");
    int i = pertenceAluno(lista, 1);
    if (i == 0)
    {
        printf("\nAluno/a esta na lista!\n\n");
    }
    else
    {
        printf("Aluno/a NAO esta na lista!\n\n");
    }

    printf("Testanto função pertence - usando a matricula da indisponivel\n\n");
    i = pertenceAluno(lista, 10);
    if (i == 0)
    {
        printf("\nAluno/a esta na lista!\n\n");
    }
    else
    {
        printf("Aluno/a NAO esta na lista!\n\n");
    }

    //Retorna a media
    printf("\nA media da turma é: %.2f\n", mediaTurma(lista)); 

    liberaLista(lista);

    DestroiAluno(a1);
    DestroiAluno(a2);
    DestroiAluno(a3);
    DestroiAluno(a4);
    DestroiAluno(a5);
    DestroiAluno(a6);
    DestroiAluno(a7);

    return 0;
}