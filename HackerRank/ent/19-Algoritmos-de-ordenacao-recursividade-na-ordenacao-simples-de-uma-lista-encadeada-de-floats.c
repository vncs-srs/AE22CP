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


typedef struct CellDE CellDE; // Renomeação da struct CellDE

// Estrutura para representar células
struct CellDE{
    float item; // Pode ser uma struct, union, ou qualquer tipo de dados.
              // Para possibilitar o reuso dessa célula para qualquer
              // tipo de informação, recomendo o uso de ponteiro
              // genérico. Exemplo: void* item;
    CellDE *previous, *next;
};


// Estrutura para representar listas duplamente encadeadas
struct ListaDE{
    CellDE *head; // Ponteiro para o primeiro elemento da lista
};

typedef struct ListaDE ListaDE; // Renomeação da struct ListaDE

// Cria uma nova célula
CellDE* criar_celulaDE(float key);

// Função para criar uma lista encadeada
ListaDE* criar_ListaDE();

// Retorna 1 se a lista está vazia ou 0, caso contrário
int ListaDE_vazia(ListaDE *l);

// Um item é inserido no início da lista
void inserir(float key, ListaDE *l);

// Imprimir o conteúdo da lista
void imprimir(ListaDE *l);

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
int liberar_LE(ListaDE *l);

// Cria uma nova célula
CellDE* criar_celulaDE(float key){
    CellDE *c = (CellDE*) malloc(sizeof(CellDE));
    c->item = key;

    c->previous = c->next = NULL;

    return c;
}


// Função para criar uma lista encadeada
ListaDE* criar_ListaDE(){
    ListaDE* l = (ListaDE*) malloc(sizeof(ListaDE));

    l->head = NULL;

    return l;
}


// Retorna 1 se a lista está vazia ou 0, caso contrário
int ListaDE_vazia(ListaDE *l){
    return (l == NULL) || (l->head == NULL);
}

// Um item é inserido no início da lista
void inserir(float key, ListaDE *l){
    CellDE *aux; // Nova célula

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_ListaDE();

    // Criar nova célula
    aux = criar_celulaDE(key);

    // Apontar a nova célula para a cabeça da
    // lista
    aux->next = l->head;
    l->head->previous = aux;

    // Atualizar a cabeça da lista
    l->head = aux;
}

// Imprimir o conteúdo da lista
void imprimir(ListaDE *l){
    CellDE *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista


    if (!ListaDE_vazia(l)){
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
int liberar_LE(ListaDE *l){
    CellDE *aux = NULL; // Para percorrer a lista, deve ser utilizada
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
void bubblesort(ListaDE *l, float n){
	int i, j, x;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1]){
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
			}
}

int main(void)
{
    ListaDE *l = criar_listaDE();
    float n;
    do
    {
        scanf("%f",&n);
        inserir(n,l);
    } while (n!=-1);
    
    bubblesort(l,n);
    imprimir(l);
    liberar_LE(l);
    



    return 0;
}

