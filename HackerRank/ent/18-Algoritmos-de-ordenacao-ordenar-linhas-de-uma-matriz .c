/*Implemente uma função que receba uma matriz de números inteiros. A função deverá ordenar, 
em ordem decrescente, cada linha da matriz.

Input Format
Na primeira linha, devem ser lidos dois números inteiros: l (linhas) e c (colunas).
Para cada uma das l linhas seguintes devem ser lidos c números inteiros.

Constraints
.
Output Format
Imprimir a matriz com as linhas ordenadas.

Sample Input 0
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Sample Output 0
4 3 2 1
8 7 6 5
12 11 10 9
16 15 14 13*/

#include <stdio.h>
#include <stdlib.h>

void ordenarLinhas(int matriz[][100], int l, int c) {
    for (int i = 0; i < l; i++) {
        // Algoritmo de ordenação 
        for (int j = 0; j < c - 1; j++) {
            for (int k = j + 1; k < c; k++) {
                if (matriz[i][k] > matriz[i][j]) {
                    // Troca os elementos
                    int aux = matriz[i][j];
                    matriz[i][j] = matriz[i][k];
                    matriz[i][k] = aux;
                }
            }
        }
    }
}

int main(void) {
    int l, c;
    scanf("%d %d", &l, &c);

    int matriz[l][c];

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    ordenarLinhas(matriz, l, c);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
