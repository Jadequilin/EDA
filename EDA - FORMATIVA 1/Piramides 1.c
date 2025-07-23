#include <stdio.h>

int main() {
    int N;
    
    // Lê a dimensão da pirâmide
    scanf("%d", &N);
    
    // Preenche e imprime a pirâmide linha por linha
    for (int i = 0; i < N; i++) {  // Laço externo para percorrer cada linha
        for (int j = 0; j < N; j++) {  // Laço interno para percorrer cada coluna
            // Calcula o valor para a célula (i, j) diretamente
            int camada = (i < j) ? i : j;   // Menor entre i e j
            camada = (camada < N - i - 1) ? camada : N - i - 1;  // Menor entre i, j e borda inferior
            camada = (camada < N - j - 1) ? camada : N - j - 1;  // Menor entre i, j, borda inferior e direita
            printf("%d ", camada + 1);  // Adiciona 1 para indicar a camada
        }
        printf("\n");  // Nova linha após cada linha da pirâmide
    }
    
    return 0;
}
