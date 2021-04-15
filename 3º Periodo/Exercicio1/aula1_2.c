#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265359

void calc_esfera (float r, float* area, float* volume){
    *area = 4 * pi * r * r;
    *volume = (4 * pi * r * r * r ) / 3;
}

int raizes (float a, float b, float c, float* x1, float* x2){
    float delta = (b*b) - (4*a*c);
    if(delta < 0){
        return 0;
    }else{
    *x1 = ((-b) + sqrt(delta)) / (2*a);
    *x2 = ((-b) - sqrt(delta)) / (2*a);
    return 1;
    }
    
}

int pares (int n, int* vet){
    int cont = 0;
    
    for(int i = 0; i < n; i++){
        if(vet[i] % 2 == 0){
            cont++;
        }
    }
    return cont;

};

void inverte (int n, int* vet){
    int temp[n],j=0;
    for (int i=0;i<n;i++){
        temp[i] = vet[i];
    }
    for (int i=0; i<n; i++){
        vet[j] = temp[(n-1)-i];
        j++;
    }
    
}

double avalia (double* poli, int grau, double x){
    double rtn;
    rtn = (poli[2] * pow(x, grau))+ poli[1] * x + poli[0];
    return rtn;
}

// Calcular area e volume de esfera;

/* int main() {
    float area,volume;
    calc_esfera(2, &area, &volume);
    printf("Area: %f\nVolume: %f\n", area, volume);
    return 0;

}
*/

// Calcular raizes da função do segundo grau

/*
int main() {
    float a, b, c, *x1, *x2;
    x1 = (float *)malloc(sizeof(float));
    x2 = (float *)malloc(sizeof(float));
    if(raizes(5,3,5,x1,x2)){
        printf("X1 = %f\nX2 = %f\n", *x1, *x2);
    }else{
        printf("Delta negativo\n");
    }
    
    free(x1);
    free(x2);
    return 0;

}
*/

// Calcular a quantidade de números pares no vetor;

/*
int main() {
    int n = 10, *vet,rtn;
    vet = (int *)malloc(sizeof(int) * n);
    for(int i=0;i<n;i++){
        scanf("%d", &vet[i]);
    }
    rtn = pares(n, vet);
    printf("Quantidade de pares = %d\n", rtn);
    free(vet);
    return 0;
}
*/

// Inverter vetor

/*
int main() {
    int n = 10, *vet;
    vet = (int *)malloc(sizeof(int) * n);
    for(int i=0; i<n;i++){
        scanf("%d", &vet[i]);
    }
    inverte(n, vet);
    for(int i=0;i<n;i++){
        printf(" %d ", vet[i]);
    }
    free(vet);

    return 0;
}
*/

// Avaliação de polinômios

int main() {
    int grau;
    grau = 2;
    double x, *vet,rtn;
    x = 7;
    vet = (double *)malloc(sizeof(double) * 3);
    vet[0] = 5;
    vet[1] = 6;
    vet[2] = 3;

    rtn = avalia(vet, grau, x);
    printf("Resultado: %0.0lf\n", rtn);
    free(vet);

    return 0;

}