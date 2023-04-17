/*Implemente uma função que receba um fila estática de números inteiros 
e uma chave, também do tipo inteiro. A função deverá inserir a chave na 
fila de forma os os elementos sejam mantidos ordenados em ordem descrescente. 
Para a inserção de novos elementos será necessário o uso uma fila auxiliar, 
já que apenas as operações de enfileirar e desenfileirar são permitidas para 
a manipulação dos elementos. Adicionalmente, pode ser usada/implementada uma 
função para verificar qual elemento está no início e no fim da fila.

Para a implementação do exercício, utilize um TAD de filas estáticas, podendo 
ser o código que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Enquanto "-1" não for lido, ler números inteiros.

Constraints

O acesso aos elementos da fila deve ser através da função desenfileirar.

Output Format

Imprimir a fila ordenada em ordem decrescente.

Sample Input 0
1 2 3 4 5 6 7 -1

Sample Output 0
7 6 5 4 3 2 1*/

#include <stdio.h>
#include <stdlib.h>



struct Fila
{
	int item[TAM_MAX];
	int ini; // posição do primeiro item
	int fim; // posição do último item
	int tam; // tamanho da fila
};

// Criar uma fila vazia
Fila* criar_fila()
{
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}