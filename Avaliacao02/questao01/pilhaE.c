#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaE.h"


struct Cell{
    int item; 
    Cell *next;
};


struct PilhaE{
    Cell *topo;
};



Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}



void empilhar(int key, PilhaE *p){
    Cell *aux; 

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}


int desempilhar(PilhaE *p){
    Cell *aux; 
    int item = INT_MIN; 

    if (!pilhaE_vazia(p)){
        aux = p->topo;
        
        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}

void imprimir_pilha(PilhaE *p){
    Cell *aux; 

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }
        
        printf("\n");
    }
}

int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}
