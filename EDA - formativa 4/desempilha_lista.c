#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int *dado;
    struct celula *prox;
}celula;

int desempilha(celula *p, int *y){
    if (p -> prox == NULL) return 0;
    celula *ret = p -> prox;
    *y = ret -> dado;
    p -> prox = ret -> prox;
    return 1;
}