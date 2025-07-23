#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *dado;
    struct celula *prox;
} Celula;

Celula *criar_pilha() {
    Celula *cabeca = malloc(sizeof(Celula));
    if (cabeca == NULL) return NULL;
    cabeca->prox = NULL;
    return cabeca;
}

int empilhar(Celula *pilha, const char *texto) {
    Celula *novo = malloc(sizeof(Celula));
    if (novo == NULL) return 1;

    novo->dado = strdup(texto); // Aloca e copia a string
    if (novo->dado == NULL) {
        free(novo);
        return 1;
    }

    novo->prox = pilha->prox;
    pilha->prox = novo;
    return 0;
}

char *desempilhar(Celula *pilha) {
    if (pilha->prox == NULL) return NULL;
    
    Celula *removida = pilha->prox;
    char *texto = removida->dado;
    pilha->prox = removida->prox;
    
    free(removida); // Libera a célula, mas mantém a string
    return texto;
}

void liberar_pilha(Celula *pilha) {
    char *texto;
    while ((texto = desempilhar(pilha)) != NULL) {
        free(texto); // Libera a string também
    }
    free(pilha);
}

int main() {
    Celula *historico = criar_pilha();
    if (historico == NULL) {
        fprintf(stderr, "Erro ao criar pilha\n");
        return 1;
    }

    char comando[10];
    char texto[501]; // Aumentado para 500 caracteres + '\0'

    while (scanf("%9s", comando) != EOF) {
        if (strcmp(comando, "desfazer") == 0) {
            char *ultimo = desempilhar(historico);
            printf("%s\n", ultimo ? ultimo : "NULL");
            free(ultimo); // Libera a string após uso
        }
        else if (strcmp(comando, "inserir") == 0) {
            scanf(" %500[^\n]", texto);
            if (empilhar(historico, texto) != 0) {
                fprintf(stderr, "Erro ao empilhar\n");
            }
        }
    }

    liberar_pilha(historico);
    return 0;
}