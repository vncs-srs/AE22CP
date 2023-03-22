/*Implemente um programa que faça o controle do consumo de energia dos 
eletrodomésticos de um imóvel. Primeiro leia os N eletrodomésticos que 
contendo nome, potência (inteiro, em kW) e tempo ativo por dia (real, 
em horas). Em seguida, leia um número inteiro d (quantidade de dias) e calcule:

O consumo total no imovel
O consumo total de cada eletrodoméstico
O consumo relativo de cada eletrodoméstico ((consumo/consumo total) * 100)
nesse período de tempo.

Input Format
Na primeira linha deve ser lido o número de eletrodoméstico.

Para cada uma das N linhas seguintes, leia as seguintes informações 
para cada eletrodoméstico: nome (string), potencia (inteiro) e tempo (real).

Por fim, leia um número inteiro que represente a quantidade de dias.

Constraints

Não utize a função gets para ler as strings. Em vez disso, use scanf 
(nos casos de teste não há o caractere espaço em branco)

Output Format

A primeira linha deve exibir o consumo total no imóvel seguido de N 
linhas com o consumo relativo de cada eletrodoméstico.

Sample Input 0
3
Ferro 30 3
Chuveiro 60 0.5
TV 5 12
5

Sample Output 0
900
Ferro 50.0
Chuveiro 16.7
TV 33.3*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Eletrodomesticos
{
    char nome[5];
    float potencia;
    float tempo;
}eletrodomesticos;

int main(void)
{
    int n,i,d;
    float consumo_total;

    scanf("%d",&n);

    eletrodomesticos vetor_elet[n];

    for ( i = 0; i < n; i++)
    {
        scanf("%s %f %f",vetor_elet[i].nome,&vetor_elet[i].potencia,&vetor_elet[i].tempo);
    }

    scanf("%d",&d);

    for ( i = 0; i < n; i++)
    {
        float consumo = vetor_elet[i].potencia * vetor_elet[i].tempo *d;
        consumo_total +=consumo;
    }

    printf("%.2f\n",consumo_total);
    for ( i = 0; i < n; i++)
    {
        float consumo_reltativo = (vetor_elet[i].potencia * vetor_elet[i].tempo * d / consumo_total)*100;
        printf("%s %.1f\n",vetor_elet[i].nome, consumo_reltativo);
    }


    return 0;
}