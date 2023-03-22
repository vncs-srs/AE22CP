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

#define dim 2

typedef struct personagem
{
    char nome[100];
    int energia;
    int defesa;
    int forca;
    int d1,d2; 
}Personagem;

//Calcula a vida restante de cada personagem
Personagem dano_vec ( int v1,Personagem v2)
{
    Personagem v3;
    v3.energia=v1-v2.forca;
    v3.defesa=v2.defesa;
    v3.forca=v2.forca;
    v3.d1=v2.d1;
    v3.d2=v2.d2;

    return(v3);
}

int main(void)
{
    int i,rodadas,defesa_total[dim];

    Personagem vetor_p[dim];
    Personagem danop1;
    Personagem danop2;
    
    //Entrada de dados dos personagens
    for ( i = 0; i < dim; i++)
    {
        scanf("%s %d %d %d",vetor_p[i].nome,&vetor_p[i].energia,&vetor_p[i].defesa,&vetor_p[i].forca);
        defesa_total[i]=vetor_p[i].energia+vetor_p[i].defesa;
    }
    danop1.energia=defesa_total[0];
    danop2.energia=defesa_total[1];

    //Entrada do numero de rodadas
    scanf("%d",&rodadas);

    //Verificar se dar empate atravez dos atributos (iguais)
    if ( danop1.d1==danop2.d2 && vetor_p[0].forca==vetor_p[1].forca)
    {
        printf("empate\n");
    }

    //Verificar em cada rodada se o pesonagem zerou os pontos de vida 
    else
    {
        for ( i = 0; i < rodadas; i++)
        {
            if (danop1.energia>0)
            {
                danop1=dano_vec(danop1.energia,vetor_p[i]);
            }
            else if (danop2.energia>0)
            {
                danop2=dano_vec(danop2.energia,vetor_p[i]);
            }
            else
            {
                break;
            }

        }

        printf("%s %d\n",vetor_p[0].nome,danop1);
        printf("%s %d\n",vetor_p[1].nome,danop2);
        
        //verifica o campeao
        if (danop1.energia>danop2.energia)
        {
            printf("%s\n",vetor_p[0].nome);
        }
        else
        {
            printf("%s",vetor_p[1].nome);
        }
        
    }
   



    return 0;
}



