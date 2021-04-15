#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char * nome;
    int matricula;
    float p1;
    float p2;
    float p3;

}; 

typedef struct aluno Aluno;

// Funcões pedidas no exercicio
void imprime_aprovados (int n, Aluno** turma);

float media_turma (int n, Aluno** turma);


// Outras funcoes
char * leNome();

float calculaMediaAluno(Aluno *aluno);

void imprimeAluno (int n, Aluno* turma);



void imprime_aprovados (int n, Aluno** turma){
    for(int i=0; i<n;i++){
        if(calculaMediaAluno(turma[i]) >= 5){
            imprimeAluno(n, turma[i]);
            // printf(" Media: %.2f\n",calculaMediaAluno(turma[i]));
        }
    }
    printf("\n");
}

float media_turma (int n, Aluno** turma){
    float media=0;
    for(int i=0; i< n; i++){
        media += calculaMediaAluno(turma[i]);
    }
    media = media / n;
   return media;
}



void imprimeAluno (int n, Aluno* turma){
    printf("%s ", turma->nome);
    printf("%d ", turma->matricula);
    printf("%.2f ", turma->p1);
    printf("%.2f ", turma->p2);
    printf("%.2f", turma->p3);
    
}

float calculaMediaAluno(Aluno *aluno){
    return (aluno->p1 + aluno->p2 + aluno->p3) / 3;
}

char * leNome(){
    char nome[121];
    setbuf(stdin,NULL);
    scanf("%121[^\n]", nome);
    setbuf(stdin,NULL);
    return strdup(nome);
}

int main() {
    int n;
    printf("Qual a quantidade de alunos da turma? ");
    scanf("%d", &n);
    Aluno** turma = (Aluno **)malloc(n * sizeof(Aluno*));

    for(int i=0; i < n; i++){
        turma[i] = (Aluno *)malloc(sizeof(Aluno));
        printf("Digite o nome do aluno: ");
        turma[i]->nome = leNome();
        printf("Digite a matricula do aluno: ");
        scanf("%d", &turma[i]->matricula);
        printf("Digite as notas do aluno:\n");
        printf("P1: ");
        scanf("%f", &turma[i]->p1);
        printf("P2: ");
        scanf("%f", &turma[i]->p2);
        printf("P3: ");
        scanf("%f", &turma[i]->p3);
    }
    printf("-----------ALUNOS DA TURMA-----------\n");
    for(int i=0; i< n; i++){
        imprimeAluno(n, turma[i]);
        printf("\n");
    }

    printf("\n-----------ALUNOS APROVADOS-----------\n");
    
    imprime_aprovados(n, turma);

    printf("\nMedia da turma: ");

    printf("%.2f\n",media_turma(n, turma));


    // Liberando memória alocada

    for (int i=0; i< n; i++){
        free(turma[i]->nome);
        free(turma[i]);
    }
        free(turma);
    return 0;
}