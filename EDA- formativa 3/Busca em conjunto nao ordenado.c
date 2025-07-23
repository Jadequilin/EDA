#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    int posicao_original;
}elemento;

void intercala(elemento *v, int e, int m, int d){
    int i = e, j = m + 1 , k = 0;
    elemento *aux = malloc((d - e + 1) * sizeof(elemento));
    while( i <= m && j <=d){
        if(v[i].valor <= v[j].valor){
            aux[k++] = v[i++];
        }else{
            aux[k++] = v[j++];
        }
    }
    while( i <= m) aux [k++] = v[i++];
    while(j <= d) aux [k++] = v[j++];
    for( k = 0, i = e; i <= d; k++, i++){
        v[i] = aux[k];
    }
    free(aux);
}

void MergeSort(elemento *v, int e, int d){
    if(e < d){
        int m = (e + d)/2;
        MergeSort(v, e, m);
        MergeSort(v, m+1, d);
        intercala(v, e , m, d);
    }
}

int BuscaBinaria(elemento *v, int n, int x){
    int e = 0;
    int d = n-1; 
    while ( e <= d ){
        int m = (e+d)/2;
        if( x == v[m].valor) return v[m].posicao_original;
        if(x > v[m].valor) { e = m + 1;
        } else{ 
            d = m - 1; 
        } 
    }
    return -1;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    elemento *v = malloc(N * sizeof(elemento));
    if (v == NULL) {
        fprintf(stderr, "Erro de alocação\n");
        return 1;
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &v[i].valor);
        v[i].posicao_original = i;
    }

    MergeSort(v, 0, N - 1);

    for(int i = 0; i < M; i++){
        int x;
        scanf("%d", &x);
        int pos = BuscaBinaria(v, N, x);
        printf("%d\n", pos);
    }

    free(v);
    return 0;
}

