#ifndef ListaLink_h
#define ListaLink_h
#include "Pagina.h"

// Tipo listalink (tipo opaco)
typedef struct listalink ListaLink;

/* Inicializa uma lista de links
*  inputs: nenhum
*  output: Ponteiro para uma lista de links inicializada
*  pre-condicao: nenhuma
*  pos-condicao: Lista de links existe
*/
ListaLink * IniciaListaLink();

/* Insere um link(pagina) em uma lista de links
*  inputs: Lista de links e a pagina que sera linkada
*  output: nenhum
*  pre-condicao: A lista de links e a link serem validos 
*  pos-condicao: Lista de links com o link adicionado
*/
void InsereListaLink(ListaLink *lista,Pagina *link);

/* Retira um link da lista de links
*  inputs: Lista de links e nome do link a ser retirado
*  output: Nenhum
*  pre-condicao: A lista de links existir
*  pos-condicao: Lista de links com o link retirada
*/
void RetiraListaLink(ListaLink *l,char *chave);

/* Imprime uma lista de links
*  inputs: Lista de links
*  output: Nenhum
*  pre-condicao: A lista de links existe
*  pos-condicao: nenhuma
*/
void ImprimeListaLink(ListaLink *lista);

/* Libera a memória alocada para a lista de links
*  inputs: A lista de links 
*  output: nenhum
*  pre-condicao: A lista de links existir
*  pos-condicao: Toda a memoria alocada para a lista de links foi liberada
*/
void DestroiListaLink(ListaLink *lista);

/* Imprime a lista de links de uma pagina no arquivo
*  inputs: A lista de links e o ponteiro para o arq 
*  output: nenhum
*  pre-condicao: A lista de links existe e o arq ja foi aberto
*  pos-condicao: nenhuma
*/
void ImprimeListaLinksArquivo(ListaLink *lista, FILE *arq);

/* Função usada na funcionalidade CAMINHO
   Percorre uma lista de links(a atual), conferindo se as paginas que eu estou passando se encontram na lista de percorridos, caso ainda nao estejam nessa lista, eu retorno ela, pois significa que eu ainda nao passei por ela.
*  inputs: A lista de links atual e a lista de links percorridos
*  output: Retorna um ponteiro para a pagina, se encontra-lá ou NULL.
*  pre-condicao: nenhuma
*  pos-condicao: nenhuma
*/

Pagina * RetornaProximoLink(ListaLink* listaInicio, ListaLink * percorridos);

/* Percorre uma lista pra ver se encontra uma pagina com o nome do argumento
*  inputs: A lista de links e o nome da pagina
*  output: Retorna um ponteiro para a pagina, se encontra-lá ou NULL.
*  pre-condicao: A lista de links existe
*  pos-condicao: nenhuma
*/
Pagina * RetornaLinkLista(ListaLink * lista,char *nome);

/* Retorna 1 se a primeira celula da lista de links for NULL
*  inputs: A lista de links
*  output: inteiro
*  pre-condicao: A lista de links existe
*  pos-condicao: nenhuma
*/
int ConfereLista(ListaLink *l,ListaLink * percorridas);

#endif