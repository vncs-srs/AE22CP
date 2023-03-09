#include <stdio.h>
#include <string.h>

typedef struct aluno{
char nome[101];
int RA;
float coef;
}Aluno;
 Aluno cadastra_aluno(char nome[101], int RA, float coef){
    Aluno a;
    strcpy(a.nome, nome);
    a.RA = RA;
    a.coef = coef;
    return a;
}
int main(void){
int i;
Aluno a = cadastra_aluno("Dona Maxima", 006671, 0.87);
return 0;
}