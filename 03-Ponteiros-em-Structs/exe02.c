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
    int x = 123;
    variavel.RA = &x;

    strcpy(variavel.nome, "Gil Away");

    printf("%s - %d - %f\n",variavel.nome,(*variavel.RA),variavel.coef);

    (*variavel.RA) = 321;


    printf("%s - %d - %f\n",variavel.nome,(*variavel.RA),variavel.coef);
    

    return 0;
}