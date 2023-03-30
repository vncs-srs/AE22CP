/*Implemente uma função que receba uma matriz quadrática de números inteiros. 
A função deverá retornar um vetor (ponteiro) alocado dinamicamente com os 
elementos da diagonal principal da matriz.

Input Format
Na primeira linha deve ser lido um número inteiro N representando a dimensão 
da matriz.
Em seguida, ler os elementos de uma matriz NxN de números inteiros.

Constraints
.
Output Format

Em uma única, linha, imprimir o conteúdo do vetor com os elementos da diagonal 
da matriz.

Sample Input 0
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Sample Output 0
1 6 11 16*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    int *item;
}vetor;


vetor* diagonal(int matriz,int N)
{
    vetor* v = (vetor*) malloc(sizeof(vetor));
    v->n = matriz;
    v->item = (int*) malloc(sizeof(int) * N);
    return v;
}


int main(void)
{
    int N,i,j;

    scanf("%d",&N);

    int matriz[N][N];

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            scanf("%d",&matriz[i][j]);            
        }

    }   

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            if (i==j)
            {
                vetor *x = diagonal(matriz[i][j],N);
                printf("%d ",x->item[i]);
            }

        }
        
    }
    

    return 0;
}