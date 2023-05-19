/*Implemente, utilizando recursão, um dos algoritmos de ordenação simples apresentados 
em sala de aula (bublesort, selection sort ou insertion sort) para a ordenação de uma 
lista encadeada de floats.

Input Format
Enquanto -1 não for lido, ler um float e colocá-lo na lista encadeada de floats.

Constraints
No seu código pode ter, no máximo, apenas um loop.

Output Format
Imprimir o contrúdo da lista ordenada.

Sample Input 0
3.0 8.0 5.0 9.0 1.0 2.0 4.0 6.0 -1

Sample Output 0
1.0 2.0 3.0 4.0 5.0 6.0 8.0 9.0*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell; // Renomeação da struct Cell

// Estrutura para representar células
struct Cell{
    float item; // Pode ser uma struct, union, ou qualquer tipo de dados.
              // Para possibilitar o reuso dessa célula para qualquer
              // tipo de informação, recomendo o uso de ponteiro
              // genérico. Exemplo: void* item;
    Cell *next;
};


// Estrutura para representar listas encadeadas
struct ListaE{
    Cell *head; // Ponteiro para o primeiro elemento da lista
};

typedef struct ListaE ListaE; // Renomeação da struct ListaE

// Cria uma nova célula
Cell* criar_celula(float key);

// Função para criar uma lista encadeada
ListaE* criar_listaE();

// Retorna 1 se a lista está vazia ou 0, caso contrário
int listaE_vazia(ListaE *l);

// Um item é inserido no início da lista
void inserir(float key, ListaE *l);

// Imprimir o conteúdo da lista
void imprimir(ListaE *l);

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_LE(ListaE *l);


// Cria uma nova célula
Cell* criar_celula(float key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Função para criar uma lista encadeada
ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}


// Retorna 1 se a lista está vazia ou 0, caso contrário
int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

// Um item é inserido no início da lista
void inserir(float key, ListaE *l){
    Cell *aux; // Nova célula

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_listaE();

    // Criar nova célula
    aux = criar_celula(key);

    // Apontar a nova célula para a cabeça da
    // lista
    aux->next = l->head;

    // Atualizar a cabeça da lista
    l->head = aux;
}

// Imprimir o conteúdo da lista
void imprimir(ListaE *l){
    Cell *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista

    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%.1f ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_LE(ListaE *l){
    Cell *aux = NULL; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista

    // Diferentemente de uma lista estática, que pode ser ter todos
    // seus elementos desalocados de uma vez, em uma lista encadeada,
    // primeiramente deve ser desolocada célula por célula
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

//Implementação ingênua do bubblesort
void bubblesort(ListaE *l){
    Cell* auxj = l->head;
    Cell* auxi = auxj;
	float x;
    while (auxi->next != NULL)
    {
        while (auxj->next != NULL)
        {
            if (auxj->item > auxj->next->item)
            {
                x = auxj->item;
                auxj->item = auxj->next->item;
                auxj->next->item = x;
            }
            auxj= auxj->next;
        }
        auxj = l->head;
        auxi = auxi->next;
    }
    
}

int main(void)
{
    ListaE *l = criar_listaE();
    float n;
    do
    {
        scanf("%f",&n);
        if(n!=-1)
            inserir(n,l);
    } while (n!=-1);

    bubblesort(l);
    imprimir(l);
    liberar_LE(l);
    



    return 0;
}

