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

void em_ordem(no* raiz){
    if (raiz == NULL) return;
    celula *pilha = cria_pilha();
    no *atual = raiz;

    while (1){
        while( atual != NULL){
            empilha(pilha, atual);
            atual = atual -> esq;
        }
        if (desempilha(pilha, &atual)) break;
        printf ("%d ", atual ->dado);
        atual = atual -> dir;
    }

    while (pilha -> prox != NULL){
        no *temp;
        desempilha(pilha, &temp);
    }
    free(pilha);
}
