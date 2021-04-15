#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaPagina.h"
#include "ListaContribuicao.h"
#include "ListaLink.h"

typedef struct celulapagina CelulaPagina;

struct celulapagina
{
    Pagina *pagina;
    ListaContribuicao *contribuicoes;
    ListaLink *links;
    CelulaPagina *prox;
};

struct listapagina
{
    CelulaPagina *prim;
    CelulaPagina *ult;
};

ListaPagina *iniciaListaPagina()
{
    ListaPagina *lista = (ListaPagina *)malloc(sizeof(ListaPagina));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

int VerificaPagina(ListaPagina *l, char *nome)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *ant = NULL;
    while (p != NULL && strcmp(RetornaNomePagina(p->pagina), nome) != 0)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void InsereListaPagina(ListaPagina *l, Pagina *p)
{
    CelulaPagina *nova = (CelulaPagina *)malloc(sizeof(CelulaPagina));
    nova->pagina = p;
    nova->contribuicoes = IniciaListaContribuicao();
    nova->links = IniciaListaLink();
    if (l->prim == NULL)
    {
        l->prim = nova;
        l->ult = nova;
    }
    l->ult->prox = nova;
    l->ult = nova;
    nova->prox = NULL;
}
Pagina *RetornaPagina(ListaPagina *l, char *nome)
{
    CelulaPagina *p = l->prim;
    Pagina *pagina;
    CelulaPagina *ant = NULL;
    while (p != NULL && strcmp(RetornaNomePagina(p->pagina), nome) != 0)
    {
        ant = p;
        p = p->prox;
    }
    pagina = p->pagina;
    return pagina;
}

void RetiraListaPagina(ListaPagina *l, char *nome)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *ant = NULL;
    while (p != NULL && strcmp(RetornaNomePagina(p->pagina), nome) != 0)
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
    DestroiListaContribuicao(p->contribuicoes);
    DestroiListaLink(p->links);
    DestroiPagina(p->pagina);
    free(p);
}

void ApagaLinksDeUmaPagina(ListaPagina *listaPaginas, char *PaginaRetirada)
{
    CelulaPagina *p;
    CelulaPagina *ant = NULL;
    ListaLink *aux;
    int pos = 0;
    for (p = listaPaginas->prim; p != NULL; p = p->prox)
    {
        aux = RetornaListaLinkPaginaPelaPosicao(listaPaginas, pos);
        RetiraListaLink(aux, PaginaRetirada);
        pos++;
    }
}
ListaContribuicao *RetornaListaContribuicaoPagina(ListaPagina *l, char *pagina)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *ant = NULL;
    while (p != NULL && strcmp(RetornaNomePagina(p->pagina), pagina) != 0)
    {
        ant = p;
        p = p->prox;
    }
    return p->contribuicoes;
}

ListaLink *RetornaListaLinkPagina(ListaPagina *l, char *pagina)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *ant = NULL;
    while (p != NULL)
    {
        if (!strcmp(RetornaNomePagina(p->pagina), pagina))
        {
            break;
        }
        ant = p;
        p = p->prox;
    }
    return p->links;
}

ListaLink *RetornaListaLinkPaginaPelaPosicao(ListaPagina *l, int pos)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *ant = NULL;
    int cont = 0;
    for (p = l->prim; p != NULL; p = p->prox)
    {
        if (cont == pos)
        {
            return p->links;
        }
        cont++;
    }
    return NULL;
}

void imprimeListaPagina(ListaPagina *l)
{
    printf("Lista paginas\n");
    CelulaPagina *p;
    for (p = l->prim; p != NULL; p = p->prox)
    {
        ImprimePagina(p->pagina);
        ImprimeListaContribuicao(p->contribuicoes, 0);
        ImprimeListaLink(p->links);
        printf("\n");
    }
}

void imprimePaginaCompleta(ListaPagina *l, char *nome)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *ant = NULL;
    while (p != NULL && strcmp(RetornaNomePagina(p->pagina), nome) != 0)
    {
        ant = p;
        p = p->prox;
    }
    ImprimePagina(p->pagina);
    ImprimeListaContribuicao(p->contribuicoes, 1);
    ImprimeListaLink(p->links);
}

void DestroiListaPagina(ListaPagina *l)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *t;

    while (p != NULL)
    {
        t = p->prox;
        DestroiListaContribuicao(p->contribuicoes);
        DestroiListaLink(p->links);
        DestroiPagina(p->pagina);
        free(p);
        p = t;
    }
    free(l);
}

int ConfereExistenciaPagina(ListaPagina *l, char *nome)
{
    CelulaPagina *p = l->prim;
    CelulaPagina *ant = NULL;
    while (p != NULL)
    {
        //ImprimePagina(p->pagina);
        if (!strcmp(RetornaNomePagina(p->pagina), nome))
        {
            return 1;
        }
        ant = p;
        p = p->prox;
    }
    return 0;
}

void ImprimeWikEd(ListaPagina *listaPaginas)
{
    CelulaPagina *p = listaPaginas->prim;
    CelulaPagina *ant = NULL;
    char nomePagina[20];
    int i = 0;
    while (p != NULL)
    {
        i = 0;
        strcpy(nomePagina, RetornaNomePagina(p->pagina));
        ListaContribuicao *l = RetornaListaContribuicaoPagina(listaPaginas, nomePagina);
        ImprimeListaContribuicao(l, 1);
        ListaLink *listaLink = RetornaListaLinkPagina(listaPaginas, nomePagina);
        FILE *arquivo = fopen(RetornaNomeArquivo(RetornaPagina(listaPaginas, nomePagina)), "w");
        if (arquivo == NULL)
        {
            printf("Sinto muito, ocorreu um problema. :/ ");
            exit(1);
        }

        fprintf(arquivo, "%s\n\n", nomePagina);
        fprintf(arquivo, "--> Historico de contribuicoes\n");
        ImprimeListaContribuicoesParaHistorico(l, arquivo);
        fprintf(arquivo, "\n--> Links \n");
        ImprimeListaLinksArquivo(listaLink, arquivo);
        fprintf(arquivo, "\n--> Textos \n");
        ImprimeListaContribuicaoTextos(l, arquivo);
        fclose(arquivo);
        ant = p;
        p = p->prox;
    }
}