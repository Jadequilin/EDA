#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char dado;
    struct no *prox;
} no;

no *criar_pilha() {
    no *cabeca = malloc(sizeof(no));
    cabeca->prox = NULL;
    return cabeca;
}

void empilhar(no *pilha, char valor) {
    no *novo = malloc(sizeof(no));
    novo->dado = valor;
    novo->prox = pilha->prox;
    pilha->prox = novo;
}

char desempilhar(no *pilha) {
    if (pilha->prox == NULL) return '\0';
    no *temp = pilha->prox;
    char valor = temp->dado;
    pilha->prox = temp->prox;
    free(temp);
    return valor;
}

char topo(no *pilha) {
    if (pilha->prox == NULL) return '\0';
    return pilha->prox->dado;
}

int precedencia(char op) {
    switch(op) {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default: return 0;
    }
}

int eh_operador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void converter_infixo_para_posfixo(char *entrada, char *saida) {
    no *pilha = criar_pilha();
    int i = 0, j = 0;
    int parenteses_abertos = 0;

    while (entrada[i] != '\0') {
        char c = entrada[i];

        if (c >= 'A' && c <= 'Z') {
            saida[j++] = c;
        }
        else if (c == '(') {
            empilhar(pilha, c);
            parenteses_abertos++;
        }
        else if (c == ')') {
            if (parenteses_abertos <= 0) {
                // Parêntese fechando sem abrir
                saida[0] = '\0';
                return;
            }
            parenteses_abertos--;
            
            while (topo(pilha) != '(') {
                char op = desempilhar(pilha);
                if (op == '\0') break;
                saida[j++] = op;
            }
            desempilhar(pilha); // Remove o '(' da pilha
        }
        else if (eh_operador(c)) {
            while (topo(pilha) != '\0' && topo(pilha) != '(' && 
                   precedencia(topo(pilha)) >= precedencia(c)) {
                if (c == '^' && topo(pilha) == '^') {
                    break; // Associatividade direita para exponenciação
                }
                saida[j++] = desempilhar(pilha);
            }
            empilhar(pilha, c);
        }
        i++;
    }

    // Verifica parênteses não fechados
    if (parenteses_abertos != 0) {
        saida[0] = '\0';
        return;
    }

    // Desempilha operadores restantes
    while (topo(pilha) != '\0') {
        char op = desempilhar(pilha);
        if (op == '(') {
            // Parêntese aberto sem fechar
            saida[0] = '\0';
            return;
        }
        saida[j++] = op;
    }

    saida[j] = '\0';
}

int main() {
    char entrada[501];
    char saida[501];
    
    scanf("%500[^\n]", entrada);

    converter_infixo_para_posfixo(entrada, saida);

    if (saida[0] == '\0') {
        printf("incorretamente parentizada\n");
    } else {
        printf("%s\n", saida);
    }

    return 0;
}