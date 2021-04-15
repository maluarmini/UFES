#include <stdio.h>
#include "Aluno.h"
#include "abb.h"

int main(){
    Aluno * al1 = IniciaAluno(1, "Maria", 10);
    Aluno * al2 = IniciaAluno(2, "Patricia", 10);
    Aluno * al3 = IniciaAluno(3, "Tiago", 8.9);
    Aluno * al4 = IniciaAluno(4, "Ana", 6.7);
    Aluno * al5 = IniciaAluno(5, "Julia", 9.8);
    Aluno * al6 = IniciaAluno(6, "Mateus", 2);
    Aluno * al7 = IniciaAluno(7, "Luiza", 10);

    Arv *a = abb_cria();
    a = abb_insere(a, al1);
    a = abb_insere(a, al2);
    a = abb_insere(a, al3);
    a = abb_insere(a, al4);
    a = abb_insere(a, al5);
    a = abb_insere(a, al6);
    a = abb_insere(a, al7);
    abb_imprime(a);
    printf("\n----Testando função busca----\n\n");

    Arv * t = abb_busca(a, 6);
    abb_imprime(t);
    t = abb_busca(a, 4);
    printf("\n\n");
    abb_imprime(t);

    printf("\n----Testando função retira----\n\n");

    // retirando a ultima
    printf("Retirando a LUIZA\n");
    a = abb_retira(a, 7);
    abb_imprime(a);
    printf("\n\n");

    // retirando tiago
    printf("Retirando o TIAGO\n");
    a = abb_retira(a, 3);
    abb_imprime(a);
    printf("\n\n");

    // retirando Maria
    printf("Retirando MARIA\n");
    a = abb_retira(a, 1);
    abb_imprime(a);
    printf("\n\n");

    // Inserindo a Maria e a Luiza denovo
    printf("Inserindo a MARIA e LUIZA de novo\n");
    a = abb_insere(a, al1);
    a = abb_insere(a, al7);
    abb_imprime(a);
    printf("\n\n");

    //liberando os alunos, ja que a libera q eu implementei no abb, não destroi eles
    DestroiAluno(al1);
    DestroiAluno(al2);
    DestroiAluno(al3);
    DestroiAluno(al4);
    DestroiAluno(al5);
    DestroiAluno(al6);
    DestroiAluno(al7);

    //Destruindo a arvore;
    a = abb_libera(a);

    
    return 0;

};