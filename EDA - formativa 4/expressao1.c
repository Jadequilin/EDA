#include <stdio.h>

#define TAMANHO_MAX 500

// Estrutura da pilha
typedef struct {
    char dados[TAMANHO_MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;  // -1 indica pilha vazia
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Empilha um caractere
void empilhar(Pilha *p, char c) {
    if (p->topo < TAMANHO_MAX - 1) {
        p->dados[++p->topo] = c;
    }
}

// Desempilha um caractere
char desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->dados[p->topo--];
    }
    return '\0';  // Retorno nulo se a pilha estiver vazia
}

// Verifica se dois delimitadores combinam
int ehParValido(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')') return 1;
    if (abertura == '[' && fechamento == ']') return 1;
    if (abertura == '{' && fechamento == '}') return 1;
    return 0;  // Não combinam
}

// Verifica se a expressão está balanceada
int estaBalanceada(char *expressao) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            empilhar(&p, expressao[i]);  // Empilha abertura
        }
        else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if (estaVazia(&p) || !ehParValido(desempilhar(&p), expressao[i])) {
                return 0;  // Pilha vazia ou não combina
            }
        }
    }

    return estaVazia(&p);  // Se a pilha estiver vazia, está balanceado
}

int main() {
    char expressao[TAMANHO_MAX + 1];
    int i = 0;
    char c;

    // Lê a expressão caractere por caractere
    while ((c = getchar()) != '\n' && c != EOF && i < TAMANHO_MAX) {
        expressao[i++] = c;
    }
    expressao[i] = '\0';  // Termina a string

    if (estaBalanceada(expressao)) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}