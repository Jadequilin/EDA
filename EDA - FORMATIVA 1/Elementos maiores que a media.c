#include <stdio.h>

int main() {
    int N;

    // Lê o tamanho do vetor
    scanf("%d", &N);
    
    int vetor[N];  // Definir o vetor com N elementos
    long int soma = 0;  // Alterar para long int para evitar overflow

    // Lê os elementos do vetor e calcula a soma
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    // Calcula a média aritmética (média inteira) com tipo long int
    long int media = soma / N;

    // Variável para verificar se há números maiores que a média
    int encontrou = 0;

    // Imprimir os elementos maiores que a média
    for (int i = 0; i < N; i++) {
        if (vetor[i] > media) {
            if (encontrou) {
                printf(" ");  // Espaço entre os números
            }
            printf("%d", vetor[i]);
            encontrou = 1;  // Marca que encontramos pelo menos um número maior que a média
        }
    }

    // Se não houver nenhum número maior que a média, imprime 0
    if (!encontrou) {
        printf("0");
    }

    printf("\n");  // Quebra de linha após a saída
    return 0;
}



