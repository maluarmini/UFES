#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"

int main(){
    TipoPilhaDupla * pilha = IniciaPilha();
    
    // Last in first out - LIFO
    // 18 foi o ultimo a entrar e o primeiro a sair, na parte dos pares
    // 19 foi o ultimo a entrar e o primeiro a sair, na parte dos impares
    push(pilha, 2);
    push(pilha, 6);
    push(pilha, 13);
    push(pilha, 15);
    push(pilha, 8);
    push(pilha, 4);
    push(pilha, 10);
    push(pilha, 11);
    push(pilha, 14);
    push(pilha, 12);
    push(pilha, 18);
    push(pilha, 7);
    push(pilha, 19);
    imprime(pilha);
    int t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);
    imprime(pilha);
    t = pop(pilha);

    printf("\n\n");
    t = pop(pilha);
    imprime(pilha);    
    destroi(pilha);
    return 0;
}