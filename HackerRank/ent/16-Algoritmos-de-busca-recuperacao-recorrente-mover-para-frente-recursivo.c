/*Implemente uma função que receba um arranjo de números inteiros. Nessa função deverá ser implementado, 
utilizando recursão, o método de recuperação recorrente mover-para-frente, no qual, cada vez que um 
registro é recuperado com sucesso, ele é movimentado para a primeira posição.

Input Format
Na primeira linha, ler um número inteiro (n) referente ao tamanho do arranjo.
Na segunda linha, ler os n elementos do vetor
Na terceira linha deve ser lida a quantidade de chaves que deverão ser procuradas). A partir da próxima 
linha, as chaves que serão procuradas devem ser lidas.

Constraints
.
Output Format
Após execução do algoritmo para cada caso teste, imprimir o arranjo.

Sample Input 0
14
1 2 3 4 5 6 7 8 9 10 11 12 13 14
8
1
6
7
6
6
0
6
7

Sample Output 0
7 6 1 2 3 4 5 8 9 10 11 12 13 14*/

#include <stdio.h>
#include <stdlib.h>

int mover_para_frente(int x, int v[], int n)
{
	int i, aux;

	for (i = 0; i < n && x != v[i]; i++);

	if (i < n){
		aux = v[i];

       	// Os elementos devem ser deslocados para para que o registro
      		// com a chave x possa ser colocado na primeira posição
        	for (i; i > 0; i--)
			v[i] = v[i - 1];

		// i é igual a zero
		v[i] = aux;

		return 0;
	}

	return -1;
}

void arranjo_rec(int v[],int n, int vkey[],int key)
{
    void procurar(int key)
    {
        mover_para_frente(key,v,n);
    }
    for (int i = 0; i < key; i++)
    {
        procurar(vkey[i]);
    }
}

int main(void)
{
    int n,i,key;
    scanf("%d",&n);
    int v[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&v[i]);
    }
    scanf("%d",&key);
    int vkey[key];
    for ( i = 0; i < key; i++)
    {
        scanf("%d",&vkey[i]);
    }
    arranjo_rec(v,n,vkey,key);

    for ( i = 0; i < n; i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
    

    return 0;
}