
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
    empilhar(desempilhar(paux),f);
}

int desenfileirar(FilaE* f){
    PilhaE* paux = criar_pilhaE();
    PilhaE* p2aux = criar_pilhaE();
    empilhar(desempilhar(f),paux);
    empilhar(desempilhar(paux),p2aux);
    empilhar(desempilhar(p2aux),f);
    return desempilhar(f);
}

void imprimir_fila(FilaE* f){
    return imprimir_pilha(f);
}

int liberar_filaE(FilaE* f){
    return liberar_pilha(f);
}