/*Gladstone está desenvolvendo um jogo simples de RPG em que há batalhas, os quais são por turnos, onde, 
em cada luta, os jogadores se revezam em cada ataque. Cada personagem, além do nome (string), tem os seguintes 
atributos representados por números inteiros: energia, defesa e força. Em cada ataque, a energia do personagem 
que está sofrendo o golpe é reduzida. O dano (redução de energia) é dado pela subtração entre o atributo de 
força (F) do atacante e o atributo de defesa do personagem atacado, o qual pode ter redução de energia. Caso 
a diferença entre força (atacante) e defesa (atacado) seja menor igual a zero, o dano será de 1 ponto. Se o 
dano resultar em energia negativa, o valor da mesma para o personagem derrotado deverá ser "0". Em cada batalha,
o perdedor será o personagem que tiver a energia zerada ou que tiver o menor valor de energia. Também, poderá 
ocorrer empate. É importante ressaltar que o personagem com energia zerada não pode mais atacar!

Implemente uma função que receba duas variáveis referentes aos personagens e um número inteiro que represente 
a quantidade de turnos, onde o primeiro personagem fornecido como parâmetro começa o ataque. Ao final, a função
deverá imprimir o resultado, indicando o nome personagem vencedor ou se houve empate.

Input Format
Nas duas primeiras linhas, devem ler lidos os dados dos personagens. "nome (vetor de char) energia (int) defesa 
(int), força (int)".
Na linha seguinte, deve ser lida a quantidade de rodadas que deverá ter a batalha.

Constraints
.
Output Format
Na primeira e segunda linha, imprimir o nome e a energia restante do primeiro e do segundo personagem, após
a execução das rodadas de ataques.

Na terceira lunha, imprimir o nome do personagem vencedor ou "empate", caso os personagens tiverem a mesma 
quantidade de energia (neste exercício não levando em conta que os personagens possam iniciar uma batalha 
com diferentes valores de energia).

Sample Input 0
idril 1000 200 150
gidal 1000 100 300
5
Sample Output 0

idril 500
gidal 750
gidal
Sample Input 1

jilian 600 100 50
endric 600 100 50
6
Sample Output 1

jilian 594
endric 594
empate
Sample Input 2

paladriel 800 75 150
orcson 800 100 90
8
Sample Output 2

paladriel 680
orcson 400
paladriel
Sample Input 3

et_bilu 800 300 1200
orcson 800 100 90
8
Sample Output 3

et_bilu 800
orcson 0
et_bilu*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dim 10

typedef struct personagem
{
    char nome[100];
    int energia;
    int defesa;
    int forca; 
}Personagem;

Personagem dano (Personagem v1)
{

}

int main(void)
{
    int i;

    Personagem vetor_p[dim];
    
    for ( i = 0; i < dim; i++)
    {
        scanf("%s",vetor_p[i].nome);
        scanf("%d",&vetor_p[i].energia);
        scanf("%d",&vetor_p[i].defesa);
        scanf("%d",&vetor_p[i].forca);
    }
    



    return 0;
}



