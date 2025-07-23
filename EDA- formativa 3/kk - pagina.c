#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int mediana3(int *v, int e, int d) {
    int m = e + (d - e) / 2;
    
    if (v[e] > v[m]) troca(&v[e], &v[m]);
    if (v[m] > v[d]) troca(&v[m], &v[d]);
    if (v[e] > v[m]) troca(&v[e], &v[m]);
    
    return m;
}

int separa(int *v, int e, int d) {
    int indice_pivo = mediana3(v, e, d);
    troca(&v[indice_pivo], &v[d]);
    
    int pivo = v[d];
    int i = e;
    int j = e;
    
    while (j < d) {
        if (v[j] < pivo) {
            troca(&v[i], &v[j]);
            i++;
        }
        j++;
    }
    troca(&v[i], &v[d]);
    return i;
}

void quickSelect(int *v, int e, int d, int k) {
    while (e < d) {
        int p = separa(v, e, d);
        
        if (k <= p) {
            d = p;
        } else {
            e = p + 1;
        }
    }
}

void quickSort(int *v, int e, int d) {
    if (e < d) {
        int p = separa(v, e, d);
        quickSort(v, e, p - 1);
        quickSort(v, p + 1, d);
    }
}

int main() {
    int N, P, X;
    scanf("%d %d %d", &N, &P, &X);

    int *v = malloc(N * sizeof(int));
    if (v == NULL) return 1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    int inicio = P * X;
    int fim = inicio + X - 1;
    
    if (fim >= N) {
        fim = N - 1;
    }
    
    quickSelect(v, 0, N - 1, fim);
    quickSort(v, 0, fim);

    for (int i = inicio; i <= fim; i++) {
        printf("%d\n", v[i]);
    }

    free(v);
    return 0;
}