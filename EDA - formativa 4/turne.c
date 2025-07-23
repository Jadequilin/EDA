#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 27

typedef struct celula {
    char cidade[MAX_NOME];
    struct celula *prox;
} celula;

// Função para enfileirar
celula* enfileira(celula *f, const char *cidade) {
    celula *novo = malloc(sizeof(celula));
    if (novo == NULL) return NULL;
    strcpy(novo->cidade, cidade);
    novo->prox = NULL;
    
    // Enfileira o novo nó
    f->prox = novo;  // O nó cabeça agora aponta para o novo nó
    return novo;     // Retorna o novo nó
}

// Função para desenfileirar
int desenfileira(celula *f, char *cidade) {
    if (f == NULL || f->prox == NULL) {
        return 0;  // Fila vazia ou inválida
    }

    celula *remover = f->prox;
    strcpy(cidade, remover->cidade);  // Armazena o valor do nó removido
    f->prox = remover->prox;          // O nó cabeça agora aponta para o próximo nó
    free(remover);                    // Libera a memória do nó removido

    return 1;  // Retorna sucesso
}

int main() {
    celula *fila = malloc(sizeof(celula));  // Nó cabeça da fila
    fila->prox = NULL;  // Inicializa a fila vazia

    char cidade[MAX_NOME];
    celula *final = fila;

    // Lendo as cidades
    while (scanf("%26s", cidade) != EOF) {
        final = enfileira(final, cidade);  // Adiciona cidade à fila
    }

    // Processando as cidades
    while (fila->prox != NULL) {
        char cidadeAtual[MAX_NOME];
        desenfileira(fila, cidadeAtual);  // Retira a primeira cidade da fila
        printf("%s\n", cidadeAtual);

        if (fila->prox == NULL) {
            break;
        }

        char ultimaLetra = tolower(cidadeAtual[strlen(cidadeAtual) - 1]);
        char *proximaCidade = fila->prox->cidade;
        char primeiraLetraProxima = tolower(proximaCidade[0]);

        if (primeiraLetraProxima == ultimaLetra) {
            char cidadeMovida[MAX_NOME];
            desenfileira(fila, cidadeMovida);  // Retira a cidade do início
            final = enfileira(final, cidadeMovida);  // Adiciona a cidade ao final
        }
    }

    // Liberação de memória (opcional)
    while (fila != NULL) {
        celula *temp = fila;
        fila = fila->prox;
        free(temp);
    }

    return 0;
}
