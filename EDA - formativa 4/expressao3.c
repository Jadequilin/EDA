#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 501
#define MAX_VARIABLES 26

typedef struct {
    char name;
    int value;
} Variable;

Variable variables[MAX_VARIABLES];
int num_variables = 0;

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    switch (op) {
        case '^': return 4;  // Maior precedência
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default: return 0;
    }
}

void apply_operator(int *stack, int *top, char op) {
    int b = stack[(*top)--];
    int a = stack[(*top)--];
    int result;
    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = a / b; break;
        case '^': result = (int)pow(a, b); break;
        default: result = 0;
    }
    stack[++(*top)] = result;
}

int evaluate_expression(const char *expr) {
    int value_stack[MAX_EXPRESSION_LENGTH];
    char operator_stack[MAX_EXPRESSION_LENGTH];
    int value_top = -1;
    int operator_top = -1;
    int i = 0;
    
    while (expr[i] != '\0') {
        if (expr[i] == ' ') {
            i++;
            continue;
        }
        
        if (expr[i] == '(') {
            operator_stack[++operator_top] = expr[i];
            i++;
        } 
        else if (expr[i] == ')') {
            while (operator_top >= 0 && operator_stack[operator_top] != '(') {
                apply_operator(value_stack, &value_top, operator_stack[operator_top--]);
            }
            if (operator_top < 0) return -1; // Parenteses desbalanceados
            operator_top--; // Remove '('
            i++;
        } 
        else if (is_operator(expr[i])) {
            while (operator_top >= 0 && 
                   operator_stack[operator_top] != '(' &&
                   (precedence(operator_stack[operator_top]) > precedence(expr[i]) ||
                   (precedence(operator_stack[operator_top]) == precedence(expr[i]) && expr[i] != '^'))) {
                apply_operator(value_stack, &value_top, operator_stack[operator_top--]);
            }
            operator_stack[++operator_top] = expr[i];
            i++;
        } 
        else {
            int num = 0;
            if (isalpha(expr[i])) {
                char var = expr[i];
                int found = 0;
                for (int j = 0; j < num_variables; j++) {
                    if (variables[j].name == var) {
                        num = variables[j].value;
                        found = 1;
                        break;
                    }
                }
                if (!found) return -1; // Variável não encontrada
                i++;
            } else {
                while (isdigit(expr[i])) {
                    num = num * 10 + (expr[i] - '0');
                    i++;
                }
            }
            value_stack[++value_top] = num;
        }
    }
    
    while (operator_top >= 0) {
        if (operator_stack[operator_top] == '(') return -1;
        apply_operator(value_stack, &value_top, operator_stack[operator_top--]);
    }
    
    if (value_top != 0) return -1; // Expressão inválida
    return value_stack[value_top];
}

int check_parentheses(const char *expr) {
    int balance = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') balance++;
        else if (expr[i] == ')') {
            balance--;
            if (balance < 0) return 0;
        }
    }
    return balance == 0;
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
    expression[strcspn(expression, "\n")] = '\0';

    if (!check_parentheses(expression)) {
        printf("emf\n");
        return 0;
    }

    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '\n') continue;
        line[strcspn(line, "\n")] = '\0';
        char *equal_sign = strchr(line, '=');
        if (equal_sign == NULL) continue;
        *equal_sign = '\0';
        char var = line[0];
        int value = atoi(equal_sign + 1);
        variables[num_variables].name = var;
        variables[num_variables].value = value;
        num_variables++;
    }

    int result = evaluate_expression(expression);
    if (result == -1) {
        printf("emf\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}