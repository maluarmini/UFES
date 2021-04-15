#ifndef Editor_h
#define Editor_h

// Tipo editor (tipo opaco)
typedef struct editor Editor;

/* Inicializa um editor com o nome
*  inputs: Nome e nome do arquivo
*  output: Ponteiro para o Editor inicializado
*  pre-condicao: nome valido
*  pos-condicao: Editor existe e contem o nome
*/
Editor * IniciaEditor(char *nome);

/* Retorna o nome do editor
*  inputs: O editor
*  output: Ponteiro para o nome do editor
*  pre-condicao: Editor valido
*  pos-condicao: O editor nao e modificado
*/
char * RetornaNomeEditor(Editor *editor);

/* Imprime um editor
*  inputs: O editor 
*  output: nenhum
*  pre-condicao: O editor existir
*  pos-condicao: nenhuma
*/
void ImprimeEditor(Editor *editor);

/* Libera a memória alocada para o editor
*  inputs: O editor
*  output: nenhum
*  pre-condicao: O editor existir
*  pos-condicao: Toda a memoria alocada para o editor foi liberada
*/
void DestroiEditor(Editor *editor);

#endif