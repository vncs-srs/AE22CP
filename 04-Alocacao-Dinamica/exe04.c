#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int n;
    int *item;
}Vetor;
Vetor* iniciar_vetor(int n)
{
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->n = n;
    v->item = (int*) malloc(sizeof(int) * n);

    return v;
}

int main(void)
{
    int i;
    Vetor *x = iniciar_vetor(50);
    printf("\nTamanho do Vetor: %d\n",x->n);
    for ( i = 0; i < 50; i++)
    {
        printf("%d ",x->item[i]);
    }

    return 0;
}
