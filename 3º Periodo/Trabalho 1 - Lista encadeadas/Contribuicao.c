#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"

struct contribuicao
{
    char *nomeEditor;
    char *nomeArquivo;
    int retirada;
};

void ContribuicaoRetirada(Contribuicao *c)
{
    if(c){
        c->retirada = 1;
    }
}

int RetornaStatusContribuicao(Contribuicao *c)
{
    if(c){
        return c->retirada;
    }
}

Contribuicao *IniciaContribuicao(char *nomeEditor, char *nomeArquivo)
{
    if(nomeEditor != NULL && nomeArquivo != NULL){
        Contribuicao *c = (Contribuicao *)malloc(sizeof(Contribuicao));
        c->nomeEditor = strdup(nomeEditor);
        c->nomeArquivo = strdup(nomeArquivo);
        c->retirada = 0;
        return c;
    }
    return NULL;
}

char *RetornaNomeArquivoContribuicao(Contribuicao *c)
{
    if(c){
        return c->nomeArquivo;
    }
}

char *RetornaNomeEditorContribuicao(Contribuicao *c)
{
    if(c){
        return c->nomeEditor;
    }
}

void ImprimeContribuicao(Contribuicao *c)
{
    if(c){
        printf("Contribuicao\n");
        printf("%s\n", c->nomeEditor);
        int i = 0;
        printf("%s\n", c->nomeArquivo);

    }
}

void DestroiContribuicao(Contribuicao *c)
{
    if(c){
        free(c->nomeEditor);
        free(c->nomeArquivo);
        free(c);
    }
}