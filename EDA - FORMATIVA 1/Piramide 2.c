#include <stdio.h>

int main() {
    int n;
    
    // Lê o número n
    scanf("%d", &n);
    
    // Primeira pirâmide (n linhas)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%02d", i); // Imprime o número i com dois dígitos
            if (j < i) {
                printf(" "); // Adiciona espaço entre os números na mesma linha
            }
        }
        printf("\n"); // Pula linha ao final de cada linha da pirâmide
    }

    printf("\n"); // Linha em branco entre as pirâmides
    
    // Segunda pirâmide (n linhas)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%02d", j); // Imprime o número j com dois dígitos
            if (j < i) {
                printf(" "); // Adiciona espaço entre os números na mesma linha
            }
        }
        printf("\n"); // Pula linha ao final de cada linha da pirâmide
    }
    
    return 0;
}

