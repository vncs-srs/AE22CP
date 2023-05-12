/*Implemente uma função recursiva que calcule o resto da divisão entre dois números inteiros.

Input Format
Na primeira linha deve ser lido um número inteiro N referente a quantidade de leituras de entradas.
Para cada uma das N próximas linhas, ler dois números inteiros (a e b)

Constraints
.
Output Format

Em cada uma das N linhas, imprimir o resultado do resto da divisão dos respectivos números inteiros.

Sample Input 0
5
1 2
6 7
8 6
0 20
23 6

Sample Output 0
1
6
2
0
5*/


#include <stdio.h>
#include <stdlib.h>


int resto_rec(int numerador,int divisor)
{
    if (numerador < divisor)
        return numerador;
    else
        return resto_rec(numerador-divisor, divisor);
}
void imprimir(int vetor[],int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d \n",vetor[i]);
    }
    
}


int main(void)
{
    int i,n,numerador,divisor;

    scanf("%d",&n);
    int vetor[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%d %d",&numerador,&divisor);
        vetor[i]=resto_rec(numerador,divisor);
    }
    imprimir(vetor,n);
    
    return 0;
}