#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union 
{
    long nro_id;
    char char_id[20];
}identificador;

typedef struct 
{
    char marca[20];
    identificador id;
    int tipo;
}inventario;

int main() 
{
    inventario inv;
    strcpy(inv.marca, "Doli");
    inv.id.nro_id = 5678;

    strcpy(inv.id.char_id,"Seila");//inv.id.nro_id = 5678;


    printf("Item de inventario: %s - %ld - %s - %d\n",inv.marca, inv.id.nro_id, inv.id.char_id, inv.tipo);

    return 0;
}