#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct celula {
    char *dado;
    struct celula *prox;
} fila;

fila *cria_fila(){
    fila *f = malloc(sizeof(fila));
    f -> prox = f;
    return f;
}

fila *enfileira(fila *f, char *x){
    fila *novo = malloc(sizeof(fila));
    novo -> prox = f-> prox;
    f -> prox = novo;
    f -> dado = strdup(x);
    return novo;
}

int desenfileira(fila *f, char **y){
    if ( f->prox == f) return 1;
    fila *lixo = f->prox;
    *y = f -> prox-> dado;
    f-> prox = lixo -> prox;
    free(lixo);
    return 0;
}

int esta_vazia(fila *f){
    return f->prox == f;
}

char *ver_proximo(fila *f){
    if(f -> prox == NULL){
        return NULL;
    }else{
        return f -> prox -> dado;
    }
}

int main(){
    char cidade[27];
    fila *f = cria_fila();
    while( scanf(" %s", cidade) != EOF){
        f = enfileira(f, cidade);
    }
    while(!esta_vazia(f)){
        char *atual;
        desenfileira(f, &atual);
        printf("%s\n", atual);
        if(esta_vazia(f)){
            free(atual);
            break;
        }

        char ultima = atual[strlen(atual)-1];
        char *proxima = ver_proximo(f);
        char primeiro = proxima[0];
        if (tolower(primeiro) == tolower(ultima)){
            char *final;
            desenfileira(f, &final);
            f = enfileira(f, final);
        }
        free(atual);
    }
    return 0;
}


