#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"
#include "ListaEditor.h"
#include "Contribuicao.h"
#include "ListaContribuicao.h"
#include "Pagina.h"
#include "ListaPagina.h"

// FUNCOES PRINCIPAIS DO PROGRAMA

void INSEREPAGINA(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE * log);

void RETIRAPAGINA(ListaPagina *listaPaginas, char *argumento1, FILE *log);

void INSEREEDITOR(ListaEditor *listaEditores, char *argumento1,FILE *log);

void INSERECONTRIBUICAO(ListaPagina *listaPaginas, ListaEditor *listaEditores, char *argumento1, char *argumento2, char *argumento3, FILE *log);

void IMPRIMEPAGINA(ListaPagina *listaPaginas, char *argumento1);

void RETIRACONTRIBUICAO(ListaPagina *listaPaginas, ListaEditor *listaEditores, char *argumento1, char *argumento2, char *argumento3, FILE *log);

void INSERELINK(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE *log);

void RETIRALINK(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE *log);

void CAMINHO(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE *log);

void IMPRIMEWIKED(ListaPagina *listaPaginas);

// FUNÇÕES PARA TRATAR ERROS E GERAR O ARQUIVO log.txt

void ErroExistenciaPagina(FILE *log, char *nomePagina);

void ErroPaginaJaExiste(FILE *log, char *nomePagina);

void ErroEditorJaExiste(FILE *log, char *nomeEditor);

void ErroRetiraContribuicao(FILE *log, char *nomeContribuicao, char *nomeContribuica);

void ErroInsereContribuicao(FILE *log, char *nomePagina);

void ErroInsereLink(FILE *log, char *nomePagina1, char *nomePagina2);

void ErroEditorNaoExiste(FILE *log, char *nomeEditor);

void ErroCaminhoPaginaInexistente(FILE *log);

void ErroRetiraLink(FILE *log);

// FUNÇÕES USADAS NA FUNCIONALIDADE CAMINHO

static void PaginasPercorridas(ListaPagina *listaPaginas, ListaLink *percorridos, Pagina *pagina1, Pagina *pagina2, Pagina *inicial);

int ExisteCaminho(ListaLink *listaLink, char *pagina2);

