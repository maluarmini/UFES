#ifndef Pagina_h
#define Pagina_h

// Tipo pagina (tipo opaco)
typedef struct pagina Pagina;

/* Inicializa uma pagina com o nome e nome do arquivo
*  inputs: Nome e nome do arquivo
*  output: Ponteiro para a pagina inicializada
*  pre-condicao: nome e nome do arquivo validos
*  pos-condicao: Pagina existe e contem o nome e nome do arquivo
*/
Pagina * iniciaPagina(char *nome, char * nomeArq);

/* Retorna o nome da pagina
*  inputs: A pagina 
*  output: Ponteiro para o nome da pagina
*  pre-condicao: A pagina existir
*  pos-condicao: A pagina nao e modificada
*/
char * RetornaNomePagina(Pagina *p);

/* Retorna o nome do arquivo da pagina
*  inputs: A pagina 
*  output: Ponteiro para o nome do arquivo da pagina
*  pre-condicao: A pagina existir
*  pos-condicao: A pagina nao e modificada
*/
char * RetornaNomeArquivo(Pagina *p);

/* Imprime uma pagina
*  inputs: A pagina 
*  output: nenhum
*  pre-condicao: A pagina existir
*  pos-condicao: nenhuma
*/
void ImprimePagina(Pagina *p);

/* Libera a memória alocada para a pagina
*  inputs: A pagina 
*  output: nenhum
*  pre-condicao: A pagina existir
*  pos-condicao: Toda a memoria alocada para a pagina foi liberada
*/
void DestroiPagina(Pagina *p);

#endif