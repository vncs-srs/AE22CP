/*Considerando uma estrutura para representar um vetor no R2, implemente uma função que receba dois vetores de acordo com a estrutura e protótipo abaixo:

typedef struct{
    int x;
    int y;
}vetor_r2;

vetor_r2 soma_vec(vetor_r2 v1, vetor_r2 v2);

A função deverá retornar um vetor resultante da soma entre v1 e v2.
Input Format
Na primeira linha deverão ser lidos os campos referentes ao v1 (x e y).
Na segunda linha deverão ser lidos os campos referentes ao v2.
Constraints
.
Output Format
Imprimir o vetor resultante da soma entre v1 e v2.
Sample Input 0
2 4
1 2
Sample Output 0
3 6*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct //struct personalizada
{
    int x; 
    int y;
}vetor_r2; 

vetor_r2 soma_vec(vetor_r2 v1, vetor_r2 v2) //funcao soma_vec usa a struct personalisada vetor_r2 cuja a variavel sao v1 e v2
{
    vetor_r2 v3;

    v3.x=v1.x+v2.x;
    v3.y=v1.y+v2.y;

    return(v3);
}

int main() 
{
    vetor_r2 v1,v2,v3; // Declaracao das variaveis 

    scanf("%d %d",&v1.x,&v1.y);   // entrada de dados. v1.x significa que estar acessando cada espaco da memoria
    scanf("%d %d",&v2.x,&v2.y);   

    v3= soma_vec(v1,v2); //

    printf("%d %d",v3.x,v3.y);

    
    return 0;
}