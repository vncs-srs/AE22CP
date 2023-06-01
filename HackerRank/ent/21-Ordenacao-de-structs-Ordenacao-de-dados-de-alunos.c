/*Adapte um dos algorimos de ordenação para o vetor de elementos da seguinte estrutura:

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;
A ordenação deve ser por nome. Caso haja registros com o mesmo nome, o critério de ordenação nesse caso é a matrícula.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. A partir da segunda linha, ler os dados de cada elemento do vetor.

Constraints
.
Output Format

Imprimir os registro ordenados. Diferentemente da forma leitura, cada registro deve ser impresso em uma linha.

Sample Input 0
4
101
chinforoso
engenharia-de-computacao
0.73
205
joana
engenharia-eletrica
0.78
98
roberto
matematica
0.62
105
joana
historia
0.87

Sample Output 0
chinforoso 101 engenharia-de-computacao 0.73
joana 105 historia 0.87
joana 205 engenharia-eletrica 0.78
roberto 98 matematica 0.62*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;


int main(void)
{
    





    return 0;
}