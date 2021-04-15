#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"

struct pagina
{
    char *nomePagina;
    char *nomeArquivo;
};

Pagina *iniciaPagina(char *nome, char *nomeArq)
{
    Pagina *p = (Pagina *)malloc(sizeof(Pagina));
    p->nomePagina = strdup(nome);
    p->nomeArquivo = strdup(nomeArq);
    return p;
}

char *RetornaNomePagina(Pagina *p)
{
    return p->nomePagina;
}

char *RetornaNomeArquivo(Pagina *p)
{
    return p->nomeArquivo;
}

void ImprimePagina(Pagina *p)
{
    printf("Pagina\n");
    printf("%s\n", p->nomePagina);
    printf("%s\n", p->nomeArquivo);
}

void DestroiPagina(Pagina *p)
{
    free(p->nomePagina);
    free(p->nomeArquivo);
    free(p);
}