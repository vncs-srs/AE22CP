#include <stdio.h>
#include "filaE.h"
#include "filaE.c"

int main()
{
    int x;
    FilaE* f;
    PilhaE* p;

    p = criar_pilhaE();
    f = criar_filaE();

    enfileirar(7,f);
    enfileirar(-13,f);
    enfileirar(18,f);
    enfileirar(-2,f);

    imprimir_fila(f);

    while (!filaE_vazia(f))
    {
        x = desempilhar(f);
        printf("x = %d\n",x);
        empilhar(x,p);
    }
    imprimir_filaE(f);
    liberar_filaE(f);
    liberar_pilha(p);

}