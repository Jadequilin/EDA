#include <stdio.h>

void toRoman(int num) {
    // Arrays com os valores romanos e seus respectivos símbolos
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // String para armazenar o resultado
    char result[20] = "";
    
    // Itera sobre os valores e símbolos romanos
    for (int i = 0; i < 13; i++) {
        // Enquanto o número for maior ou igual ao valor atual, subtraímos e adicionamos o símbolo correspondente
        while (num >= values[i]) {
            num -= values[i];
            strcat(result, symbols[i]);
        }
    }
    
    // Imprime o resultado
    printf("%s\n", result);
}

int main() {
    int n;
    
    // Lê a quantidade de números a serem convertidos
    scanf("%d", &n);
    
    // Lê os números inteiros a serem convertidos
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        
        // Converte cada número para o formato romano e imprime
        toRoman(value);
    }
    
    return 0;
}
