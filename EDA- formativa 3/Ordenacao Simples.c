#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int *v, int n){
    for( int i = 1; i < n; i++){
        for(int j = i-1; j >= 0 && v[j] > v[j+1]; j--){
            troca(&v[j], &v[j+1]);
        }
    }
}

int main(){
    int n = 0;
    int MAX = 1000;
    int *v = malloc(MAX * sizeof(int));
    if (v == NULL) {
        fprintf(stderr, "Erro de alocação\n");
        return 1;
    }

    while (n < MAX && scanf("%d", &v[n]) == 1) {
        n++;
    }

    insertionSort(v, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
       
    }

    free(v);
    return 0;
}  

