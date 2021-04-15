#ifndef Professor_h
#define Professor_h
typedef struct professor Professor;

Professor * IniciaProfessor(int siape, char * nome, float salario);

void ImprimeProfessor(Professor * prof);

int RetornaSiape(Professor *prof);

char* RetornaNomeProf(Professor *prof);

float RetornaSalario(Professor *prof);

void DestroiProfessor(Professor *prof);


#endif