/*Crie uma struct para representar um número racional, ou seja, nessa estrutura deve haver os seguintes campos: 
numerador e denominador.

Em seguida, crie uma função que receba dois números racionais. A função deverá retornar um outro número racional 
resultante da divisão dos números fornecidos como entrada.

Input Format
A primeira linha é composta pelo numerador e denominador, respectivamente, do primeiro número racional.
A segunda linha é composta pelo numerador e denominador, respectivamente, do segundo número racional.

Constraints
As entradas lidas devem ser armazenadas em varíaveis do tipo de estrutura que você criou.

Output Format
Número racional resultante da divisão dos números fornecidos como entrada.

Sample Input 0
1 2
3 4
Sample Output 0
4 6*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int x;
    int y;
}racional;

racional divide_rac(racional v1,racional v2)
{
    racional v3;

    v3.x=v1.x*v2.y;
    v3.y=v1.y*v2.x;

    return(v3);
} 

int main() 
{
    racional v1,v2,v3;  

    scanf("%d %d",&v1.x,&v1.y);  
    scanf("%d %d",&v2.x,&v2.y);   

    v3= divide_rac(v1,v2); 

    printf("%d %d",v3.x,v3.y);

    
    return 0;
}