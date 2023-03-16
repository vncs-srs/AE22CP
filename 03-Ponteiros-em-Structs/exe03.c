#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[101];
    int *RA;
    float coef;
}Aluno;

int main(void)
{
    Aluno variavel;
    Aluno *ponteiro;
    int x = 123;

    
    printf("%s - %d - %f\n",variavel.nome,(*variavel.RA),variavel.coef);

    ponteiro = &variavel;

    (*ponteiro).RA = &x; // ou variavel.RA = &x
    (*ponteiro).coef = 0.57;
    *(*ponteiro).RA = 98765;

    strcpy(variavel.nome, "Gil Away");

    printf("%s - %d - %f\n",variavel.nome,(*variavel.RA),variavel.coef);


    return 0;
}