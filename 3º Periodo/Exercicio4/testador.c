#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"
#include "matriz.h"

int main() {

    //Criando, inicializando e preenchendo algumas matrizes;
    Matriz* m1 = inicializaMatriz(4,4);
    Matriz* m2 = inicializaMatriz(5,5);
    Matriz* m3 = inicializaMatriz(3,2);
    Matriz* m4 = inicializaMatriz(2,3);

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

    // Inicializando a Lista 1
    Lista *l = IniciaLista();
    // Inserindo elementos na lista 1
    InsereLista(l,m1);
    InsereLista(l,m2);
    InsereLista(l,m3);
    InsereLista(l,m4);

    printf("Imprimindo Lista 1:\n");
    ImprimeLista(l);

    //Inicializando uma nova lista
    Lista *novaLista = IniciaLista();
    // Criando as matrizes transpostas e inserindo na lista 2
    Matriz* trpm1 = transposta(m1);
    Matriz* trpm2 = transposta(m2);
    Matriz* trpm3 = transposta(m3);
    Matriz* trpm4 = transposta(m4);

    InsereLista(novaLista,trpm1);
    InsereLista(novaLista,trpm2);
    InsereLista(novaLista,trpm3);
    InsereLista(novaLista,trpm4);
    
    printf("Imprimindo a lista 2:\n");
    ImprimeLista(novaLista);

    printf("Testando a função RetiraLista \n");

    Matriz *matRetirada = RetiraLista(novaLista,0);
    printf("\n");
    ImprimeLista(novaLista);
    
    printf("\nMatriz Retirada - Primeira posiçao\n");
    imprimeMatriz(matRetirada);

    printf("Colocando a matriz retirada denovo\n");
    InsereLista(novaLista,trpm4);

    ImprimeLista(novaLista);

    printf("Retirando mais uma matriz - Ultima posiçao\n");

    Matriz *matRetirada1 = RetiraLista(novaLista,3);
    printf("\n");
    ImprimeLista(novaLista);

    printf("Colocando uma nova matriz\n");

    InsereLista(novaLista,trpm1);

    ImprimeLista(novaLista);

    printf("Retirando mais uma matriz - Caso Comum");

    Matriz * matRetirada2 = RetiraLista(novaLista,1);

    printf("\n");
    ImprimeLista(novaLista);

    printf("Colocando uma nova matriz\n");

    InsereLista(novaLista, matRetirada2);

    ImprimeLista(novaLista);

    // Utilizando a função que destroi a lista, células e seus conteudos
    DestroiLista(l);
    DestroiLista(novaLista);

    //Utilizando a função que destroi a lista, células e assumindo que o cliente irá destruir os conteudos;
    /*  
    destroiMatriz(m1);
    destroiMatriz(m2);
    destroiMatriz(m3);
    destroiMatriz(m4);
    destroiMatriz(trpm1);
    destroiMatriz(trpm2);
    destroiMatriz(trpm3);
    destroiMatriz(trpm4);
    DestroiListaSemDestruirOConteudo(novaLista);
    DestroiListaSemDestruirOConteudo(l);
    */  
    

    return 0;
}