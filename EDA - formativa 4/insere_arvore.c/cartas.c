#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *cria_fila(){
    celula *f = malloc(sizeof(celula));
    f->prox = f;
    return f;
}

celula *enfileira(celula *f , int x){
    celula *novo = malloc(sizeof(celula));
    novo->prox = f->prox;
    f->prox = novo;
    f->dado = x;
    return novo;
}

int desenfileira(celula *f, int *y){
    *y = f->prox->dado;
    celula *ret  = f->prox;
    f->prox = ret->prox;
    free(ret);
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    celula *f = cria_fila();
    char descartados[500];
    for (int i = 1; i <= n; i++){
        f = enfileira(f, i);
    }
    int j = 0;
    while( f-> prox-> prox != f){
        int z;
        desenfileira(f, &z);
        descartados[j++] = z;
        desenfileira(f, &z);
        f = enfileira(f,z);
    }

    printf("Cartas descartadas: ");
    for (int i= 0; i < j; i++){
        printf(" %d", descartados[i]);
        if ( i < j-1) printf(",");
    }
    printf("\nCarta restante: %d\n", f->prox->dado);
    return 0;

}
