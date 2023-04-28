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
#include <limits.h>

#define TAM_MAX 100


struct Fila
{
	int item[TAM_MAX];
	int ini; // posição do primeiro item
	int fim; // posição do último item
	int tam; // tamanho da fila
};

typedef struct Fila Fila;

// Criar uma fila vazia
Fila* criar_fila();

// Verificar se a fila está cheia
int fila_cheia(Fila *f);

// Verificar se a fila está vazia
int fila_vazia(Fila *f);

// Colocar um item na fila
int enfileirar(Fila *f, int chave);

// remover um item da fila
int desenfileirar(Fila *f);

// Imprimir conteúdo da fila
void imprimir_fila(Fila *f);

// liberar fila
void liberar_fila(Fila *f);

// Criar uma fila vazia
Fila* criar_fila()
{
    Fila *f = (Fila*) malloc(sizeof(Fila));

    f->ini = -1;
    f->fim = -1;
    f->tam = 0;

    return f;
}

// Verificar se a fila está cheia
int fila_cheia(Fila *f)
{
    if (f == NULL)
        return -1; // A fila é nula
    else if (f->tam < TAM_MAX)
        return 0; // A fila não está cheia, pois o seu tamanho atingiu a capacidade máxima
    else
        return 1; // fila cheia
}

int fila_vazia(Fila *f){
    if (f == NULL)
        return -1; // A fila é nula
    else if (f->tam > 0)
        return 0; // A fila não está vazia, pois o seu tamanho é maior que zero
    else
        return 1; // fila vazia*/
}

// Colocar um item na fila
int enfileirar(Fila *f, int chave){
    // Se a fila for vazia, um espaço é alocado para ela
    if (f == NULL)
        f = criar_fila();

    // Se a fila não estiver cheia, enfileirar um item
    // ! => operação lógica de negação
    // Exemplos:
    // !0 = 1
    // !(número diferente de 0) = 0
    // Caso a fila seja nula, antes de entrar no comando if, ela é criada
    // ou seja, não precisa fazer "if (pilha_cheia(p) == 0)"
    if (!fila_cheia(f)){
        // Caso a fila estiver vazia
        if (f->ini < 0)
            f->ini = f->fim = 0;

        // Ao enfileirar um item, a posição do último elemento da fila
        // deve se atualizada. Antes da atualização, se a posição fim
        // for menor que a capacidade máxima da lista menos 1, basta
        // apenas incrementar o campo fim. Caso contrário, f->fim = 0;
        else if (f->fim < TAM_MAX - 1)
            f->fim++;
        else
            f->fim = 0;

        // Após a atualização da posição final da fila, basta atribuir o
        // novo item na última posição da fila
        f->item[f->fim] = chave;

        // Atualizar o tamanho da fila, que aumentou
        f->tam++;

        return 1; // Operação bem sucedida
    }

    return 0; // A fila estava cheia
}
// remover um item da fila
int desenfileirar(Fila *f){
    int item = INT_MIN;

    // Verificar se a fila é vazia (1) ou nula (-1)
    // A única condição para "entrar" no comando if é a função abaixo
    // retornar 0, cuja negação é 1
    // Para qualquer retorno diferente de 0, a negação será 0
    if (!fila_vazia(f)){
        item = f->item[f->ini];
        f->tam--; // a fila reduz o seu tamanho
	
	// Se a fila ficar vazia após a operação de desenfileirar, ini e 
	// fim passar a ser -1. Caso a fila não ficar vazia, o campo ini 
	// deve ser ser atualizado. Se a posição ini for menor que a 
	// capacidade máxima da lista menos 1, basta apenas incrementar o 
	// campo ini. Caso contrário, f->ini = 0;
	if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }else if (f->ini < TAM_MAX - 1)
            f->ini++;
        else
            f->ini = 0;
    }

    return item;
}

// Imprimir conteúdo da fila
void imprimir_fila(Fila *f){
    // Uma cópia da fila deve ser feita, pois podemos ter acesso
    // aos elementos apenas pela operação desempilhar, ou seja,
    // se usarmos a fila original (f), perderíamos os seus dados
    Fila aux = *f;
    int item;

    // Como a variável aux não é ponteiro, para utilizamos o seu
    // endereço como parâmetro para chamarmos a função fila_vazia
    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item);
    }
    
    printf("\n");
}

// liberar fila
void liberar_fila(Fila *f){
    if (f != NULL)
        free(f);
}

void inserirOrdenado(Fila *f, int chave) {
    Fila *aux = criar_fila();
    int elem;
    
    while (fila_vazia(f)!=1 && f->item[f->ini] > chave){
        elem=desenfileirar(f);
        enfileirar(aux, elem);
        
        }

    enfileirar(aux,chave);

    while (fila_vazia(f)!=1){
        enfileirar(aux, desenfileirar(f));

        }
    
    while (fila_vazia(aux)!=1){
        enfileirar(f, desenfileirar(aux));

        }
    free(aux);
        
}




int main(void)
{
    int i,n;
    Fila *f = criar_fila();


    while (n!=-1)
    {
        
        scanf("%d",&n);  
        if (n==-1)
        {
            break;
        }
        
        inserirOrdenado(f,n);
    }

    imprimir_fila(f);


    
    return 0;
    
}