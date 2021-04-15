#ifndef ListaContribuicao_h
#define ListaContribuicao_h
#include "Contribuicao.h"

// Tipo lista contribuicao (tipo opaco)
typedef struct listacontribuicao ListaContribuicao;

/* Inicializa uma lista de contribuicoes
*  inputs: nenhum
*  output: Ponteiro para uma lista de contribuicoes inicializada
*  pre-condicao: nenhuma
*  pos-condicao: Lista de contribuicoes existe
*/
ListaContribuicao * IniciaListaContribuicao();

/* Insere uma contribuicao em uma lista de contribuicoes
*  inputs: Lista de editor e o editor
*  output: nenhum
*  pre-condicao: A lista de contribuicoes e a contribuicao serem validas 
*  pos-condicao: Lista de contribuicao com a contribuicao adicionada
*/
void InsereListaContribuicao(ListaContribuicao *lista,Contribuicao *c);

/* Retira uma contribuicao da lista de contribuicoes liberando e encadeando a lista
*  inputs: Lista de contribuicoes e nome da contribuicao a ser retirada
*  output: Nenhum
*  pre-condicao: A lista de contribuicoes e a contribuicao serem validas
*  pos-condicao: Lista de contribuicao com a contribuicao retirada
*/
void RetiraListaContribuicao(ListaContribuicao *l,char *chave);

/* Altera retira uma contribuicao apenas alterando o status dela, mantendo ela na lista
*  para o historico de contribuicoes das paginas
*  inputs: Lista de contribuicoes e nome da contribuicao a ser retirada
*  output: Nenhum
*  pre-condicao: A lista de contribuicoes e a contribuicao serem validas
*  pos-condicao: nenhuma
*/
void RetiraListaContribuicaoParaHistorico(ListaContribuicao *l,char *chave);

/* Imprime uma lista de contribuicao para o cliente (terminal)
*  inputs: Lista de contribuicao
*  output: Nenhum
*  pre-condicao: A lista de contribuicao existe
*  pos-condicao: nenhuma
*/
void ImprimeListaContribuicao(ListaContribuicao *lista,int id);

/* Imprime uma lista de contribuicao para no arquivo de saida
*  inputs: Lista de contribuicao
*  output: Nenhum
*  pre-condicao: A lista de contribuicao existe
*  pos-condicao: nenhuma
*/
void ImprimeListaContribuicoesParaHistorico(ListaContribuicao *lista, FILE * arq);

/* Imprime uma lista de contribuicao com os respectivos textos
*  inputs: Lista de contribuicao
*  output: Nenhum
*  pre-condicao: A lista de contribuicao existe
*  pos-condicao: nenhuma
*/
void ImprimeListaContribuicaoTextos(ListaContribuicao *lista, FILE * arq);

/* Faz uma copia do arquivo de contribuicao desejado para imprimir 
*  inputs: Um contribuicao e um ponteiro pro arquivo da pagina
*  output: Nenhum
*  pre-condicao: A contribuicao existe e o arquivo ja foi previamente aberto
*  pos-condicao: nenhuma
*/
void imprime(Contribuicao *c,FILE * arq);


/* Confere se a contribuicao existe na lista de contribuicao que esta sendo avaliada
*  inputs: Lista de contribuicao e o nome da contribuicao
*  output: retorna 1 se a contribuicao for encontrada e 0 se nao for encontrada
*  pre-condicao: A lista de contribuicao existe
*  pos-condicao: nenhuma
*/
int ConfereContribuicao(ListaContribuicao * l, char * chave);

/* Libera a memória alocada para a lista de contribuicoes
*  inputs: A lista de contribuicoes
*  output: nenhum
*  pre-condicao: A lista de contribuicoes existir
*  pos-condicao: Toda a memoria alocada para o lista de contribuicoes foi liberada
*/
void DestroiListaContribuicao(ListaContribuicao *lista);


#endif