#include "listaE.h"
#include <stdio.h>

int main(){
    
    ListaE* myList = criar_listaE();
    
    inserir_primeiro(10,myList);
    inserir_primeiro(7,myList);
    inserir_primeiro(13,myList);
    inserir_ultimo(-5,myList);
    
    int tamanho = tamanho_LE(myList);
    
    printf("\nTamanho da lista: %d\n",tamanho);
    
    imprimir(myList);
    liberar_LE(myList);
    

    return 0;
}
