#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void remove_depois( celula *p){
    if ( p == NULL || p -> prox == NULL){
        return;
    }
    celula *lixo = p -> prox;
    p -> prox = p -> prox -> prox;
    free(lixo);
}

void remove_elemento(celula *le, int x){
    if (le == NULL) return;
    celula *atual = le;
    while(atual -> prox != NULL && atual -> prox -> dado != x){
        atual = atual -> prox;
    }
    celula *lixo = atual -> prox;
    atual -> prox = atual -> prox -> prox;
    free(lixo);
}

void remove_todos_elementos(celula *le, int x){
    if (le == NULL) return;
    celula *atual = le;
    while(atual -> prox != NULL){
        if(atual -> prox -> dado == x){
            celula *lixo = atual -> prox;
            atual -> prox = atual -> prox -> prox;
            free(lixo);
        }else{
            atual = atual -> prox;
        }          
    }
}