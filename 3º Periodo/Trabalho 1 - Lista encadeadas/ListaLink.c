#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaLink.h"
#include "ListaPagina.h"

typedef struct celulalink CelulaLink;

struct celulalink
{
    Pagina *link;
    CelulaLink *prox;
};

struct listalink
{
    CelulaLink *prim;
    CelulaLink *ult;
};

ListaLink *IniciaListaLink()
{
    ListaLink *lista = (ListaLink *)malloc(sizeof(ListaLink));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void InsereListaLink(ListaLink *lista, Pagina *link)
{   
    if(lista != NULL && link != NULL){
        CelulaLink *nova = (CelulaLink *)malloc(sizeof(CelulaLink));
        nova->link = link;
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

void RetiraListaLink(ListaLink *l, char *chave)
{   
    if(l != NULL){
        CelulaLink *p = l->prim;
        CelulaLink *ant = NULL;
        while (p != NULL && strcmp(RetornaNomePagina(p->link), chave) != 0)
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

        free(p);

    }
}

void ImprimeListaLink(ListaLink *lista)
{
    if(lista != NULL){
        printf("Lista links\n");
        CelulaLink *p;
        for (p = lista->prim; p != NULL; p = p->prox)
        {
            ImprimePagina(p->link);
            printf("\n");
        }
    }
}

void ImprimeListaLinksArquivo(ListaLink *lista, FILE *arq)
{   
    if(lista != NULL && arq != NULL){
        CelulaLink *p;
        char *aux;
        int i = 0;
        for (p = lista->prim; p != NULL; p = p->prox)
        {
            i = 0;
            fprintf(arq, "%s ", RetornaNomePagina(p->link));
            aux = RetornaNomePagina(p->link);
            fprintf(arq, "%s\n", RetornaNomeArquivo(p->link));
        }
    }
}

void DestroiListaLink(ListaLink *lista)
{   
    if(lista != NULL){
        CelulaLink *p = lista->prim;
        CelulaLink *t;

        while (p != NULL)
        {
            t = p->prox;
            //DestroiPagina(p->link);
            free(p);
            p = t;
        }
        free(lista);
    }
}

// Encontrar uma pagina pelo nome, na lista de link
Pagina *RetornaLinkLista(ListaLink *lista, char *nome)
{   
    if(lista != NULL){
    CelulaLink *p = lista->prim;
    CelulaLink *t;
    for (p = lista->prim; p != NULL; p = p->prox)
    {
        if (!strcmp(RetornaNomePagina(p->link), nome))
        {
            return p->link;
        }
    }
    return NULL;
    }
}

Pagina *RetornaProximoLink(ListaLink *listaInicio, ListaLink *percorridos)
{   
    if(listaInicio != NULL){
        CelulaLink *p = listaInicio->prim;
        CelulaLink *t = NULL;
        char *nomePagina;
        if (p == NULL)
        {
            printf("Ja começa vazia, nem entra no for\n");
            return NULL;
        }
        for (p = listaInicio->prim; p != NULL; p = p->prox)
        {
            nomePagina = RetornaNomePagina(p->link);
            // se eu não achar a pagina na lista das percorridas
            // eu retorno ela, pois significa que eu ainda nao passei nela
            if (RetornaLinkLista(percorridos, nomePagina) == NULL)
            {

                return p->link;
            }
        }
        return NULL;
    }
}

int ConfereLista(ListaLink *l,ListaLink * percorridas)
{   
    if(l != NULL && percorridas != NULL){
        char *nomePagina;
        CelulaLink *p = l->prim;
        for(p=l->prim; p != NULL; p=p->prox){
            nomePagina = RetornaNomePagina(p->link);
            
            if (RetornaLinkLista(percorridas, nomePagina) != NULL)
            {
            continue;
            }else{
                return 0;
            }
        }
        return 1;
    }
}