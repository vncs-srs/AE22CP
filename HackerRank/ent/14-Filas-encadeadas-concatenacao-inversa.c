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

#define TAM_MAX 100

typedef struct Cell Cell; // Renomeação da struct Cell

// Estrutura para representar células
struct Cell{
    int item; // Pode ser uma struct, union, ou quanquer tipo de dados. 
              // Para possibilitar o reuso dessa célula para qualquer 
              // tipo de informação, recomendo o uso de ponteiro 
              // genérico. Exemplo: void* item;
    Cell *next;
};



typedef struct FilaE FilaE; // Renomeação da estruct FilaE
typedef struct Pilha Pilha;

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

// Criar uma pilha vazia
Pilha* criar_pilha();

// Verificar se a pilha está cheia (stack overflow)
int pilha_cheia(Pilha *p);

// Verificar se a pilha está vazia (stack underflow)
int pilha_vazia(Pilha *p);

// Inserir um novo item na pilha, caso houver espaço
int empilhar(Pilha *p, int chave);

// Remover item do topo da pilha, caso essa estrutura não estiver vazia
int desempilhar(Pilha *p);

// Imprimir conteúdo da pilha
void imprimir_pilha(Pilha *p);

// Liberar a pilha
void liberar_pilha(Pilha *p);

// Obter a posição da pilha em que está o topo
int obter_posicao_topo(Pilha *p);

// Retorna o valor que está no topo. Caso a pilha estiver vazia, será retornado INT_MIN.
int acessar_valor_topo(Pilha *p);

// Estrutura para representar filas encadeadas
struct FilaE{
    Cell *inicio;
    Cell *fim;
};

struct Pilha{
    int item[TAM_MAX];
    int topo;
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


// Criar uma pilha vazia
Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

// Verificar se a pilha está cheia (stack overflow)
int pilha_cheia(Pilha *p){
    // Uma solução simples
    // Antes de verificar o topo da pilha, primeiro devemos verificar se
    // a pilha é nula
    //return (p != NULL) && p->topo == (TAM_MAX - 1);

    //outra alternativa para implementação dessa função para retornar
    //-1: se a pilha for nula
    // 0: se a pilha não estiver cheia
    // 1: se a pilha estiver cheia
    if (p == NULL)
        return -1;
    else if (p->topo >= (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

// Verificar se a pilha está vazia (stack underflow)
int pilha_vazia(Pilha *p){
    // Uma solução simples
    // Pilha nula ou com o topo igual a -1 é uma pilha vazia
    //return (p == NULL) || (p->topo == -1);

    //outra alternativa para implementação dessa função para retornar
    //-1: se a pilha for nula
    // 0: se a pilha não estiver vazia
    // 1: se a pilha estiver vazia
    if (p == NULL)
        return -1;
    else if (p->topo < 0)
        return 1;
    else
        return 0;
}

// Inserir um novo item na pilha, caso houver espaço
int empilhar(Pilha *p, int item){
    // Se a pilha for nula, reservar um espaço na memória para ela
    if (p == NULL)
        p = criar_pilha();

    // Se a pilha não estiver cheia, empilhar um item
    // ! => operação lógica de negação
    // Exemplos:
    // !0 = 1
    // !(número diferente de 0) = 0
    // Caso a pilha seja nula, antes de entrar no comando if, ela é criada
    // ou seja, não precisa fazer "if (pilha_cheia(p) == 0)"
    if (!pilha_cheia(p)){
        p->topo++; // a pilha aumenta

        p->item[p->topo] = item; // um novo item é empilhado

        return 1; // operação bem sucedida
    }

    return 0; // operação mal sucedida
}

// Remover item do topo da pilha, caso essa estrutura não estiver vazia
int desempilhar (Pilha *p){
    int item = INT_MIN;

    // Verificar se a pilha é vazia (1) ou nula (-1)
    // A única condição para "entrar" no comando if é a função abaixo
    // retornar 0, cuja negação é 1
    // Para qualquer retorno diferente de 0, a negação será 0
    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

// Imprimir conteúdo da pilha
void imprimir_pilha(Pilha *p){
    // Uma cópia da pilha deve ser feita, pois podemos ter acesso
    // aos elementos apenas pela operação desempilhar, ou seja,
    // se usarmos a pilha original (p), perderíamos os seus dados
    Pilha aux = *p;
    int item;

    // Como a variável aux não é ponteiro, para utilizamos o seu
    // endereço como parâmetro para chamarmos a função pilha_vazia
    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d\n", item);
    }
}

// Liberar a pilha
void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}


// Obter a posição da pilha em que está o topo
int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}


// Retorna o valor que está no topo. Caso a pilha estiver vazia, será retornado INT_MIN.
int acessar_valor_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->item[p->topo];
    else
        return INT_MIN;
}



void concatena_inversa_FilaE(FilaE *f1,FilaE *f2,FilaE *f3)
{
    Pilha *p1 = criar_pilha();
    Pilha *p2 = criar_pilha();

    while (filaE_vazia(f1)==0)
    {
        empilhar(p1,desenfileirar(f1));
    }
    while (pilha_vazia(p1)==0)
    {
        enfileirar(desempilhar(p1),f3);
    }
    while(filaE_vazia(f2)==0)
    {
        empilhar(p2,desenfileirar(f2));
    }
    while (pilha_vazia(p2)==0)
    {
        enfileirar(desempilhar(p2),f3);
    }
    
}

int main(void)
{
    FilaE *f1 = criar_filaE();
    FilaE *f2 = criar_filaE();
    FilaE *f3 = criar_filaE();

    int n;

    do
    {
        scanf("%d",&n);
        if(n!=-1)
            enfileirar(n,f1);
    }while (n!=-1);

    do
    {
        scanf("%d",&n);
        if(n!=-1)
            enfileirar(n,f2);
    }while (n!=-1);
    
    concatena_inversa_FilaE(f1,f2,f3);

    imprimir_fila(f3);

    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);

    return 0;
}