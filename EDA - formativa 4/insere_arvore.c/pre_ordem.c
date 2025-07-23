#include <stdlib.h>
#include <stdio.h>

// Árvore binária
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Celula da pilha (agora armazena ponteiros para nós)
typedef struct celula{
    no *conteudo;
    struct celula *prox;
}celula;

celula *cria_pilha(){
    celula *p = malloc(sizeof(celula));
    p -> prox = NULL;
    return p;
}

int empilha(celula *p, no *n){
    celula *novo = malloc(sizeof(celula));
    novo -> conteudo = n;
    novo -> prox = p-> prox;
    p -> prox  = novo;
    return 0;
}

int desempilha( celula *p, no **n){
    if (p -> prox  == NULL) return 1;
    celula *rem = p -> prox;
    *n = rem -> conteudo;
    p -> prox = rem -> prox;
    free(rem);
    return 0;
}

void pre_ordem(no *raiz){
    if (raiz == NULL) return;
    celula *p = cria_pilha();
    empilha(p, raiz);

    no *atual;
    while (!desempilha(p, &atual)){
        printf("%d ", atual -> dado);
        if(atual -> dir) empilha(p, atual -> dir);
        if( atual -> esq) empilha(p, atual -> esq);
    }

    while( p-> prox != NULL){
        no *temp;
        desempilha(p, &temp);
    }
    free(p);
}