// MAIN
int main(int argc, char *argv[])
{
    FILE *arquivo = fopen(argv[1], "r");
    char func[100], argumento1[100], argumento2[100], argumento3[100], aux[100];
    int i = 0;
    char c;
    if (arquivo == NULL)
    {
        printf("Problema na leitura do arquivo.\n");
        return 1;
    }
    FILE *log = fopen("log.txt", "w");
    if (log == NULL)
    {
        printf("Problema na geracao do arquivo log.txt.\n");
        //fclose(log);
        exit(1);
    }
    ListaPagina *listaPaginas = iniciaListaPagina();
    ListaEditor *listaEditores = IniciaListaEditor();

    while (fscanf(arquivo, "%s", func) != EOF)
    {
        if (!strcmp(func, "INSEREPAGINA"))
        {
            fscanf(arquivo, "%s", argumento1);
            fscanf(arquivo, "%s", argumento2);
            printf("%s %s %s\n", func, argumento1, argumento2);
            INSEREPAGINA(listaPaginas, argumento1, argumento2,log);
        }
        else if (!strcmp(func, "RETIRAPAGINA"))
        {
            fscanf(arquivo, "%s", argumento1);
            printf("%s %s\n", func, argumento1);
            RETIRAPAGINA(listaPaginas, argumento1, log);
        }
        else if (!strcmp(func, "INSEREEDITOR"))
        {
            fscanf(arquivo, "%s", argumento1);
            printf("%s %s\n", func, argumento1);
            INSEREEDITOR(listaEditores, argumento1,log);
        }
        else if (!strcmp(func, "INSERECONTRIBUICAO"))
        {
            fscanf(arquivo, "%s", argumento1);
            fscanf(arquivo, "%s", argumento2);
            fscanf(arquivo, "%s", argumento3);
            printf("%s %s %s %s\n", func, argumento1, argumento2, argumento3);
            INSERECONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, log);
        }
        else if (!strcmp(func, "IMPRIMEPAGINA"))
        {
            fscanf(arquivo, "%s", argumento1);
            printf("%s %s\n", func, argumento1);
            IMPRIMEPAGINA(listaPaginas, argumento1);
        }
        else if (!strcmp(func, "INSERELINK"))
        {
            fscanf(arquivo, "%s", argumento1);
            fscanf(arquivo, "%s", argumento2);
            printf("%s %s %s\n", func, argumento1, argumento2);
            INSERELINK(listaPaginas, argumento1, argumento2, log);
        }
        else if (!strcmp(func, "RETIRALINK"))
        {
            fscanf(arquivo, "%s", argumento1);
            fscanf(arquivo, "%s", argumento2);
            printf("%s %s %s\n", func, argumento1, argumento2);
            RETIRALINK(listaPaginas, argumento1, argumento2, log);
            ImprimeListaLink(RetornaListaLinkPagina(listaPaginas, argumento1));
        }
        else if (!strcmp(func, "RETIRACONTRIBUICAO"))
        {
            fscanf(arquivo, "%s", argumento1);
            fscanf(arquivo, "%s", argumento2);
            fscanf(arquivo, "%s", argumento3);
            printf("%s %s %s %s\n", func, argumento1, argumento2, argumento3);
            RETIRACONTRIBUICAO(listaPaginas, listaEditores, argumento1, argumento2, argumento3, log);
        }
        else if (!strcmp(func, "CAMINHO"))
        {
            fscanf(arquivo, "%s", argumento1);
            fscanf(arquivo, "%s", argumento2);
            printf("%s %s %s\n", func, argumento1, argumento2);
            CAMINHO(listaPaginas, argumento1, argumento2, log);
        }
        else if (!strcmp(func, "IMPRIMEWIKED"))
        {
            IMPRIMEWIKED(listaPaginas);
        }
        else if (!strcmp(func, "FIM"))
        {
            DestroiListaPagina(listaPaginas);
            DestroiListaEditor(listaEditores);
        }
        else
        {
            /* Tratamento para eventuais comandos que o codigo nao esteja
               preparado para receber
            */
            printf("Comando %s nao foi encontrado \n", func);
        }
    }
    fclose(arquivo);
    fclose(log);
    return 0;
}

void INSEREPAGINA(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE *log)
{
    if (VerificaPagina(listaPaginas, argumento1) == 0)
    {
        Pagina *novaPagina = iniciaPagina(argumento1, argumento2);
        InsereListaPagina(listaPaginas, novaPagina);
    }else{
        ErroPaginaJaExiste(log,argumento1);
    }
}

void RETIRAPAGINA(ListaPagina *listaPaginas, char *argumento1, FILE *log)
{
    if (!VerificaPagina(listaPaginas, argumento1))
    {
        ErroExistenciaPagina(log, argumento1);
    }
    else
    {
        ApagaLinksDeUmaPagina(listaPaginas, argumento1);
        RetiraListaPagina(listaPaginas, argumento1);
    }
}
void INSEREEDITOR(ListaEditor *listaEditores, char *argumento1,FILE * log)
{
    if (VerificaEditor(listaEditores, argumento1) == 0)
    {
        Editor *novoEditor = IniciaEditor(argumento1);
        InsereListaEditor(listaEditores, novoEditor);
    }else{
        ErroEditorJaExiste(log,argumento1);
    }
}

