#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char marca[20];
    union{ // formato depende do tipo inventario
    long nro_id; // inventários do tipo 1
    char char_id[20]; // outros inventários
    };
    int tipo;
}inventario;

int main() 
{
    
    inventario inv;
    strcpy(inv.marca, "Doli");
    inv.nro_id = 5678;
    
    return 0;
}