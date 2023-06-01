/**

Exercício: implementar uma função que converta uma matriz de números inteiros em uma matriz esparsa.
  
 */
#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

Spa_Mat* converterMatrizB_MatrizE(int *mat, int l, int c);

int main() {
    int matriz[][5] = {{1, 0, 0, 0, 1},{0, 2, 0, 2, 0},{0, 0, 3, 0, 0},{0, 4, 0, 4, 0},{5, 0, 0, 0, 5}};
    
    Spa_Mat *matrix = converterMatrizB_MatrizE((int *)matriz, 5, 5);

    imprimir(matrix);

    printf("\nExiste o elemento 45? %d\n",buscar(45, matrix));
    printf("\nExiste o elemento 3? %d\n",buscar(3, matrix));

    return 0;
}

Spa_Mat* converterMatrizB_MatrizE(int *mat, int l, int c){
    int i, j;
    Spa_Mat *matrix = criar(l, c);
    
    for (int i = 0; i < l; i++){
     for (int j = 0; j < c; j ++){
          if(*(mat + i*c + j) != 0)
               trocar(*(mat + i*c + j), i, j, matrix);
     }
    }
    return matrix;
}
