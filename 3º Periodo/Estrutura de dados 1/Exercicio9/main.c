#include <stdio.h>
#include "arvore.h"
#include "Aluno.h"

int main(){
    Aluno * al1 = IniciaAluno(1, "Maria", 10);
    Aluno * al2 = IniciaAluno(2, "Patricia", 10);
    Aluno * al3 = IniciaAluno(3, "Tiago", 8.9);
    Aluno * al4 = IniciaAluno(4, "Ana", 6.7);
    Aluno * al5 = IniciaAluno(5, "Julia", 9.8);
    Aluno * al6 = IniciaAluno(6, "Mateus", 2);
    Aluno * al7 = IniciaAluno(7, "Luiza", 10);

    Arv *a = arv_cria(al1, 
    arv_cria(al2,
    arv_criavazia(),
    arv_cria(al3, arv_criavazia(),
    arv_criavazia())
    ),
    arv_cria(al4,
    arv_cria(al5, arv_criavazia(),
    arv_criavazia()),
    arv_cria(al6, arv_criavazia(),
    arv_criavazia())
    )
    );

    arv_imprime(a);

    int pertence = arv_pertence(a, RetornaNome(al1));
    if(pertence==1){
        printf("\nAluno %s pertence a arvore\n", RetornaNome(al1));
    }else{
        printf("\nAluno %s NAO pertence a arvore\n",RetornaNome(al1));
    }

    pertence = arv_pertence(a, RetornaNome(al7));
    if(pertence==1){
        printf("\nAluno %s pertence a arvore\n",RetornaNome(al7));
    }else{
        printf("\nAluno %s NAO pertence a arvore\n", RetornaNome(al7));
    }

    if(arv_pertence(a,RetornaNome(al6))){
        printf("\nAluno %s pertence a arvore\n",RetornaNome(al6));
    }else{
        printf("\nAluno %s NAO pertence a arvore\n", RetornaNome(al6));
    }

    int f = folhas(a);

    printf("O numero de folhas da arvore e de: %d\n", f);

    int c = ocorrencias(a,RetornaNome(al1));

    printf("O numero de ocorrencias do aluno(a) %s na arvore e de: %d\n",RetornaNome(al1), c);

    int h = altura(a);

    printf("A altura da arvore e de : %d\n", h);
}