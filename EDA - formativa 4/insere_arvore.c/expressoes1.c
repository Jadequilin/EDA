#include <stdio.h>
#include <stdlib.h>
typedef struct celula
{
    int dado;
    struct celula *prox;
}pilha;

pilha *cria_pilha(){
    pilha *p = malloc(sizeof(pilha));
    p -> prox = NULL;
    return p;
}

int empilha(pilha *p, int x){
    pilha *novo = malloc(sizeof(pilha));
    novo -> dado = x;
    novo->prox = p -> prox;
    p->prox = novo;
    return 0;
}

pilha *desempilha(pilha *p){
    if ( p-> prox == NULL) return NULL;
    pilha *rem = p-> prox;
    p-> prox = rem -> prox;
    return rem;
}

int parentiza(char *palavra){
    pilha *p = cria_pilha();
    int i = 0;
    while( palavra[i] != '\0'){
        if( palavra[i] == '{' || palavra[i] == '[' || palavra[i] == '('){
            empilha(p, palavra[i]);
        }else if( palavra[i] == ')'){
            pilha *temp = desempilha(p);
            if (temp == NULL || temp -> dado != '(' ) return 1;
        }else if( palavra[i] == ']'){
            pilha *temp = desempilha(p);
            if(temp == NULL || temp -> dado != '[' ) return 1;
        }else if( palavra[i] == '}'){
            pilha *temp = desempilha(p);
            if( temp == NULL || temp -> dado != '{' ) return 1;
        }
        i++;
    }
    if (desempilha(p) != NULL){
        return 1;
    }else{
        return 0;
    }
    return 0;
}

int main(){
    char palavra[5000];
    scanf("%[^\n]s", palavra);
    if(parentiza(palavra) == 0){
        printf("sim");
    }else{
        printf("nao");
    }
}

