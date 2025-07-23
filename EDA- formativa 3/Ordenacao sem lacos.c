#include <stdio.h>
#include <stdlib.h>

/*void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordena(int *v, int n){
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0 && v[j] > v[j+1]; j--){
            troca(&v[j], &v[j+1]);
        }
    }
}*/

void insere(int *v, int n, int i) {
    if (i <= 0)
        return;

    if (v[i] < v[i - 1]) {
        int temp = v[i];
        v[i] = v[i - 1];
        v[i - 1] = temp;
        insere(v, n, i - 1);
    }
}

void ordena_rec(int *v, int n, int i) {
    if (i >= n)
        return;

    insere(v, n, i);
    ordena_rec(v, n, i + 1);
}

void ordena(int *v, int n) {
    ordena_rec(v, n, 1);
}