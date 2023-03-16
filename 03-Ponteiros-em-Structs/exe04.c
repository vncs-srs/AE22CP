#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[101];
    int RA;
    float coef;
}Aluno;

int main(void)
{
    Aluno variavel;
    Aluno *ponteiro;
    ponteiro = &variavel;
    ponteiro->RA = 12345;
    ponteiro->coef = 0.65;


    strcpy(ponteiro->nome, "Roberto");
   
    printf("%s - %d - %f\n",ponteiro->nome,ponteiro->RA,ponteiro->coef);
    
    
    return 0;
}