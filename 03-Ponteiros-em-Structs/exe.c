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

    (*ponteiro).RA = 98765;
    (*ponteiro).coef = 0.57;
    strcpy((*ponteiro).nome, "Gil Away");

    printf("%s - %d - %f\n",(*ponteiro).nome,(*ponteiro).RA,(*ponteiro).coef);

    printf("%s - %d - %f\n",variavel.nome,variavel.RA,variavel.coef);




    return 0;
}