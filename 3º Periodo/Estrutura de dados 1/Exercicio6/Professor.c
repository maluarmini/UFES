#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Professor.h"

struct professor{
    int siape;
    char *nome;
    float salario;
};

Professor * IniciaProfessor(int siape, char * nome, float salario){
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    professor->siape = siape;
    professor->salario = salario;
    professor->nome = strdup(nome);
    return professor;
}

void ImprimeProfessor(Professor * prof){
    printf("Nome: %s, Siape: %d, Salario: %.2f\n",prof->nome,prof->siape,prof->salario);
}

int RetornaSiape(Professor *prof){
    return prof->siape;
}

char* RetornaNomeProf(Professor *prof){
    return prof->nome;
}

float RetornaSalario(Professor *prof){
    return prof->salario;
}

void DestroiProfessor(Professor *prof){
    free(prof->nome);
    free(prof);
}