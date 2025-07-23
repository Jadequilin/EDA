#include <stdlib.h>
#include <string.h>

typedef struct fila {
  int *dados;
  int N, p, u;
} fila;

int enfileira (fila *f, int x) {
  // 1. Verifica se a fila precisa ser redimensionada
  if (f->N == 0 || (f->u + 1) % f->N == f->p) {
    int N_antigo = f->N;
    int novo_tamanho = (N_antigo == 0) ? 16 : N_antigo * 2;
    
    int *novos_dados = malloc(novo_tamanho * sizeof(int));
    if (novos_dados == NULL) return 0;

    int p_final = f->p;
    int u_final = f->u;

    if (N_antigo == 0) { // Caso 1: Primeira alocação
        p_final = 0;
        u_final = 0;
    } else if (f->p > f->u) { // Caso 2: Fila "enrolada"
        int size_p = N_antigo - f->p;
        int size_u = f->u;

        if (size_p < size_u) { // Estratégia A: Bloco do final é menor
            memcpy(&novos_dados[novo_tamanho - size_p], &f->dados[f->p], size_p * sizeof(int));
            memcpy(&novos_dados[0], &f->dados[0], size_u * sizeof(int));
            p_final = novo_tamanho - size_p;
            // u_final não muda nesta etapa
        } else { // Estratégia B: Bloco do começo é menor ou igual
            int i = 0;
            int j = f->p;
            while (j != f->u) {
                novos_dados[f->p + i] = f->dados[j];
                i++;
                j = (j + 1) % N_antigo;
            }
            // p_final não muda
            u_final = f->p + i;
        }
        free(f->dados);
    } else { // Caso 3: Fila contígua (não enrolada)
        memcpy(&novos_dados[f->p], &f->dados[f->p], (f->u - f->p) * sizeof(int));
        // p_final não muda
        // u_final não muda
        free(f->dados);
    }
    
    f->dados = novos_dados;
    f->N = novo_tamanho;
    f->p = p_final;
    f->u = u_final;
  }

  // Com espaço garantido, insere o elemento
  f->dados[f->u] = x;
  f->u = (f->u + 1) % f->N;
  
  return 1;
}

// Não tem jeito desse codigo ser a logica certa e convencional