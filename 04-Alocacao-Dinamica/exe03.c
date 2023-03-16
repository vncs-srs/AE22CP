#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int item[100];
    int quantidade;
}Vetor;

Vetor* iniciar_vetor()
{
    int i;
    Vetor* v = (Vetor*) malloc(sizeof(Vetor)); // e se usarmos calloc?
    
    /*v->quantidade = 0;
    
    for (i = 0; i < 100; i++)
    v->item[i] = 0;*/

    return v;
}

int main(void)
{
    int i;
    Vetor *x = iniciar_vetor();
    printf("\nQuantidade: %d\n",x->quantidade);
    for ( i = 0; i < 100; i++)
    {
        printf("%d ",x->item[i]);
    }
    




    return 0;
}
