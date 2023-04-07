#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_EXP 10

typedef struct 
{
    int cons;
    int expo;
}Elemento;

//Estrutura para a lista estatica

typedef struct 
{
    Elemento item[MAX_EXP];
    int tam; //tamanho da lista
}Lista;

//Funcao para criar uma lista estatica

Lista* criar_lista()
{
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}

//Retona 1 se a lista esta cheia ou 0, caso contrario 

int lista_cheia(Lista *l)
{
    return (l != NULL) && (l->tam == MAX_EXP);
}

//Procura a posicao de um item com o expoente expo e retona a sua respectiva posicao 
//Caso o item nao seja encontrado, e retornado -1

int buscar(Lista *l,int expo)
{
    int i;

    if (!lista_vazia(l))
    {
        // Procurar na parte "não vazia" da lista
        for (i = 0; i < l->tam; i++)
        {
            if (l->item[i] == expo)
            {
                return i;
            }
        }
    }
    // Se chegou aqui é porque a lista está vazia ou o item não foi encontrado
    return -1;
}

int polinomio(Lista *l,int x)
{
    int i,P,aux,expo;
    for ( i = 0; i < l->tam; i++)
    {
        
        aux=pow(expo,l->item[i]);

        P=P+aux;
    }
    
    return P;
}

void mastrar_polinomio(Lista *l,int x)
{
    int i;


    for (i = 0; i < l->tam; i++)
    {
        printf("(%d)^%d + ",x ,l->item[i]);
    }

    printf("\n");
}

/*void inserir(Lista *l,int expo , int const)
{
    polinomio(expo);
}*/

/*int main(void)
{
    Lista* L1 = criar_lista();


    return 0;

}*/



