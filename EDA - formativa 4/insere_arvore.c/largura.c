#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq,*dir;
}no;

typedef struct celula{
    no *dado;
    struct celula *prox;
}fila;


fila *cria_fila(){
    fila *f = malloc(sizeof(fila));
    f->prox = f;
    return f;
}

fila*enfileira(fila*f, no *x)
{
    fila *novo = malloc(sizeof(fila));
    novo->prox = f->prox;
    f->prox = novo;
    f->dado = x;
    return novo;
}

int desenfileira(fila*f, no **y)
{
    if(f->prox == f) return 1;// fila vazia 
    fila *lixo = f->prox;
    *y = lixo ->dado;
    f->prox = lixo->prox;
    free(lixo);
    return 0; // deu certo
}

void largura(no *raiz){
    fila *f = cria_fila();
    f = enfileira(f, raiz);
    while (!desenfileira(f, &raiz)){
        if (raiz != NULL){
            printf("%d", raiz -> dado);
            f = enfileira(f, raiz-> esq);
            f = enfileira(f, raiz -> dir);
        }
    }
    free(f);
}
