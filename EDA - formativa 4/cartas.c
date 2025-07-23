#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *cria_fila_circular() {
    celula *f = malloc(sizeof(celula));
    f->prox = f;
    return f;
}

celula *enfileira(celula *f, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->prox = f->prox;
    f->prox = novo;
    f->dado = x;
    return novo;  // Retorna o novo fim da fila
}

int desenfileira(celula *f, int *y) {
    if (f->prox == f) return 1;
    
    celula *removida = f->prox;
    *y = removida->dado;
    f->prox = removida->prox;
    free(removida);
    return 0;
}

void destruir_fila(celula *f) {
    while (f->prox != f) {
        int temp;
        desenfileira(f, &temp);
    }
    free(f);
}

int main() {
    int n;
    scanf("%d", &n);
    
    celula *f = cria_fila_circular();
    for (int i = 1; i <= n; i++) {
        f = enfileira(f, i);
    }

    printf("Cartas descartadas: ");
    int primeiro = 1;
    int count = 0;
    int ultima_carta = -1;
    
    while (1) {
        int carta;
        if (desenfileira(f, &carta)) break;
        
        if (count < n - 1) {
            if (!primeiro) printf(", ");
            printf("%d", carta);
            primeiro = 0;
            count++;
        } else {
            ultima_carta = carta;
            break;
        }
        
        if (desenfileira(f, &carta)) {
            ultima_carta = carta;
            break;
        }
        
        f = enfileira(f, carta);
    }
    
    printf("\nCarta restante: %d\n", ultima_carta);
    destruir_fila(f);
    return 0;
}