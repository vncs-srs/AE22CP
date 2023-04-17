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

    if (!lista_cheia(l))
    {
        // Procurar na parte "não vazia" da lista
        for (i = 0; i < l->tam; i++)
        {
            if (l->item[i].expo == expo)
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
    int i,r=0;

    for ( i = 0; i < l->tam; i++)
    {
        r +=l->item[i].cons * pow(x,l->item[i].expo);
    }
    
    return r;
}

void mostrar_polinomio(Lista *l)
{
    int i;
    char polinomio[100];


    for (i = 0; i < l->tam; i++)
    {
        if (l->item[i].cons > 0)
        {
            sprintf(polinomio + strlen(polinomio)," + %d^%d",l->item[i].cons,l->item[i].expo);
        }
        else
        {
            sprintf(polinomio + strlen(polinomio)," %d^%d",l->item[i].cons,l->item[i].expo);
        }
    }

    printf("%s\n",polinomio);
}

int inserir(Lista *l, int expo,int cons)
{
    // Se a lista for nula, podemos alocar um espaço para ela, já que
    // pretendemos fazer uma inserção nela
    if (l == NULL)
        l = criar_lista();

    if (!lista_cheia(l))
    {
        int posicao = buscar(l, expo);

        if (posicao == -1)
        {
            l->item[l->tam].expo = expo;
            l->item[l->tam].cons = cons;

            l->tam++;

            return 1;
        }
        else
        {
            l->item[posicao].cons = cons;

            return 1;
        }
    }


    
}

int main(void)
{
    Lista* L1 = criar_lista();
    inserir(L1,3, 1);
    inserir(L1,2, -2);
    inserir(L1,1, 5);
    inserir(L1,0, 1);
    inserir(L1,3, -5);


    mostrar_polinomio(L1);

    int resul = polinomio(L1,2);

    printf("\n Resultado: %d\n",resul);

    return 0;

}



