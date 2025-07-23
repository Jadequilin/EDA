#include <stdlib.h>
#include <stdio.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    p -> prox = NULL;
    return p;
}

int empilha(celula *p, int x){
    celula *novo = malloc(sizeof(celula));
    if(novo == NULL) return 1;
    novo -> dado = x;
    novo -> prox = p -> prox;
    p -> prox = novo;
    return 0;
}

celula *desempilha_dado(celula *p, int *y){
    celula *rem = p -> prox;
    if (p-> prox == NULL) return 1;
    *y = rem -> dado;
    p -> prox = rem -> prox;
    return 0;
}

celula *desempilha(celula *p){
    if (p -> prox == NULL) return 1;
    celula *ret = p->prox;
    p -> prox = ret->prox;
}

void destroi_pilha(celula *p){
    celula *ret = desempila(p);
    celula *rem = desempilha_dado(p, 15);
    while (rem != NULL || ret != NULL){
        free(rem);
        free(ret);
    }
    free(p);
}