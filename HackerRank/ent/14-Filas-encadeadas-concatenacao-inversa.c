/*Implemente uma função que receba 3 filas encadeadas (f1, f2, f3). A função deve concatenar 
f1 e f2, de forma que ambas sejam invertidas, em f3. Durante a concatenação, as filas f1 e f2 
devem ser esvaziadas. Dica: utilizar pilhas como auxiliar.

Exemplo:
Antes
f1 = {1, 2, 3}
f2 = {4, 5, 6, 7}
f3 = {}

Depois
f1 = {}
f2 = {}
f3 = {3, 2, 1, 7, 6, 5, 4}

Para a implementação do exercício, utilize um TAD de filas encadeadas, podendo ser um dos códigos 
que foi apresentado em aula (disponível no repositório da disciplina no GitHub).

Input Format
Na primeira linha, enquanto "-1" não for lido, ler números inteiros e inserir na primeira fila.
Na segunda linha, enquanto "-1" não for lido, ler números inteiros e inserir na segunda fila.

Constraints

As filas devem ser manipuladas apenas por funções. As únicas operações permitidas são: enfileirar 
e desenfileirar.

Output Format
Imprimir a fila concatenada

Sample Input 0
1 2 3 -1
4 5 6 7 -1

Sample Output 0

3 2 1 7 6 5 4*/

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

typedef struct FilaE FilaE; // Renomeação da estruct FilaE

// Cria uma nova célula
Cell* criar_celula(int key);

// Função para criar uma fila encadeada
FilaE* criar_filaE();

// Retorna 1 se a fila está vazia ou 0, caso contrário
int filaE_vazia(FilaE* f);

// Enfileirar um item
void enfileirar(int key, FilaE* f);

// Desenfileirar um item da fila
int desenfileirar(FilaE* f);

// verifica o item que está no início fila
int verificar_inicio(FilaE *f);

// verifica o item que está no fim fila
int verificar_fim(FilaE *f);

// Imprimir o conteúdo da fila
void imprimir_fila(FilaE* f);

// Desalocar a fila
int liberar_filaE(FilaE* f);

// Estrutura para representar filas encadeadas
struct FilaE{
    Cell *inicio;
    Cell *fim;
};


// Cria uma nova célula
Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


// Função para criar uma fila encadeada
FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


// Retorna 1 se a fila está vazia ou 0, caso contrário
int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


// Enfileirar um item
void enfileirar(int key, FilaE* f){
    Cell *aux; // Nova célula

    // Caso a pilha encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (f == NULL)
        f = criar_filaE();

    // Criar nova célula
    aux = criar_celula(key);

    // Caso a fila ainda esteja vazia, o primeiro e
    // o último elemento são iguais
    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        // Caso a fila não esteja vazia, basta atualizar
        // o final da estrutura
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


// Desenfileirar um item da fila
int desenfileirar(FilaE* f){
    Cell *aux; // Primeiro elemento da fila
    int item = INT_MIN; // Valor que está no início da fila

    if (!filaE_vazia(f)){
    	// obter o primeiro elemento da fila
        aux = f->inicio;

        f->inicio = aux->next;
        
        if (f->inicio == NULL)
        	f->fim = NULL;

        // Acessar o conteúdo da célula
        item = aux->item;

        // Liberar a célula desenfileirada
        free(aux);
    }

    return item;
}


// verifica o item que está no início fila
int verificar_inicio(FilaE *f){
    if (!filaE_vazia(f))
        return f->inicio->item;
    else
        return INT_MIN;
}


// verifica o item que está no fim fila
int verificar_fim(FilaE *f){
    if (!filaE_vazia(f))
        return f->fim->item;
    else
        return INT_MIN;
}

// Imprimir o conteúdo da fila
void imprimir_fila(FilaE* f){
    Cell *aux; // Para percorrer a fila, deve ser utilizada
    	       // uma variável auxiliar para não perder o
    	       // topo da lista

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


// Desalocar a fila
int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (!filaE_vazia(f))
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

int concatena_FilaE(FilaE *f1,FilaE *f2,FilaE *f3)
{
    Cell *aux1,*aux2;

    aux1=f1->fim;
    aux2=f2->fim;


    while (aux2!=NULL)
    {
        enfileirar(desenfileirar(aux2),f3);
    }
    while (aux2!=NULL)
    {
        enfileirar(desenfileirar(aux1),f3);
    }

    return f3;
}

int main(void)
{
    FilaE *f1 = criar_filaE();
    FilaE *f2 = criar_filaE();
    FilaE *f3 = criar_filaE();


    int n;

    while (n!=-1)
    {
        scanf("%d",&n);
        if(n!=-1)
            enfileirar(n,f1);
    }
    imprimir_fila(f1);
    while (n!=-1)
    {
        scanf("%d",&n);
        if(n!=-1)
            enfileirar(n,f2);
    }
    imprimir_fila(f1);


    concatena_FilaE(f1,f2,f3);
    

    imprimir_fila(f3);

    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);



    return 0;
}