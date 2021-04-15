#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz
{   
    int **matriz;
    int linhas;
    int colunas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    if(nlinhas > 0 && ncolunas > 0){ // Pré condição
        Matriz * mat = (Matriz *)malloc(sizeof(Matriz));
        mat->matriz = (int **)malloc(sizeof(int*)*nlinhas);
        for(int i=0;i<nlinhas;i++){
            mat->matriz[i] = (int *)malloc(sizeof(int)*ncolunas);
        }
        mat->linhas = nlinhas;
        mat->colunas= ncolunas;
        if(mat){ // Pos condição
            return mat;
        }
    }
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    if(mat){
        int i = recuperaNLinhas(mat);
        int j = recuperaNColunas(mat);
        mat->matriz[linha][coluna] = elem;
    }
    
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    int i = recuperaNLinhas(mat);
    int j = recuperaNColunas(mat);
    if(mat && linha <= i && coluna <= j){
        return mat->matriz[linha][coluna];
    }
}

int recuperaNColunas (Matriz* mat){
    if(mat){
        return mat->colunas;
    }
    
}

int recuperaNLinhas (Matriz* mat){
    if(mat){
        return mat->linhas;
    }
    
}

Matriz* transposta (Matriz* mat){
    int linhasMat = recuperaNLinhas(mat); //ColunasTrp;
    int colunasMat = recuperaNColunas(mat); //LinhasTrp
    if(mat){
        Matriz * trp = (Matriz*)malloc(sizeof(Matriz));
        trp->matriz = (int **)malloc(sizeof(int *)*colunasMat);
        for(int i=0;i<colunasMat;i++){
            trp->matriz[i] = (int *)malloc(sizeof(int)*linhasMat);
        }
        trp->linhas = colunasMat; 
        trp->colunas = linhasMat;
        for(int i=0; i<mat->linhas;i++){
            for(int j=0;j<mat->colunas;j++){
                trp->matriz[j][i] = mat->matriz[i][j];
            }
        }
        return trp; 
    }
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    if(mat1 && mat2 && mat1->colunas == mat2->linhas){
        Matriz * mult = (Matriz *)malloc(sizeof(Matriz));
        mult->matriz = (int **)malloc(sizeof(int*)*mat1->linhas);
        for(int i =0;i<mat1->linhas;i++){
            mult->matriz[i] = (int*)malloc(sizeof(int)*mat2->colunas);
        }
        mult->linhas = mat1->linhas;
        mult->colunas = mat2->colunas;
        for(int i=0;i<mat1->linhas;i++){
            for(int j=0;j<mat2->colunas;j++){
                mult->matriz[i][j] = 0;
            }
        }

        for(int i=0;i<mat1->linhas;i++){
            for(int j=0;j<mat2->colunas;j++){
                for(int k=0;k<mat1->colunas;k++){
                    mult->matriz[i][j] = mult->matriz[i][j] + mat1->matriz[i][k]*mat2->matriz[k][j];
                }
            }
        }
        return mult;
    }
}

void imprimeMatriz(Matriz* mat){
    int linhas = recuperaNLinhas(mat);
    int colunas = recuperaNColunas(mat);
    if(mat){
        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                printf("%d ", mat->matriz[i][j]);
            }
            printf("\n");
        }
    }
}

void destroiMatriz(Matriz* mat){
    if(mat){
        for(int i=0;i<mat->linhas;i++){
        free(mat->matriz[i]);
        }
        free(mat->matriz);
        free(mat);
    }
}