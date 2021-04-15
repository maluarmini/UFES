#ifndef ListaPagina_h
#define ListaPagina_h
#include "Pagina.h"
#include "ListaContribuicao.h"
#include "ListaLink.h"

// Tipo listapagina (tipo opaco)
typedef struct listapagina ListaPagina;

/* Inicializa uma lista de paginas
*  inputs: nenhum
*  output: Ponteiro para uma lista de paginas inicializada
*  pre-condicao: nenhuma
*  pos-condicao: Lista de paginas existe
*/
ListaPagina * iniciaListaPagina();

/* Verifico se existe uma pagina com o nome passado no paramentro
*  na minha lista de paginas 
*  inputs: Lista de paginas e nome da pagina
*  output: se nao existe retorna 0, se existe retorna 1
*  pre-condicao: Lista de paginas existe
*  pos-condicao: A lsita de paginas nao e modificada
*/
int VerificaPagina(ListaPagina *l, char * nome);

/* Insere uma pagina em uma lista de paginas
*  inputs: Lista de pagina e a pagina
*  output: nenhum
*  pre-condicao: A lista de pagina e a pagina serem validas 
*  pos-condicao: Lista de pagina com a pagina adicionada
*/
void InsereListaPagina(ListaPagina *l, Pagina *p);

/* Retira uma pagina da lista de paginas
*  inputs: Lista de paginas e nome da pagina a ser retirada
*  output: Nenhum
*  pre-condicao: A lista de pagina e a pagina serem validas
*  pos-condicao: Lista de pagina com a pagina retirada
*/
void RetiraListaPagina(ListaPagina *l, char * nome);

/* Imprime uma lista de paginas
*  inputs: Lista de paginas
*  output: Nenhum
*  pre-condicao: A lista de pagina existe
*  pos-condicao: nenhuma
*/
void imprimeListaPagina(ListaPagina *l);

/* Libera a memória alocada para a lista de paginas
*  inputs: A lista de paginas 
*  output: nenhum
*  pre-condicao: A lista de paginas existir
*  pos-condicao: Toda a memoria alocada para a lista de paginas foi liberada
*/
void DestroiListaPagina(ListaPagina *l);

/* Retorna uma pagina da lista de paginas, buscando pelo nome
*  inputs: A lista de paginas e o nome da pagina 
*  output: Ponteiro para a pagina
*  pre-condicao: A lista de paginas existir
*  pos-condicao: A lista de pagina nao e modificada
*/
Pagina * RetornaPagina(ListaPagina *l, char * nome);


/* Imprime uma unica pagina da lista de pagina, com suas contribuicoes e links
*  inputs: Lista de paginas e o nome da pagina que deseja imprimir
*  output: Nenhum
*  pre-condicao: A lista de pagina existe
*  pos-condicao: nenhuma
*/
void imprimePaginaCompleta(ListaPagina *l, char *nome);

/* Retorna o ponteiro para a lista de contribuicoes da pagina
*  inputs: Lista de paginas e o nome da pagina
*  output: Ponteiro para a lista de contribuicoes da pagina
*  pre-condicao: A lista de paginas existe
*  pos-condicao: nenhuma
*/
ListaContribuicao * RetornaListaContribuicaoPagina(ListaPagina *l,char *pagina);

/* Retorna o ponteiro para a lista de links da pagina
*  inputs: Lista de paginas e o nome da pagina
*  output: Ponteiro para a lista de links da pagina
*  pre-condicao: A lista de paginas existe
*  pos-condicao: nenhuma
*/
ListaLink * RetornaListaLinkPagina(ListaPagina *l,char *pagina);

/* Confere se a pagina existe na lista de paginas do wiked
*  inputs: Lista de paginas e o nome da pagina
*  output: retorna 1 se a pagina for encontrada e 0 se nao for encontrada
*  pre-condicao: A lista de paginas existe
*  pos-condicao: nenhuma
*/
int ConfereExistenciaPagina(ListaPagina *p, char *nome);

/* Gera os arquivos de todas as paginas do wiked
*  inputs: Lista de paginas
*  output: Nenhum
*  pre-condicao: A lista de paginas existe
*  pos-condicao: nenhuma
*/
void ImprimeWikEd(ListaPagina *l);

/* Retorna o ponteiro para a lista de links da pagina usando a 'posição'
*  da pagina na lista
*  inputs: Lista de paginas e o um inteiro que indica a posição
*  output: Ponteiro para a lista de links da pagina
*  pre-condicao: A lista de paginas existe
*  pos-condicao: nenhuma
*/
ListaLink * RetornaListaLinkPaginaPelaPosicao(ListaPagina *l,int pos);


/* Percorre todas as paginas da lista de paginas e apaga os links
*  de uma pagina que foi retirada.
*  inputs: Lista de paginas e um ponteiro para char com o nome da pagina retirada
*  output: nenhum
*  pre-condicao: A lista de paginas existe
*  pos-condicao: nenhuma
*/
void ApagaLinksDeUmaPagina(ListaPagina * listaPaginas,char * PaginaRetirada);

#endif