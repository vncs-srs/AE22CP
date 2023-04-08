/*Implemente uma função que receba duas listas estáticas (l1, l2).
 A função deverá retornar a posição lista l2 dentro de l1. Caso a 
 lista l2 não estiver na l1, retornar "-1".

Exemplo:

l1 = {1, 2, 3, 4, 5, 6, 7,** 8, 7, 6, 8**, 9, 10}

l2 = {8, 7, 6, 8}

No exemplo acima, l2 está (inicia) na posição 7 da lista l2.

Para a implementação do exercício, utilize um TAD de listas estáticas, 
podendo ser o código que foi apresentado em aula (disponível no repositório
da disciplina no GitHub).

Input Format

Na primeira linha, enquanto "-1" não for lido, ler números inteiros. Na 
segunda linha, a mesma restrição da primeira linha deve ser aplicada.

Constraints
.
Output Format
Imprimir a posição da lista l2 na l1.

Sample Input 0
1 2 3 4 5 6 7 8 7 6 8 9 10 -1
8 7 6 8 -1

Sample Output 0
7

Sample Input 1
1 2 3 4 5 6 7 8 7 6 8 9 10 -1
8 9 10 1 -1

Sample Output 1
-1

Sample Input 2
1 2 3 4 5 6 7 8 7 6 8 9 10 -1
1 2 3 4 -1

Sample Output 2
0

Sample Input 3
1 2 3 4 5 6 7 8 7 6 8 9 10 -1
8 9 10 -1
Sample Output 3

10*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct 
{
    int lista[MAX];
    int tamanho;
} Lista;

int busca(Lista *l1, Lista *l2) 
{
    int i, j;
    for (i = 0; i <= l1->tamanho - l2->tamanho; i++) 
    {
        for (j = 0; j < l2->tamanho; j++) {
            if (l1->lista[i + j] != l2->lista[j]) 
            {
                break;
            }
        }
        if (j == l2->tamanho) 
        {
            return i;
        }
    }
    return -1;
}

int main(void) 
{
    Lista l1, l2;
    int i;

    // Lendo a primeira lista
    for (i = 0; i < MAX; i++) 
    {
        scanf("%d", &l1.lista[i]);
        if (l1.lista[i] == -1) 
        {
            break;
        }
    }
    l1.tamanho = i;

    // Lendo a segunda lista
    for (i = 0; i < MAX; i++) 
    {
        scanf("%d", &l2.lista[i]);
        if (l2.lista[i] == -1) 
        {
            break;
        }
    }
    l2.tamanho = i;

    // Buscando a segunda lista na primeira
    int posicao = busca(&l1, &l2);
    if (posicao == -1) 
    {
        printf("-1\n");
    } else {
        printf("%d\n",posicao);
    }

    return 0;
}