/*Implemente a função que receba quatro parâmetros: número inteiro a ser procurado, 
vetor de inteiros (v[] ou *v), tamanho do vetor (n) e um número inteiro representando 
tamanho mínimo (m). Nessa função, enquanto o espaço de busca (espaço coberto entre os 
índices esquerdo e direito em uma busca binária, ou seja, direito - esquerdo + 1) for 
maior que m, o método de busca binária deve ser aplicada. Quando o espaço de busca 
ficar menor ou igual a m, a busca sequencial deverá ser executada. Se a busca sequencial 
for aplicada, o espaço de busca deverá ser impresso (caso houver). Ao final a posição 
do item procurado no vetor é retornada. Caso o item não seja encontrado, a função deverá 
retornar -1.

Input Format
Na primeira linha deve ser lido um número inteiro que deverá ser procurado. Na segunda 
linha deve ser lido o tamanho do vetor. Na terceira devem ser lidos os elementos do vetor. 
Na quarta linha deve ser lida o tamanho mínimo da partição (m) para fazer a busca binária.

Constraints
.
Output Format
Na primeira linha deve ser impresso o subvetor referente ao espaço de busca a partir do momento 
em que a busca sequencial é executada. Na próxima linha deve ser impressa a posição retornada 
pela função.

Caso a busca sequencial não tenha sido executada, apenas a posição retornada pela função deve 
ser impressa.

Sample Input 0
1
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
4

Sample Output 0
1 2 3
0

Sample Input 1
4
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
4

Sample Output 1
3

Explanation 1
Como o item 4 é encontrado antes do espaço de busca ser menor que 4, apenas a sua respectiva posição 
é impressa.

Sample Input 2
17
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
5

Sample Output 2
13 14 15 16
-1*/

#include <stdio.h>
#include <stdlib.h>

int busca_sequencial(int x, int v[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (x == v[i])
			return i;
        else
            return -1;
}

int main(void)
{
    int num,dim,i;

    scanf("%d",&num);
    scanf("%d",&dim);

    int vetor[dim];
    for ( i = 0; i < dim; i++)
    {
        scanf("%d",&vetor[i]);
    }
    printf("%d\n",busca_sequencial(num,vetor,dim));
    
    return 0;
}