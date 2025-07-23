#include <stdio.h>
#include <stdio.h>

// Função recursiva que calcula o grau-9
int grau_9_rec(char *num_str) {
    int soma = 0;
    for (int i = 0; num_str[i] != '\0'; i++) {
        soma += num_str[i] - '0';
    }

    // Caso base: soma tem um dígito
    if (soma < 10) {
        if (soma == 9) {
            return 1; // múltiplo de 9 com grau 1
        } else {
            return 0; // não múltiplo de 9
        }
    } else {
        // Converte soma para string para chamada recursiva
        char soma_str[20];
        sprintf(soma_str, "%d", soma);
        int res = grau_9_rec(soma_str);
        if (res == 0) {
            return 0;
        } else {
            return res + 1;
        }
    }
}

int main() {
    char numero[1100];

    while (scanf("%s", numero) == 1) {
        if (numero[0] == '0' && numero[1] == '\0') {
            break; // fim da entrada
        }

        int grau = grau_9_rec(numero);

        if (grau > 0) {
            printf("%s is a multiple of 9 and has 9-degree %d.\n", numero, grau);
        } else {
            printf("%s is not a multiple of 9.\n", numero);
        }
    }

    return 0;
}
