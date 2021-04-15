#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaContribuicao.h"

typedef struct celulacontribuicao CelulaContribuicao;

struct celulacontribuicao
{
    Contribuicao *c;
    CelulaContribuicao *prox;
};
struct listacontribuicao
{
    CelulaContribuicao *prim;
    CelulaContribuicao *ult;
};

ListaContribuicao *IniciaListaContribuicao()
{
    ListaContribuicao *l = (ListaContribuicao *)malloc(sizeof(ListaContribuicao));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void InsereListaContribuicao(ListaContribuicao *lista, Contribuicao *c)
{   
    if(lista != NULL && c != NULL){
        CelulaContribuicao *nova = (CelulaContribuicao *)malloc(sizeof(CelulaContribuicao));
        nova->c = c;
        if (lista->prim == NULL)
        {
            lista->prim = nova;
            lista->ult = nova;
        }
        lista->ult->prox = nova;
        lista->ult = nova;
        nova->prox = NULL;
    }
    
}

void RetiraListaContribuicao(ListaContribuicao *l, char *chave)
{   
    if(l != NULL && chave != NULL){
        CelulaContribuicao *p = l->prim;
        CelulaContribuicao *ant = NULL;
        while (p != NULL && strcmp(RetornaNomeArquivoContribuicao(p->c), chave) != 0)
        {
            ant = p;
            p = p->prox;
        }
        if (p == NULL)
        {
            return;
        }

        if (p == l->prim && p == l->ult)
        {
            l->prim = l->ult = NULL;
        }
        else if (p == l->prim)
        {
            l->prim = p->prox;
        }
        else if (p == l->ult)
        {
            l->ult = ant;
            l->ult->prox = NULL;
        }
        else
        {
            ant->prox = p->prox;
        }
        ContribuicaoRetirada(p->c);
        free(p);
    }
    
}

void RetiraListaContribuicaoParaHistorico(ListaContribuicao *l, char *chave)
{   
    if(l != NULL && chave != NULL){
        CelulaContribuicao *p = l->prim;
        CelulaContribuicao *ant = NULL;
        while (p != NULL && strcmp(RetornaNomeArquivoContribuicao(p->c), chave) != 0)
        {
            ant = p;
            p = p->prox;
        }
        if (p == NULL)
        {
            return;
        }
        ContribuicaoRetirada(p->c);
    }   
}

int ConfereContribuicao(ListaContribuicao *l, char *chave)
{   
    if(l != NULL && chave != NULL){
    CelulaContribuicao *p = l->prim;
    CelulaContribuicao *ant = NULL;
    while (p != NULL)
    {
        if (!strcmp(RetornaNomeArquivoContribuicao(p->c), chave))
        {
            return 1;
        }
        ant = p;
        p = p->prox;
    }
    return 0;
    }
}

void ImprimeListaContribuicao(ListaContribuicao *lista, int id)
{   if(lista != NULL){
        printf("Lista contribuicoes\n");
        CelulaContribuicao *p;
        int n;
        for (p = lista->prim; p != NULL; p = p->prox)
        {
            if (RetornaStatusContribuicao(p->c) == 0)
            {
                ImprimeContribuicao(p->c);
                continue;
            }
            if (RetornaStatusContribuicao(p->c) == 1)
            {
                if (id == 0)
                {
                }
                else if (id == 1)
                {
                    printf("\nContribuicao removida pelo editor %s\n", RetornaNomeEditorContribuicao(p->c));
                }
            }
        }
    }     
}

void ImprimeListaContribuicoesParaHistorico(ListaContribuicao *lista, FILE *arq)
{   
    if(lista != NULL){
        CelulaContribuicao *p;

        for (p = lista->prim; p != NULL; p = p->prox)
        {
            if (RetornaStatusContribuicao(p->c) == 0)
            {
                fprintf(arq, "%s %s\n", RetornaNomeEditorContribuicao(p->c), RetornaNomeArquivoContribuicao(p->c));
                continue;
            }
            if (RetornaStatusContribuicao(p->c) == 1)
            {
                fprintf(arq, "%s %s <<retirada>>\n", RetornaNomeEditorContribuicao(p->c), RetornaNomeArquivoContribuicao(p->c));
            }
        }
    }
}

void imprime(Contribuicao *c, FILE *arquivo)
{   
    if(c && arquivo != NULL){
        FILE *origem, *destino;
        char caracter;
        //printf("%s", RetornaNomeArquivoContribuicao(c));
        origem = fopen(RetornaNomeArquivoContribuicao(c), "r");

        if (origem == NULL)
        {
            printf("Problema na leitura do arquivo.\n");
            fclose(origem);
            exit(1);
        }
        fprintf(arquivo, "\n-------- %s (%s) --------\n\n", RetornaNomeArquivoContribuicao(c), RetornaNomeEditorContribuicao(c));
        while ((caracter = fgetc(origem)) != EOF)
        {
            fputc(caracter, arquivo);
        }
        printf("Contribuicao copiada\n");
        fclose(origem);
    }
}

void ImprimeListaContribuicaoTextos(ListaContribuicao *lista, FILE *arq)
{   
    if(lista != NULL && arq!= NULL){
    CelulaContribuicao *p;
    for (p = lista->prim; p != NULL; p = p->prox)
    {
        if (RetornaStatusContribuicao(p->c) == 0)
        {
            imprime(p->c, arq);
            continue;
        }
        else
        {
            continue;
        }
    }
    }
}
void DestroiListaContribuicao(ListaContribuicao *lista)
{   
    if(lista){
    CelulaContribuicao *p = lista->prim;
    CelulaContribuicao *t;

    while (p != NULL)
    {
        t = p->prox;
        DestroiContribuicao(p->c);
        free(p);
        p = t;
    }
    free(lista);
    }
}