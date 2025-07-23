#include <stdio.h>
#include <stdlib.h>

// implementacao de pre ordem e em ordem
/*
typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

typedef struct celula{
    struct no *conteudo;
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
    novo -> prox = p -> prox;
    p -> prox = novo;
    return 0;
}

int desempilha(celula *p, no **n){
    if ( p -> prox == NULL) return 1;
    celula *rem = p -> prox;
    *n = rem -> conteudo;
    p -> prox = rem -> prox;
    free(rem);
    return 0;
}
/*
void pre_ordem(no *raiz){
    if (raiz == NULL) return;
    celula *pilha = cria_pilha();
    empilha(pilha, raiz);
    while(pilha -> prox != NULL) {
        no *atual = desempilha(pilha);
        printf(" %d", atual -> dado);
        if (atual -> dir != NULL) empilha(pilha, atual->dir);
        if (atual -> esq != NULL) empilha (pilha, atual -> esq);
    }
    while(desempilha(pilha) != NULL);
    free(pilha);
}
*/
// em ordem
/*
void em_ordem(no *raiz){
    if (raiz == NULL) return;
    celula *pilha = cria_pilha();
    no *atual = raiz;
    while(1){
        while(atual != NULL){
            empilha(pilha, atual);
            atual = atual -> esq;
        }
        no *visit;
        if (desempilha(pilha, &visit)) break;
        printf("%d ", visit ->dado);
        atual = visit -> dir;
    } 
    while(pilha -> prox != NULL){
        no *temp;
        desempilha(pilha, &temp);
    }
    free(pilha);
}*/

typedef struct celula
{
    int dado;
    struct celula *esq,*dir;
}celula;

typedef struct no
{
    celula *dado;
    struct no *prox;
}fila;


fila *cria_fila()
{
    fila *f = malloc(sizeof(fila));
    f->prox = f;
    return f;
}

fila*enfileira(fila*f,celula *x)
{
    fila *novo = malloc(sizeof(fila));
    novo->prox = f->prox;
    f->prox = novo;
    f->dado = x;
    return novo;
}

int desenfileira(fila*f, celula **y)
{
    if(f->prox == f) return 1;// fila vazia 
    *y = f->prox->dado;
    fila*lixo = f->prox;
    f->prox = lixo->prox;
    free(lixo);
    return 0; // deu certo
}

void largura(celula *raiz)
{
    fila *f = cria_fila();
    f = enfileira(f,raiz);
    while (!desenfileira(f,&raiz))
    {
        if (raiz != NULL)
        {
            printf("%d",raiz->dado);
            f = enfileira(f,raiz->esq);
            f = enfileira(f,raiz->dir);
        }
        
    }
    free(f);
}