typedef struct Cell Cell;
typedef struct  PilhaE PilhaE;

Cell* criar_celula(int key);

PilhaE* criar_pilhaE();

int pilhaE_vazia(PilhaE *p);

void empilhar(int key, PilhaE *p);

int desempilhar(PilhaE *p);

void imprimir_pilha(PilhaE *p);

int liberar_pilha(PilhaE *p);
