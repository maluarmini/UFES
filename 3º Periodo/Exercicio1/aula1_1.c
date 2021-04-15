#include <stdio.h>
#include <stdlib.h>

void modificaVariavelA(int a, int *pa){
    *pa = a;
};

void modificaVariavelB(int b, int *pb){
    *pb = b;
};

void modificaVariavelC(int c, int *pc){
    *pc = c;
}

void modificaVariavelD(int d, int *pd){
    *pd = d;
}

int main() {
    int a, b, c, d;
    int *pa, *pb, *pc, *pd;
    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    modificaVariavelA(20, pa);
    modificaVariavelA(19, pb);
    modificaVariavelA(18, pc);
    modificaVariavelA(17, pd);
    printf("Valor A: %d\nValor B: %d\nValor C: %d\nValor D: %d\n", a,b,c,d);
    
    return 0;
}