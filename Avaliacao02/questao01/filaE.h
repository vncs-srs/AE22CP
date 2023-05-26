#include "pilhaE.h"
#define FilaE PilhaE

typedef struct Cell Cell;
typedef struct FilaE FilaE;

Cell* criar_celula(int key);

FilaE* criar_filaE();

int filaE_vazia(FilaE* f);

void enfileirar(int key, FilaE* f);

int desenfileirar(FilaE* f);

void imprimir_filaE(FilaE* f);

int liberar_filaE(FilaE* f);