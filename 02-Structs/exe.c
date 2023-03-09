#include <stdio.h>

typedef struct aluno
{
    char nome[101];
    int RA;
    float coef;
}Aluno;

int main(void)
{
    Aluno a = {"Renato", 1234567, 0.986};
    printf("%s - %d - %f\n", a.nome, a.RA, a.coef);
    Aluno b = a;
    printf("%s - %d - %f\n", b.nome, b.RA, b.coef);
    return 0;
}
