#ifndef PALAVRA_h
#define PALAVRA_h
#include <stdio.h>

typedef struct palavra Palavra;

Palavra *inicPalavra(char *str);

Palavra *inserePalavralista(Palavra *lista, Palavra *p);

Palavra *buscaPalavra(Palavra *pal, char *string);

void imprimelista(Palavra *p);

void liberalistaPalavra(Palavra *pal);

char *retornaString(Palavra *pal);

void atualizaOcorrencias(Palavra *pal);

int contaPalavraslista(Palavra *p);

int retornaOcorrencias(Palavra *pal);

#endif