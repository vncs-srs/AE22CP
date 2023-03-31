/*Implemente uma função que receba duas matrizes de números inteiros com dimensões iguais. 
A função deverá retornar uma matriz (int**), alocada dinamicamente, resultante da soma 
das duas matrizes de entrada.

Input Format
Na primeira linha devem ser lidos dois números inteiros: um para a quantidade de linhas 
(l) e outro para a quantidade de colunas (c).

Em seguida, ler o conteúdo de duas matrizes lxc.
Constraints
.
Output Format
Imprimir o conteúdo da matriz resultante da soma.

Sample Input 0
3 3
1 2 3
1 2 3
1 2 3
4 5 6
3 2 1
1 1 1

Sample Output 0
5 7 9
4 4 4
2 3 4

Explanation 0

Primeira matriz:
1 2 3 1 2 3 1 2 3

Segunda matriz:
4 5 6 3 2 1 1 1 1*/

#include <stdio.h>
#include <stdlib.h>

// Função que recebe duas matrizes de números inteiros com dimensões iguais e retorna uma matriz resultante da soma das duas matrizes de entrada.
int **soma_matrizes(int **matriz1, int **matriz2, int l, int c) 
{
    // Aloca dinamicamente uma nova matriz para armazenar a soma das duas matrizes de entrada.
    int **matriz_soma = (int **) malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++) 
    {
        matriz_soma[i] = (int *) malloc(c * sizeof(int));
        // Soma os elementos correspondentes das duas matrizes de entrada e armazena o resultado na nova matriz.
        for (int j = 0; j < c; j++) 
        {
            matriz_soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    // Retorna a nova matriz resultante da soma das duas matrizes de entrada.
    return matriz_soma;
}

int main(void) 
{
    int l, c;
    // Lê as dimensões das matrizes de entrada.
    scanf("%d %d", &l, &c);

    // Aloca dinamicamente a primeira matriz de entrada e lê seus elementos.
    int **matriz1 = (int **) malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++) 
    {
        matriz1[i] = (int *) malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) 
        {
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Aloca dinamicamente a segunda matriz de entrada e lê seus elementos.
    int **matriz2 = (int **) malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++) 
    {
        matriz2[i] = (int *) malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) 
        {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Chama a função que soma as duas matrizes de entrada e armazena o resultado em uma nova matriz.
    int **matriz_soma = soma_matrizes(matriz1, matriz2, l, c);

    // Imprime o conteúdo da nova matriz resultante da soma das duas matrizes de entrada.
    for (int i = 0; i < l; i++) 
    {
        for (int j = 0; j < c; j++) 
        {
            printf("%d ", matriz_soma[i][j]);
        }
        printf("\n");
    }

    return 0;
}