#include <stdlib.h>
#include <stdio.h>

// Árvore binária
typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

// Celula da pilha (agora armazena ponteiros para nós)
typedef struct celula {
    no *conteudo;          // Armazena ponteiro para nó da árvore
    struct celula *prox;
} celula;

// Cria pilha (igual à sua versão, mas com tipo atualizado)
celula *cria_pilha() {
    celula *p = malloc(sizeof(celula));
    p->prox = NULL;
    return p;
}

// Empilha (agora recebe ponteiro para nó)
int empilha(celula *p, no *n) {
    celula *novo = malloc(sizeof(celula));
    if (!novo) return 1;
    novo->conteudo = n;
    novo->prox = p->prox;
    p->prox = novo;
    return 0;
}

// Desempilha (agora retorna ponteiro para nó)
int desempilha(celula *p, no **n) {
    if (!p->prox) return 1;
    celula *rem = p->prox;
    *n = rem->conteudo;
    p->prox = rem->prox;
    free(rem);
    return 0;
}

// Pré-ordem (versão simplificada e segura)
void pre_ordem(no *raiz) {
    if (!raiz) return;
    
    celula *pilha = cria_pilha();
    empilha(pilha, raiz);
    
    no *atual;
    while (!desempilha(pilha, &atual)) {
        printf("%d ", atual->dado);
        if (atual->dir) empilha(pilha, atual->dir);
        if (atual->esq) empilha(pilha, atual->esq);
    }
    free(pilha);
}

// Em-ordem (versão simplificada e segura)
void em_ordem(no *raiz) {
    if(raiz == NULL) return;
    celula *pilha = cria_pilha();
    no *atual = raiz;
    
    while (1) {
        while (atual != NULL) {
            empilha(pilha, atual);
            atual = atual->esq;
        }
        if (desempilha(pilha, &atual)) break;
        printf("%d ", atual->dado);
        atual = atual->dir;
    }
    free(pilha);
}