void INSERECONTRIBUICAO(ListaPagina *listaPaginas, ListaEditor *listaEditores, char *argumento1, char *argumento2, char *argumento3, FILE *log)
{
    if (ConfereExistenciaPagina(listaPaginas, argumento1) == 1 && ConfereExistenciaEditor(listaEditores, argumento2))
    {
        Contribuicao *novaContribuicao = IniciaContribuicao(argumento2, argumento3);
        Contribuicao *novaContribuicaoEditor = IniciaContribuicao(argumento2, argumento3);
        InsereListaContribuicao(RetornaListaContribuicaoPagina(listaPaginas, argumento1), novaContribuicao);

        InsereListaContribuicao(RetornaListaContribuicaoEditor(listaEditores, argumento2), novaContribuicaoEditor);
    }
    else
    {
        if (ConfereExistenciaPagina(listaPaginas, argumento1) == 0)
        {
            ErroExistenciaPagina(log, argumento1);
        }
        else
        {
            ErroEditorNaoExiste(log, argumento2);
        }
    }
}

void IMPRIMEPAGINA(ListaPagina *listaPaginas, char *argumento1)
{
    char nomeArquivo[20];
    char nomePagina[20];
    int i = 0;
    strcpy(nomePagina, argumento1);
    if (ConfereExistenciaPagina(listaPaginas, nomePagina))
    {
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
    }
}

void INSERELINK(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE *log)
{
    if (ConfereExistenciaPagina(listaPaginas, argumento1) == 1 && ConfereExistenciaPagina(listaPaginas, argumento2) == 1)
    {
        ListaLink *listaAux = RetornaListaLinkPagina(listaPaginas, argumento1);
        if (RetornaLinkLista(listaAux, argumento2) == NULL)
        {
            InsereListaLink(listaAux, RetornaPagina(listaPaginas, argumento2));
        }
    }
    else
    {
        ErroInsereLink(log, argumento1, argumento2);
    }
}

void RETIRALINK(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE *log)
{
    if (ConfereExistenciaPagina(listaPaginas, argumento1) == 1 && ConfereExistenciaPagina(listaPaginas, argumento2) == 1)
    {
        ListaLink *listaAux = RetornaListaLinkPagina(listaPaginas, argumento1);
        RetiraListaLink(listaAux, argumento2);
    }
    else
    {
       ErroRetiraLink(log); 
    }
}

void IMPRIMEWIKED(ListaPagina *listaPaginas)
{
    ImprimeWikEd(listaPaginas);
}

void RETIRACONTRIBUICAO(ListaPagina *listaPaginas, ListaEditor *listaEditores, char *argumento1, char *argumento2, char *argumento3, FILE *log)
{
    if (ConfereExistenciaPagina(listaPaginas, argumento1) == 1)
    {
        if (ConfereContribuicao(RetornaListaContribuicaoEditor(listaEditores, argumento2), argumento3))
        {
            RetiraListaContribuicaoParaHistorico(RetornaListaContribuicaoPagina(listaPaginas, argumento1), argumento3);
            RetiraListaContribuicaoParaHistorico(RetornaListaContribuicaoEditor(listaEditores, argumento2), argumento3);
            printf("CONTRIBUICAO RETIRADA COM SUCESSO\n");
        }
        else
        {
            ErroRetiraContribuicao(log, argumento3, argumento2);
        }
    }
}

// Função de recursao para adicionar na lista as paginas que eu for percorrendo
static void PaginasPercorridas(ListaPagina *listaPaginas, ListaLink *percorridos, Pagina *pagina1, Pagina *pagina2, Pagina *inicial)
{
    char *nome1 = RetornaNomePagina(pagina1);
    char *nome2 = RetornaNomePagina(pagina2);
    char *paginaInicial = RetornaNomePagina(inicial);

    /* Insere a pagina que eu estou, pois se eu to nela ela ja foi percorrida
        e eu nao quero eventualmente entrar nela de novo.
    */
    InsereListaLink(percorridos, pagina1);

    // Retorno a lista de links da pagina que eu estou no momento, a inicial
    ListaLink *listaLinkInicio = RetornaListaLinkPagina(listaPaginas, nome1);

    int rtn = ConfereLista(listaLinkInicio,percorridos);
    printf("\nRTN : %d\n", rtn);
    if (rtn == 1)
    {
        listaLinkInicio = RetornaListaLinkPagina(listaPaginas, paginaInicial);
    }

    // Confere se existe caminho entre a lista que eu estou com a pagina que eu busco um caminho
    if (ExisteCaminho(listaLinkInicio, nome2) == 1)
    {
        //Se existe eu insiro ela na minha lista de paginas percorridas e retorno.
        InsereListaLink(percorridos, pagina2);
        printf("\nExiste caminho\n");
        return;
    }
    else
    {

        Pagina *aux = RetornaProximoLink(listaLinkInicio, percorridos);
        if (aux != NULL)
        {
            PaginasPercorridas(listaPaginas, percorridos, aux, pagina2, RetornaPagina(listaPaginas, paginaInicial));
        }
    }
    return;
}

