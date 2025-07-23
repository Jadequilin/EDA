#include <stdio.h>

int main() {
    int F, L;
    scanf("%d %d", &F, &L);

    char sala[20][25] = {{0}};  // Inicializa a sala com 0 (vazio)

    char fileira;
    int lugar;

    // Lê os lugares ocupados enquanto houver entradas válidas
    while (scanf(" %c%d", &fileira, &lugar) == 2) {
        int linha = fileira - 'A';  // Converte a letra da fileira para o índice
        int coluna = lugar - 1;     // Converte o número do lugar para o índice
        sala[linha][coluna] = 1;    // Marca o lugar como ocupado
    }

    // Exibe o mapa da sala
    printf("  ");
    for (int i = 0; i < L; i++) {
        printf("%02d ", i + 1);  // Imprime os números dos lugares (01 a 25)
    }
    printf("\n");

    // Imprime o mapa da sala, começando de baixo para cima
    for (int i = F - 1; i >= 0; i--) {
        printf("%c ", 'A' + i);  // Imprime a letra da fileira
        for (int j = 0; j < L; j++) {
            if (sala[i][j] == 1)
                printf("XX");  // Lugar ocupado
            else
                printf("--");  // Lugar vazio
            if (j < L - 1) printf(" ");  // Não coloca espaço após o último número
        }
        printf("\n");
    }

    return 0;  // Colocado fora do while para garantir que o programa execute completamente
}
