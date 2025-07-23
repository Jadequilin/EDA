#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int *dados;  // Ponteiro para o vetor que armazena os elementos
    int N;       // Capacidade atual da fila
    int p;       // Posição de remoção (início da fila)
    int u;       // Posição de inserção (fim da fila)
} fila;

// Função para redimensionar a fila
void redimensiona(fila *f) {
    int nova_capacidade = f->N * 2;  // Dobrar a capacidade
    int *novo_dados = (int *)malloc(nova_capacidade * sizeof(int));

    int i = 0;
    // Copiar os dados da fila original para o novo vetor
    while (f->p != f->u) {
        novo_dados[i] = f->dados[f->p];
        f->p = (f->p + 1) % f->N;  // Atualizar posição de remoção
        i++;
    }

    // Liberar a memória do vetor antigo
    free(f->dados);

    f->dados = novo_dados;
    f->N = nova_capacidade;
    f->p = 0;
    f->u = i;
}

// Função para enfileirar
int enfileira(fila *f, int x) {
    // Verifica se a fila está cheia
    if ((f->u + 1) % f->N == f->p) {
        redimensiona(f);  // Redimensiona a fila
    }

    // Insere o valor na fila
    f->dados[f->u] = x;

    // Atualiza a posição de inserção
    f->u = (f->u + 1) % f->N;

    return 1;  // Retorna 1 indicando que a inserção foi bem-sucedida