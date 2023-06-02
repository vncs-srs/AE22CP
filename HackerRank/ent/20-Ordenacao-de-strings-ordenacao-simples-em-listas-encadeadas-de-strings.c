/*Implemente um algoritmo de ordenação simples para ordenar uma lista encadeada de strings.

Input Format

Na primeira linha deve ser lida a quantidade de elementos que serão inseridos na lista encadedade. 
A partir da segunda linha, ler as strings e colicá-las na lista encadeada.

Constrachars
.
Output Format

Imprimir o conteúdo da lista encadeada após a ordenação.

Sample Input 0
8
joao_paulo
tereza
joao_luiz
vegeta
ana
vampeta
yusuke
aioria

Sample Output 0
aioria
ana
joao_luiz
joao_paulo
tereza
vampeta
vegeta
yusuke*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell Cell; // Renomeação da struct Cell

// Estrutura para representar células
struct Cell{
    char item[30]; // Pode ser uma struct, union, ou qualquer tipo de dados.
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
Cell* criar_celula(char key[]);

// Função para criar uma lista encadeada
ListaE* criar_listaE();

// Retorna 1 se a lista está vazia ou 0, caso contrário
char listaE_vazia(ListaE *l);

// Um item é inserido no início da lista
void inserir_primeiro(char key[], ListaE *l);

// Um item é inserido no final da lista
void inserir_ultimo(char key[], ListaE *l);

// Imprimir o conteúdo da lista
void imprimir(ListaE *l);

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
char liberar_LE(ListaE *l);

// Cria uma nova célula
Cell* criar_celula(char key[]){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    strcpy(c->item,key);

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
char listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

// Um item é inserido no início da lista
void inserir_primeiro(char key[], ListaE *l){
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


// Um item é inserido no final da lista
void inserir_ultimo(char key[], ListaE *l){
    Cell *aux, *nova; // célula auxiliar e nova,
                      // respectivamente

    // Caso a lista encadeada seja nula,
    // alocar um espaço para essa estrutura
    if (l == NULL)
        l = criar_listaE();

    // Se a lista estiver vazia, não faz sentido
    // percorrê-la
    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

	// Percorrer a lista até encontrar a última
	// célula
        while(aux->next != NULL)
            aux = aux->next;

        // Criar nova célula
        nova = criar_celula(key);

	// O último elemento da lista aponta para a
	// nova célula
        aux->next = nova;
    }
}




// Imprimir o conteúdo da lista
void imprimir(ListaE *l){
    Cell *aux; // Para percorrer a lista, deve ser utilizada
    	       // uma variável auxiliar para não perder a
    	       // cabeça da lista

    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%s \n", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}

// Liberar lista
// Retorna 1 se a operação for bem-sucedida ou 0, caso contrário
char liberar_LE(ListaE *l){
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

int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 < c2) return -1;
    else return 1;
}


int comparar(char s1[], char s2[]){
	int i;

	for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

	return comparar_char(s1[i], s2[i]);
}


void troca(char **vstr, int p1, int p2){
    char *str;

    str = vstr[p1];
    vstr[p1] = vstr[p2];
    vstr[p2] = str;
}

void bubblesort(ListaE *l){
    Cell* auxj = l->head;
    Cell* auxi = auxj;
	char x[30];
    while (auxi->next != NULL)
    {
        while (auxj->next != NULL)
        {
            if (comparar(auxj->item ,auxj->next->item)>0)
            {
                strcpy(x , auxj->item);
                strcpy(auxj->item , auxj->next->item);
                strcpy(auxj->next->item , x);
            }
            auxj= auxj->next;
        }
        auxj = l->head;
        auxi = auxi->next;
    }
    
}



int main(void)
{
    int n;
    char s[30];

    ListaE *l = criar_listaE();

    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        
        scanf("%s",s);
        inserir_primeiro(s,l);
    }
    bubblesort(l);
    imprimir(l);

    liberar_LE(l);
    





    return 0;
}
