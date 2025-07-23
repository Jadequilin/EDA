#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Assume que 'f' é um nó cabeça (dado não utilizado, prox aponta para o início)
celula *enfileira(celula *f, int x) {
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return NULL;
    novo -> prox = f -> prox;
    f -> prox = novo;
    f -> dado = x;
    return novo;
}