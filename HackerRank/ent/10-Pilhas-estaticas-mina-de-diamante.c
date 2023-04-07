/*O Sr. Alcídes está trabalhando em uma mina para extrair o máximo que consegue de diamantes 
"<>". Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de 
diamante, novos diamantes poderão ser encontrados. Se ele tem como uma entrada .<...<<..>>
....>....>>>., três diamantes são formados: "O primeiro é retirado de "<..>", "<>" e "<.....
..>". Implemente uma função que receba uma string representado a carga com areia e diamante.
A função deverá retornar a quantidade de diamantes contidas na carga. Para a solução do problema
, deve ser utilizada uma pilha estática.

Para a implementação do exercício, utilize um TAD de pilhas estáticas, podendo ser um dos códigos
que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir 
é uma string que contém apenas os seguintes caracteres: "<", ">" e ".".

Constraints

Os elementos da pilha podem ser manipulados apenas utilizando funções de empilhar e desempilhar.

Output Format

A quantidade de diamantes possíveis de serem extraídos em cada caso de entrada deve ser impressa.

Sample Input 0*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct 
{
    int topo;
    char elem[MAX];
} Pilha;

void inicializa(Pilha *p) 
{
    p->topo = -1;
}

int vazia(Pilha *p) 
{
    return p->topo == -1;
}

int cheia(Pilha *p) 
{
    return p->topo == MAX - 1;
}

void empilha(Pilha *p, char c) 
{
    if (cheia(p)) 
    {
        printf("Erro: pilha cheia\n");
        exit(1);
    }
    p->topo++;
    p->elem[p->topo] = c;
}

char desempilha(Pilha *p) 
{
    if (vazia(p)) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    char c = p->elem[p->topo];
    p->topo--;
    return c;
}

int main(void) 
{
    int n;
    scanf("%d", &n);
    while (n--) {
        Pilha p;
        inicializa(&p);
        char s[MAX];
        scanf("%s", s);
        int diamantes = 0;
        for (int i = 0; s[i]; i++) 
        {
            if (s[i] == '<') 
            {
                empilha(&p, s[i]);
            } else if (s[i] == '>' && !vazia(&p)) 
            {
                desempilha(&p);
                diamantes++;
            }
        }
        printf("%d\n", diamantes);
    }
    
    return 0;
}