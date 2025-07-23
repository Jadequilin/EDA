#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

int desenfileira(celula *f, int *y) {
    if (f == NULL || f->prox == NULL) {
        return 0; // Fila vazia ou inválida
    }
    
    celula *remover = f->prox;
    *y = remover->dado;
    f->prox = remover->prox;
    free(remover);
    
    return 1;
}