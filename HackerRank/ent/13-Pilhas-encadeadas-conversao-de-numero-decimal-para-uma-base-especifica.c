/*Implemente um número que receba dois números inteiros: número na base decimal (n) e a base (b). 
A função deverá retornar uma pilha encadeada resultante da conversão de n na base b.

Para a implementação do exercício, utilize um TAD de pilhas encadeadas, podendo ser um dos códigos 
que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Ler dois números inteiros na seguinte sequência: número na base decimal e a base em que o número decimal 
será convertido.

Constraints

1 - Para acessar um elemento na pilha, deve ser utilizada a função desempilhar ou implementar uma função 
que retorne o elemento que está no topo da pilha. Para inserir um elemento na pilha, deve ser utilizada 
a função empilhar.

2 - o número que representa a base deve estar entre a seguinte faixa de valores: 2 <= b <= 16.

Output Format
Imprimir o número convertido na base b esvaziando a pilha encadeada.

Sample Input 0
35 2

Sample Output 0
100011

Sample Input 1
1550 16

Sample Output 1

60e*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para representar células
struct Cell{
    int item; // Pode ser uma struct, union, ou quanquer tipo de dados. 
              // Para possibilitar o reuso dessa célula para qualquer 
              // tipo de informação, recomendo o uso de ponteiro 
              // genérico. Exemplo: void* item;
    Cell *next;
};

typedef struct Cell Cell; // Renomeação da struct Cell

typedef struct PilhaE PilhaE;  // Renomeação da struct PilhaE

// Cria uma nova célula
Cell* criar_celula(int key);

// Função para criar uma pilha encadeada
PilhaE* criar_pilhaE();

// Retorna 1 se a pilha está vazia ou 0, caso contrário
int pilhaE_vazia(PilhaE *p);

// Inserir, no topo de uma pilha, um novo elemento
void empilhar(int key, PilhaE *p);

// Remover um item do topo da pilha
int desempilhar(PilhaE *p);

// Retorna o valor que está no topo. Caso a pilha estiver vazia, será retornado INT_MIN.
int acessar_valor_topo(PilhaE *p);

// Imprimir conteúdo da pilha
void imprimir_pilha(PilhaE *p);

// Desalocar pilha
int liberar_pilha(PilhaE *p);

// Estrutura de dados para representar uma pilha
struct PilhaE{
    Cell *topo;
};


// Cria uma nova célula
Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Função para criar uma pilha encadeada
PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


// Retorna 1 se a pilha está vazia ou 0, caso contrário
int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


// Inserir, no topo de uma pilha, um novo elemento
void empilhar(int key, PilhaE *p){
    Cell *aux; // Nova célula

    // Caso a pilha encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (p == NULL)
        p = criar_pilhaE();

    // Criar nova célula
    aux = criar_celula(key);

    // Apontar a nova célula para o topo da pilha
    aux->next = p->topo;

    // Atualizar topo da pilha
    p->topo = aux;
}


// Remover um item do topo da pilha
int desempilhar(PilhaE *p){
    Cell *aux; // Topo da pilha a ser removido
    int item = INT_MIN; // Valor que está no topo

    if (!pilhaE_vazia(p)){
        // obter a célula do topo da pilha
        aux = p->topo;
        
        // Acessar o conteúdo da célula
        item = aux->item;

        // Atualizar o topo da pilha
        p->topo = aux->next;

        // Liberar a célula desempilhada
        free(aux);
    }

    return item;
}


// Retorna o valor que está no topo. Caso a pilha estiver vazia, será retornado INT_MIN.
int acessar_valor_topo(PilhaE *p){
    if (!pilhaE_vazia(p))
        return p->topo->item;
    else
        return INT_MIN;
}

// Imprimir conteúdo da pilha
void imprimir_pilha(PilhaE *p){
    Cell *aux; // Para percorrer a pilha, deve ser utilizada
    	       // uma variável auxiliar para não perder o
    	       // topo da pilha

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }
        
        printf("\n");
    }
}


// Desalocar pilha
int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}


int main(void)
{
    int num, dec, base;
    PilhaE *p1 = criar_pilhaE();

    scanf("%d",&num);
    scanf("%d",&dec);
    scanf("%d",&base);

    empilhar(num,p1);




    liberar_pilha(p1);

    return 0;
}