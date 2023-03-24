/*Escreva uma função que receba três variáveis (altura, largura e comprimento) do tipo float 
para a representação de um paralelepípedo reto e três ponteiros do tipo float.
Nessa função, cada ponteiro deverá armazenar uma medida relacionada ao palalepípedo, como:
área = 

Input Format
Ler três variáveis do tipo float.

Constraints
A impressão dos floats deve considerar apenas uma casa decimal.

Output Format
Em cada linha, imprimir o conteúdo de um ponteiro seguido o seguinte padrão:
"area: valor"
"volume: valor"
"comprimento da diagonal: valor"

Sample Input 0
6.0 6.0 7.0

Sample Output 0
area: 240.0
volume: 252.0
comprimento da diagonal: 11.0*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula(float altura,float comprimento,float largura,float *area,float *volume,float *diagonal)
{
  
    *area=2*altura*largura+2*altura*comprimento+2*largura*comprimento;
    *volume=altura*largura*comprimento;
    *diagonal=pow(pow(altura,2)+pow(largura,2)+pow(comprimento,2),0.5);
}


int main (void)
{
    float altura,largura,comprimento;
    float area,volume,diagonal;
    
    scanf("%f %f %f",&altura,&largura,&comprimento);
    calcula(altura,largura,comprimento,&area,&volume,&diagonal);

    printf("area: %.1f\n", area);
    printf("volume: %.1f\n", volume);
    printf("comprimento da diagonal: %.1f\n", diagonal);

    return 0;
}