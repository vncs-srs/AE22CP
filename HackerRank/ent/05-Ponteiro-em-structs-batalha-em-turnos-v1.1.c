/*Após ter o protótipo de jogo de RPG aprovado pelo CEO de uma 
importante empresa de games, Gladstone decide fazer melhorias 
na jogabilidade. Dessa vez o jogo deverá ter mais recursos. 
Consequentemente, a estrutura de cada personagem deve ter os 
seguintes campos: nome, energia, defesa, força e três golpes 
diferentes (A1, A2, A3), sendo cada um com um valor diferente. 
Após a execução de um golpe, o dano é dado pela seguinte equação:

Caso o valor da equação acima for negativo, o dano será de 1 ponto 
apenas. Em cada batalha, o perdedor será o personagem que tiver a 
energia zerada ou que tiver o menor valor de energia. Também, poderá 
ocorrer empate. É importante ressaltar que o personagem com energia 
zerada não pode mais atacar!

O jogo também tem mais novidades novidades: o personagem, em vez de 
atacar, pode tomar uma poção de cura, que restaura 200 pontos; quem 
inicia o ataque não é necessariamente o primeiro personagem; o valor 
máximo de energia é 1000 (personagem completamente saudável).

Implemente funções para o gerenciamento de batalha entre dois personagens.
Para isso, devem ser utilizados ponteiros de structs. Exemplo de protótipos:

void reduzir_energia(Tipo *p, int pontos_dano); // reduz pontos_dano 
pontos na saúde do personagem (valor mínimo de saúde: 0)

void restaurar(Tipo *p); // aumenta 200 pontos na saúde do 
personagem (valor máximo de saúde: 1000)

Input Format
Nas duas primeiras linhas, devem ler lidos os dados dos personagens. 
Cada uma das duas primeiras linhas tem a seguinte seguência: "nome (
vetor de char) energia (int) defesa (int), força (int), ataque 1 
(int), ataque 2 (int), ataque 3 (int)""

Na linha seguinte, deve ser lida a quantidade de ações (N) que deverá ter a batalha.

A leitura das próximas N linhas devem ser no formato: "P A" (o personagem toma 
uma poção de cura) ou P A G (o personagem realiza um ataque), onde:

P: do tipo inteiro, representa o personagem que executa a ação. O valor pode 
ser 1 (primeiro persongem lido) ou 2

A: é um caractere que representa uma ação, que pode ser "C" (cura) ou "A" ataque.

Caso a ação representada pelo caractere "A", ainda deverá ser definido qual 
dos 3 três golpes possíveis deve ser executado, ou seja, o valor deve ser 1, 2 ou 3

Constraints
.
Output Format

Na primeira e segunda linha, imprimir o nome e a energia restante do primeiro e 
do segundo personagem, após a execução das rodadas de ataques.

Na terceira lunha, imprimir o nome do personagem vencedor ou "empate", caso os 
personagens tiverem a mesma quantidade de energia (neste exercício não levando 
em conta que os personagens possam iniciar uma batalha com diferentes valores 
de energia).

Sample Input 0
idril 1000 200 150 10 20 30
gidal 1000 100 300 20 25 15
8
1 A 3
2 A 2
1 A 2
2 A 1
1 A 1
2 A 3
1 C
2 A 3

Sample Output 0
idril 725
gidal 790
gidal

Sample Input 1
jilian 1000 150 50 50 30 40
endric 1000 150 50 35 50 40
2
1 C
2 C

Sample Output 1
jilian 1000
endric 1000
empate*/


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
    int A1,A2,A3; 
}Personagem;

void reduzir_energia(Personagem *p, int pontos_dano)
{
    int dano=pontos_dano-p->defesa;

    if (dano <= 0) 
    {
        dano = 1;
    }
    p->energia -= dano;
    if (p->energia < 0) 
    {
        p->energia = 0;
    }
}

void restaurar(Personagem *p)
{
    p->energia=p->energia+200;

    if (p->energia>1000)
    {
        p->energia=1000;
    }
    
}
void atacar(Personagem *atacante, Personagem *atacado) 
{
    int golpe,p,pontos_dano;
    char opcao;
    scanf ("%d ",&p);
    scanf("%c",&opcao);

    switch (opcao)
    {
    case 'A':
        scanf("%d",&golpe);

        switch (golpe)
        {
        case 1:
            pontos_dano = atacante->A1 + atacante->forca;
            reduzir_energia(atacado,pontos_dano);
            break;
        case 2:
            pontos_dano = atacante->A2 + atacante->forca;
            reduzir_energia(atacado,pontos_dano);
            break;
        case 3:
            pontos_dano = atacante->A3 + atacante->forca;
            reduzir_energia(atacado,pontos_dano);
            break;
        
        default:
            break;
        }
        break;
    case 'C':
        restaurar(atacante);
        break;
    default:
        break;
    }
    
}

//Funcao batalha chama a funcao ataque a cada rodada e mostra o vencedor
void batalha(Personagem *p1, Personagem *p2, int turnos) 
{
    int i;
    for (i = 0; i < turnos; i++) 
    {

        if (i % 2 == 0)
        {
            atacar(p1, p2);
        } 
        if (p2->energia<=0)
        {
            break;
        }
        else
        {   
            atacar(p2, p1);
        }
        
    }
    if (p1->energia == p2->energia) 
    {
        printf("%s %d\n", p1->nome, p1->energia);
        printf("%s %d\n", p2->nome, p2->energia);
        printf("empate\n");
    } 
    else if (p1->energia > p2->energia) 
    {
        printf("%s %d\n", p1->nome, p1->energia);
        printf("%s %d\n", p2->nome, p2->energia);
        printf("%s\n", p1->nome);
    } 
    else 
    {
        printf("%s %d\n", p1->nome, p1->energia);
        printf("%s %d\n", p2->nome, p2->energia);
        printf("%s\n", p2->nome);
    }

}

int main(void)
{
    int turnos,i;

    Personagem vetor_p[dim];
    
    //Entrada de dados dos personagens
    for ( i = 0; i < dim; i++)
    {
        scanf("%s %d %d %d %d %d %d",vetor_p[i].nome,&vetor_p[i].energia,&vetor_p[i].defesa,&vetor_p[i].forca,&vetor_p[i].A1,&vetor_p[i].A2,&vetor_p[i].A3);  
    }
    
    scanf("%d", &turnos);
    batalha(&vetor_p[0], &vetor_p[1],turnos);

    return 0;

}