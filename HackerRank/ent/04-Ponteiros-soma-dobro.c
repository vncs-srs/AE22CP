/*Implemente um programa que leia três valores do tipo float (A, B e C). 
Em seguida faça uma função que receba três ponteiros do tipo float. Essa 
função deverá dobrar o valor em cada ponteiro e retornar a soma desses 
valores dobrados.Exemplo: se a função receber ponteiros com os valores 
A=3.0, B=4.0 e C=0.0, ao final da execução da função, A=6.0, B=8.0 e 
C=0.0 e retorno será 14.0.

Input Format
A primeira linha contém um único inteiro N, indicando a quantidade 
de vezes que serão lidos os parâmetros da função.
Nas próximas N linhas, ler três valores do tipo float.

Constraints
.
Output Format
Para cada vez em que os parâmetros da função forem lidos deverá ser 
apresentada uma linha de saída no seguinte formato: "A=X B=Y C=Z 
SOMA=TOTAL", sendo todos com precisão de uma casa decimal.

Sample Input 0
4
3.0 4.0 0.0
0.5 7.2 2.0
10.0 0.1 0.2
-10.0 100.0 -1.3

Sample Output 0
A=6.0 B=8.0 C=0.0 SOMA=14.0
A=1.0 B=14.4 C=4.0 SOMA=19.4
A=20.0 B=0.2 C=0.4 SOMA=20.6
A=-20.0 B=200.0 C=-2.6 SOMA=177.4*/

#include <stdio.h>

void somadobro(float *X,float *Y,float *Z)
{
    float S;
    int i;
    for ( i = 0; i < 1; i++)
    {
        *X=(*X)*2;
        *Y=(*Y)*2;
        *Z=(*Z)*2;
    }
    S=(*X)+(*Y)+(*Z);
    
    printf("A=%.1f B=%.1f C=%.1f SOMA=%.1f\n",*X,*Y,*Z,S);
    
}

int main(void)
{
    float X,Y,Z;
    int N,i;

    scanf("%d",&N);
    for ( i = 0; i < N; i++)
    {
        scanf("%f %f %f",&X,&Y,&Z);
        somadobro(&X,&Y,&Z);
    }
    

    return 0;
}