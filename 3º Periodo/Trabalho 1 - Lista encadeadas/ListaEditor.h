#ifndef ListaEditor_h
#define ListaEditor_h
#include "Editor.h"
#include "ListaContribuicao.h"

// Tipo listaeditor (tipo opaco)
typedef struct listaeditor ListaEditor;

/* Inicializa uma lista de editores
*  inputs: nenhum
*  output: Ponteiro para uma lista de editores inicializada
*  pre-condicao: nenhuma
*  pos-condicao: Lista de editores existe
*/
ListaEditor * IniciaListaEditor();

/* Insere um editor em uma lista de editores
*  inputs: Lista de editor e o editor
*  output: nenhum
*  pre-condicao: A lista de editor e o editor serem validos 
*  pos-condicao: Lista de editor com o editor adicionado
*/
void InsereListaEditor(ListaEditor *l, Editor *ed);

/* Retira um editor da lista de editores
*  inputs: Lista de editores e nome da editor a ser retirado
*  output: Nenhum
*  pre-condicao: A lista de editores e o editor serem validos
*  pos-condicao: Lista de editor com o editor retirado
*/
void * RemoveEditor(ListaEditor *l,char *chave);

/* Imprime uma lista de editores
*  inputs: Lista de editor
*  output: Nenhum
*  pre-condicao: A lista de editor existe
*  pos-condicao: nenhuma
*/
void ImprimeListaEditor(ListaEditor *l);

/* Libera a memória alocada para a lista de editores
*  inputs: A lista de editores 
*  output: nenhum
*  pre-condicao: A lista de editores existir
*  pos-condicao: Toda a memoria alocada para o lista de editores foi liberada
*/
void DestroiListaEditor(ListaEditor *l);

/* Confere se o editor existe na lista de editores
*  inputs: Lista de editores e o nome do editor
*  output: retorna 1 se o editor for encontrado e 0 se nao for encontrado
*  pre-condicao: A lista de editores existe
*  pos-condicao: nenhuma
*/
int ConfereExistenciaEditor(ListaEditor *l, char *nome);

/* Retorna o ponteiro para a lista de contribuicoes do editor
*  inputs: Lista de editores e o nome do editor
*  output: Ponteiro para a lista de contribuicoes d o editor
*  pre-condicao: A lista de editor existe
*  pos-condicao: nenhuma
*/
ListaContribuicao * RetornaListaContribuicaoEditor(ListaEditor *l,char *editor);

/* Verifico se existe um editor com o nome passado no paramentro
*  na minha lista de editores
*  inputs: Lista de editores e nome do editor
*  output: se nao existe retorna 0, se existe retorna 1
*  pre-condicao: Lista de editores existe
*  pos-condicao: A lsita de editores nao e modificada
*/
int VerificaEditor(ListaEditor* l,char * nome);

#endif