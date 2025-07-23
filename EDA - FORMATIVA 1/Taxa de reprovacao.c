#include <stdio.h>
#include <stdlib.h>

// Função para comparar dois códigos (usada pelo quicksort)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int D;
    scanf("%d", &D);  // Lê o número total de disciplinas (não utilizado diretamente)

    int ano, semestre, m;
    // Processa cada semestre
    while (scanf("%d %d %d", &ano, &semestre, &m) == 3) {
        int max_reprovados = -1;
        int codigos[100]; // Armazena os códigos das disciplinas com mais reprovados
        int qtd_codigos = 0;

        // Processa as disciplinas do semestre
        for (int i = 0; i < m; i++) {
            int codigo, matriculados, aprovados;
            scanf("%d %d %d", &codigo, &matriculados, &aprovados);

            int reprovados = matriculados - aprovados; // Calcula o número de reprovados

            // Se a disciplina tem mais reprovados, atualiza
            if (reprovados > max_reprovados) {
                max_reprovados = reprovados;
                codigos[0] = codigo; // Atualiza o primeiro código
                qtd_codigos = 1;      // Reseta a quantidade de códigos
            } else if (reprovados == max_reprovados) {
                codigos[qtd_codigos++] = codigo; // Adiciona outro código com o mesmo número de reprovados
            }
        }

        // Ordena os códigos das disciplinas com o maior número de reprovados
        qsort(codigos, qtd_codigos, sizeof(int), compare);

        // Imprime a saída no formato correto
        printf("%d/%d\n", ano, semestre);

        // Imprime os códigos separados por espaço
        for (int i = 0; i < qtd_codigos; i++) {
            if (i > 0) {
                printf(" "); // Espaço entre os números
            }
            printf("%d", codigos[i]);
        }

        // Linha em branco após cada semestre
        printf("\n\n");
    }

    return 0;
}
