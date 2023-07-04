
#include "pilhaE.h"
#include "pilhaE.c"
#include "filaE.h"

FilaE* criar_filaE(){
    return criar_pilhaE();
}

int filaE_vazia(FilaE* f){
    return (pilhaE_vazia(f));
}

void enfileirar(int key, FilaE* f){
    PilhaE* paux = criar_pilhaE();
    empilhar(key,paux);
}

int desenfileirar(FilaE* f){
    PilhaE* paux = criar_pilhaE();

    while (!pilhaE_vazia(f))
        empilhar(desempilhar(f),paux);

    int valor_topo = desempilhar(paux);

    while (!pilhaE_vazia(paux))
        empilhar(desempilhar(paux),f);

    liberar_pilha(paux);
    return valor_topo;
}

void imprimir_fila(FilaE* f){
    FilaE* aux;
    aux = criar_filaE();
    while(!filaE_vazia(f))
        empilhar(desempilhar(f),aux);
    
    imprimir_pilha(aux);

    while(!filaE_vazia(aux))
        empilhar(desempilhar(aux),f);
    
    liberar_pilha(aux);
}

int liberar_filaE(FilaE* f){
    return liberar_pilha(f);
}