#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"


int main() {

    Spa_Mat *matrix = criar(5, 5);

    trocar(1, 0, 0, matrix);
    trocar(2, 1, 1, matrix);
    trocar(3, 2, 2, matrix);
    trocar(4, 3, 3, matrix);
    trocar(5, 4, 4, matrix);

    trocar(1, 0, 4, matrix);
    trocar(2, 1, 3, matrix);
    trocar(3, 2, 2, matrix);
    trocar(4, 3, 1, matrix);
    trocar(5, 4, 0, matrix);

    imprimir(matrix);

    printf("\nExiste o elemento 45? %d\n",buscar(45, matrix));
    printf("\nExiste o elemento 3? %d\n",buscar(3, matrix));

    return 0;
}