void CAMINHO(ListaPagina *listaPaginas, char *argumento1, char *argumento2, FILE *log)
{
    // Criei uma lista para armazenar as paginas que eu for percorrendo no meu programa
    ListaLink *percorridos = IniciaListaLink();

    // Verificar se ambas as paginas existem.
    if (VerificaPagina(listaPaginas, argumento1) && VerificaPagina(listaPaginas, argumento2))
    {
        PaginasPercorridas(listaPaginas, percorridos, RetornaPagina(listaPaginas, argumento1), RetornaPagina(listaPaginas, argumento2), RetornaPagina(listaPaginas, argumento1));
    }
    else
    {
        ErroCaminhoPaginaInexistente(log);
        DestroiListaLink(percorridos);
        return;
    }

    /* Confere se eu encontro a pagina na lista das percorridas
        Se isso ocorrer entao significa que em algum momento na minha função de recursao
        eu consegui chegar nessa pagina e logo estabelecer um caminho entre as duas 
        paginas.
        Se não, entao significa que nao foi possivel estabeler esse caminho.
    */
    if (RetornaLinkLista(percorridos, argumento2))
    {
        fprintf(log, "HA CAMINHO da pagina %s para %s\n", argumento1, argumento2);
    }
    else
    {
        fprintf(log, "NAO HA CAMINHO da pagina %s para %s\n", argumento1, argumento2);
    }

    // Liberar a memoria que eu aloquei para armazenar as paginas percorridas.
    DestroiListaLink(percorridos);
}

// Conferindo se possui caminho na propria lista de links da pagina
int ExisteCaminho(ListaLink *listaLink, char *pagina2)
{
    if (RetornaLinkLista(listaLink, pagina2) == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void ErroExistenciaPagina(FILE *log, char *nomePagina)
{
    fprintf(log, "ERRO: Nao existe a pagina de %s\n", nomePagina);
}

void ErroPaginaJaExiste(FILE *log, char *nomePagina)
{
    fprintf(log, "ERRO: A pagina %s ja existe no Wiked\n", nomePagina);
}

void ErroRetiraContribuicao(FILE *log, char *nomeContribuicao, char *nomeEditor)
{
    fprintf(log, "ERRO: Nao e possivel remover a contribuicao %s pois ela nao foi feita por voce %s.\n", nomeContribuicao, nomeEditor);
}

void ErroInsereContribuicao(FILE *log, char *nomePagina)
{
    fprintf(log, "ERRO: A pagina %s, na qual voce esta tentando inserir uma contribuicao, nao existe.\n", nomePagina);
}

void ErroInsereLink(FILE *log, char *nomePagina1, char *nomePagina2)
{
    fprintf(log, "ERRO: Nao foi possivel linkar as paginas pois ela/elas nao existem\n");
}

void ErroRetiraLink(FILE *log)
{
    fprintf(log, "Nao foi possivel retirar o link");
}

void ErroEditorNaoExiste(FILE *log, char *nomeEditor)
{
    fprintf(log, "ERRO: Editor %s nao existe\n", nomeEditor);
}

void ErroEditorJaExiste(FILE *log, char *nomeEditor)
{
    fprintf(log, "ERRO: Ja existe um editor cadastrado no Wiked com esse nome '%s'\n", nomeEditor);
}

void ErroCaminhoPaginaInexistente(FILE *log)
{
    fprintf(log, "Nao e possivel verificar CAMINHOS entre paginas inexistentes\n");
}