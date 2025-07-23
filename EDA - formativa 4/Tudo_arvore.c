#include <stdio.h>
#include <stdlib.h>
// tudo de arvore, insere, remove (pelo antecessor), maximo, minimo e altura

typedef struct no{
    int chave;
    struct no *esq, *dir;
}no;
/*
no *inserir (no *r, int x){
    // insere quando a arvore nao tiver elementos, ou quando tiver em uma folha, cria nova variavel, aloca ela e passa o dado, e explicita q o os filhos de ambos os lados sao nulos
    if ( r == NULL){  
        no *novo = malloc(sizeof(no));
        novo -> chave = x;
        novo ->dir = novo -> esq = NULL;
        return novo;
    }
    // realiza a conta, se o elemento a ser colocado na arvore ja existe,é ignorado, se for menor insere na esquerda, se for maior na direita, retorna r
    if ( x == r-> chave) return r;
    if ( x < r ->chave){
        r ->esq = inserir(r->esq, x);
    }else{
        r-> dir = inserir(r->dir, x);
    }
    return r;
}*/

 
/*no *encontra_antecessor(no *r){
    no *atual = r -> esq;
    while (atual -> dir != NULL){
        atual = atual -> dir;
    }
    return atual;
}*/
/*
no* remover( no *r, int x){
    if (r == NULL) return NULL; // arvore ja ta vazia
    if ( x < r -> chave){   // elemento a ser removido pode ser maior ou menor na busca, se nao houver filho esquerdo, apago o direito, vice-versa
        r->esq = remover(r->esq, x);
    }else if( x > r -> chave ){
        r -> dir = remover( r-> dir, x);
    }else{
        if( r-> esq == NULL){
            no *temp = r->dir;
            free(r);
            return temp;
        }else if ( r-> dir == NULL){
            no *temp = r->esq;
            free(r);
            return temp;
        }else{
            no *antecessor = r->esq;
            while (antecessor -> dir != NULL) {
                antecessor = antecessor -> dir;
            }
            r->chave = antecessor ->chave;
            r->esq = remover(r-> esq, antecessor -> chave);
        }
        // especifica o dado do antecessor, e que vai sempre buscar remover usando esse no como criterio    
    }
    return r;
}*/


/* no *maximo (no *r){
    if ( r == NULL) return NULL;
    no *atual = r;
    while(atual -> dir != NULL){
        atual = atual -> dir;
    }
    return atual;
}*/
/*
no *minimo (no *r){
    if (r == NULL) return NULL;
    no *atual = r;
    while (atual -> esq != NULL){
        atual = atual -> esq;
    }
    return atual;
}*/
/*
no *encontra_sucessor( no *r){
    if (r == NULL) return NULL;
    no *atual = r -> dir;
    while(atual -> esq != NULL){
        atual = atual -> esq;
    }
    return atual;
}
*/

int altura (no *r){
    if ( r == NULL) return 0;
    int altura_esq = altura(r->esq);
    int altura_dir = altura( r-> dir);
    return ( altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
} 