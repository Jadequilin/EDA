#include <stdlib.h>
#include <stdio.h>

typedef struct celula{
    int dado; 
    struct celula *prox;
}celula;

celula *cria_fila(){
    celula *f = malloc(sizeof(celula));
    f -> prox = f;
    return f;
}

celula *enfileira(celula *f, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> prox = f-> prox;
    f-> prox = novo;
    f -> dado = x;
    return novo;
}

int desenfileira(celula *f, int *y){
    if ( f -> prox == f) return 1;
    *y = f-> prox -> dado;
    celula *lixo = f-> prox;
    f -> prox = lixo -> prox;
    free(lixo);
    return 0;
}

void destroi_fila(celula *f) {
    while (f->prox != f) {
        int temp;
        desenfileira(f, &temp);
    }
    free(f);
}