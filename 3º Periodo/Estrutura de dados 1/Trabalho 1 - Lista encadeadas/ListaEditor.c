#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEditor.h"
#include "ListaContribuicao.h"

typedef struct celeditor CelulaEditor;

struct celeditor
{
    Editor *ed;
    ListaContribuicao *contribuicoes;
    CelulaEditor *prox;
};

struct listaeditor
{
    CelulaEditor *prim;
    CelulaEditor *ult;
};

ListaEditor *IniciaListaEditor()
{
    ListaEditor *l = (ListaEditor *)malloc(sizeof(ListaEditor));
    l->prim = NULL;
    l->ult = NULL;
    return l;
}

void InsereListaEditor(ListaEditor *l, Editor *ed)
{   
    if(l != NULL && ed != NULL){
        CelulaEditor *nova = (CelulaEditor *)malloc(sizeof(CelulaEditor));
        nova->ed = ed;
        nova->contribuicoes = IniciaListaContribuicao();
        if (l->prim == NULL)
        {
            l->prim = nova;
            l->ult = nova;
        }
        l->ult->prox = nova;
        l->ult = nova;
        nova->prox = NULL;
    }
}

void *RemoveEditor(ListaEditor *l, char *chave)
{   
    if(l != NULL && chave != NULL){
        CelulaEditor *p = l->prim;
        CelulaEditor *ant = NULL;
        Editor *editor;
        while (p != NULL && strcmp(RetornaNomeEditor(p->ed), chave) != 0)
        {
            ant = p;
            p = p->prox;
        }

        editor = p->ed;

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

void ImprimeListaEditor(ListaEditor *l)
{   
    if(l){
        printf("Lista Editores:\n");
        CelulaEditor *p;
        for (p = l->prim; p != NULL; p = p->prox)
        {
            ImprimeEditor(p->ed);
        }
    }
}

ListaContribuicao *RetornaListaContribuicaoEditor(ListaEditor *l, char *editor)
{   
    if(l != NULL && editor != NULL){
        CelulaEditor *p = l->prim;
        CelulaEditor *ant = NULL;
        while (p != NULL && strcmp(RetornaNomeEditor(p->ed), editor) != 0)
        {
            ant = p;
            p = p->prox;
        }
        return p->contribuicoes;
    }
}

int ConfereExistenciaEditor(ListaEditor *l, char *nome)
{   
    if(l != NULL && nome != NULL){
        CelulaEditor *p = l->prim;
        CelulaEditor *ant = NULL;
        while (p != NULL)
        {
            //ImprimePagina(p->pagina);
            if (!strcmp(RetornaNomeEditor(p->ed), nome))
            {
                return 1;
            }
            ant = p;
            p = p->prox;
        }
        return 0;
    }
}

int VerificaEditor(ListaEditor *l, char *nome)
{   
    if(l != NULL && nome != NULL){
        CelulaEditor *p = l->prim;
        CelulaEditor *ant = NULL;
        while (p != NULL && strcmp(RetornaNomeEditor(p->ed), nome) != 0)
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
}

void DestroiListaEditor(ListaEditor *l)
{ //Destroi a lista sem destruir os editores dela
    if(l != NULL){
        CelulaEditor *p = l->prim;
        CelulaEditor *t;

        while (p != NULL)
        {
            t = p->prox;
            DestroiListaContribuicao(p->contribuicoes);
            DestroiEditor(p->ed);
            free(p);
            p = t;
        }
        free(l);
    }
}