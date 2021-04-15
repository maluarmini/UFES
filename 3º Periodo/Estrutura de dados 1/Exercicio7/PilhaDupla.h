#ifndef PilhaDupla_h
#define PilhaDupla_h

typedef struct tipopilhadupla TipoPilhaDupla;

TipoPilhaDupla * IniciaPilha(void);

void push (TipoPilhaDupla * pilha, int item);

int pop(TipoPilhaDupla * pilha);

void imprime(TipoPilhaDupla * pilha);

//Destroi a pilha;
void destroi(TipoPilhaDupla * pilha);


#endif