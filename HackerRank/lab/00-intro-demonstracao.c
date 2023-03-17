/*Implemente um programa que receba dois números inteiros. A função deverá retornar a soma dos números.
Input Format
Na primeira linha devem ser lidos 2 números inteiros
Constraints
.
Output Format
A soma dos números deve ser impresso.
Sample Input 0
1 2
Sample Output 0
3*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//FUNCAO SOMA 

int soma(int num1, int num2)
{
    return(num1+num2);
}

int main() 
{
    int num1,num2;

    scanf("%d %d",&num1,&num2);

    printf("%d",soma(num1,num2));

    return 0;
}
