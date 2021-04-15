#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "ListaDuplamenteEncadeadaSemSentinela.h"

int main(){
     //Criando, inicializando e preenchendo algumas matrizes;
    Matriz* m1 = inicializaMatriz(4,4);
    Matriz* m2 = inicializaMatriz(5,5);
    Matriz* m3 = inicializaMatriz(3,2);
    Matriz* m4 = inicializaMatriz(2,3);
    Matriz* m5 = inicializaMatriz(2,3);

    for (int i=0;i<4;i++)
        for (int j=0;j<4; j++)
            modificaElemento(m1, i, j,i+j);
    imprimeMatriz(m1);
    for (int i=0;i<5;i++)
        for (int j=0;j<5; j++)
            modificaElemento(m2, i, j,i+j);
    imprimeMatriz(m2);
    for (int i=0;i<3;i++)
        for (int j=0;j<2; j++)
            modificaElemento(m3, i, j,i+j);
    imprimeMatriz(m3);
    for (int i=0;i<2;i++)
        for (int j=0;j<3; j++)
            modificaElemento(m4, i, j,i+j);
    imprimeMatriz(m4);

    for (int i=0;i<2;i++)
        for (int j=0;j<3; j++)
            modificaElemento(m5, i, j,i+j);

    // Inicializando a Lista 1
    ListaDpl *l = IniciaLista();
    // Inserindo elementos na lista 1
    l = InsereLista(l,m1);
    l = InsereLista(l,m2);
    l = InsereLista(l,m3);
    l = InsereLista(l,m4);

    printf("Imprimindo Lista 1:\n");
    imprimeLista(l);

    printf("Testando a função RetiraLista \n");

    printf("Retirando uma matriz - primeira posição\n");
    l = RetiraLista(l,0);
    printf("\n");
    imprimeLista(l);

    printf("Retirando mais uma matriz - Ultima posiçao\n");

    l = RetiraLista(l,2);
    printf("\n");
    imprimeLista(l);
    
    printf("Inserindo mais uma matriz\n");

    l = InsereLista(l,m5);
    imprimeLista(l);
    printf("\n");
    printf("Retirando mais uma matriz - Caso Comum");

    l = RetiraLista(l,1);

    printf("\n");
    imprimeLista(l);

    printf("Retirando mais uma matriz - ultima\n");
    l = RetiraLista(l,1);
    imprimeLista(l);
    
    printf("Tentando retirar um matriz que não sera encontrada\n");
    l = RetiraLista(l,1);
    imprimeLista(l);


    printf("Inserindo mais uma matriz\n");
    l = InsereLista(l,m1);
    imprimeLista(l);

    printf("Retirando mais uma matriz - ultima\n");
    l = RetiraLista(l,1);
    imprimeLista(l);
    printf("\n");

    printf("Retirando a unica matriz da lista\n");
    l = RetiraLista(l,0);

    imprimeLista(l);

    printf("\nLista vazia\n");

    printf("Tentando retirar uma matriz de uma lista vazia\n");

    l = RetiraLista(l,0);

    imprimeLista(l);
    printf("\n");
    printf("Fim dos testes!!\n");
    //Utilizando a função que destroi a lista, 
    //assumindo que o cliente irá destruir os conteudos;
    DestroiLista(l);
    destroiMatriz(m1);
    destroiMatriz(m2);
    destroiMatriz(m3);
    destroiMatriz(m4);
    destroiMatriz(m5);
    
    
    return 0;
}