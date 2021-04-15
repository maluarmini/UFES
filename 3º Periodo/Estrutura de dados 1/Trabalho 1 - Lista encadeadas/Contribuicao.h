#ifndef Contribuicao_h
#define Contribuicao_h

// Tipo contribuicao (tipo opaco)
typedef struct contribuicao Contribuicao;

/* Inicializa uma contribuicao com o nome do editor e nome do arquivo
*  inputs: Nome do editor e nome do arquivo
*  output: Ponteiro para a contribuicao inicializada
*  pre-condicao: nome do editor e nome do arquivo validos
*  pos-condicao: Contribuc existe e contem o nome e nome do arquivo
*/
Contribuicao * IniciaContribuicao(char *nomeEditor, char * nomeArquivo);

/* Retorna o nome do arquivo de contribuicao
*  inputs: A contribuicao 
*  output: Ponteiro para o nome do arquivo de ocntribuicao
*  pre-condicao: A contribuicao existir
*  pos-condicao: A contribuicao nao e modificada
*/
char * RetornaNomeArquivoContribuicao(Contribuicao *c);

/* Atualiza o status da retirada da contribuicao para 1
*  inputs: A contribuicao 
*  output: nenhum
*  pre-condicao: A contribuicao existir
*  pos-condicao: A contribuicao com o status de retira = 1
*/
void ContribuicaoRetirada(Contribuicao *c);

/* Retorna o status da contribuicao
*  inputs: A contribuicao 
*  output: um inteiro para indicar se ela ja foio removida ou nao
*  pre-condicao: A contribucao existir
*  pos-condicao: A contribuicao nao e modificada
*/
int RetornaStatusContribuicao(Contribuicao *c);

/* Retorna o nome do editor da contribuicao
*  inputs: A contribuicao 
*  output: o nome do editor da contribuicao
*  pre-condicao: A contribucao existir
*  pos-condicao: A contribuicao nao e modificada
*/
char * RetornaNomeEditorContribuicao(Contribuicao *c);

/* Imprime uma contribuicao
*  inputs: A contribuicao 
*  output: nenhum
*  pre-condicao: A contribuicao existir
*  pos-condicao: nenhuma
*/
void ImprimeContribuicao(Contribuicao *c);

/* Libera a memória alocada para a pagina
*  inputs: A pagina 
*  output: nenhum
*  pre-condicao: A pagina existir
*  pos-condicao: Toda a memoria alocada para a pagina foi liberada
*/
void DestroiContribuicao(Contribuicao *c);

#endif