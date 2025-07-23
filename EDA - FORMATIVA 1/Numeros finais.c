#include <stdio.h>
#include <string.h>

// Função que verifica se b está nos últimos dígitos de a
int encaixa(int a, int b) {
    // Converte os números para strings
    char str_a[20], str_b[20];  // Buffers para armazenar os números como strings
    sprintf(str_a, "%d", a);
    sprintf(str_b, "%d", b);
    
    // Calcula o tamanho de str_b e verifica os últimos dígitos de str_a
    int len_a = strlen(str_a);
    int len_b = strlen(str_b);

    // Se a quantidade de dígitos de b for maior que a de a, não pode encaixar
    if (len_b > len_a) {
        return 0;
    }

    // Compara os últimos len_b dígitos de str_a com str_b
    if (strcmp(str_a + len_a - len_b, str_b) == 0) {
        return 1;
    }
    
    return 0;
}

