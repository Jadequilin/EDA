#include <stdio.h>
#include <stdlib.h> 

typedef struct{
    int valor;
    int posicao_original;
}elemento;

void troca (elemento *a, elemento *b){
    elemento temp = *a;
    *a = *b;
    *b = temp;
}

int separa(elemento *v, int e, int d){
    int c = v[d].valor;
    int j = e, k = e;
    while(k < d){
        if(v[k].valor <= c){
            troca(&v[k], &v[j]);
            j++;
        }
    k++;    
    }
    troca(&v[j], &v[d]);
    return j;
}

void quickSort(elemento *v, int e, int d){
    if(e < d){
        int p = separa(v, e, d);
        quickSort(v, e, p-1);
        quickSort(v, p+1, d);
    }
}

int buscaBinaria(elemento *v, int n, int x){
    int e = -1;
    int d = n;
    while(e < d){
        int m = (d+e)/2;
        if(x == v[m].valor) return v[m].posicao_original;
        if (x > v[m].valor){
            e = m;
        }else{
            d = m;
        }
    }
    return d;
}

int main(){
    int N, M;
    scanf(" %d %d", &N, &M);
    elemento *v = malloc( N* sizeof(elemento));
    for( int i = 0; i < N; i++){
        scanf(" %d", &v[i].valor);
        v[i].posicao_original = i;
    }
    quickSort(v, 0, N-1);

    int posicao_atual = 0;
    int tempo_total = 0;
  
    for(int i = 0; i < M; i++){
        int x;
        scanf(" %d", &x);
        int pos = buscaBinaria(v, N, x);
        if (pos != -1){
            tempo_total += abs(posicao_atual - pos);
            posicao_atual = pos;
        }
        
    }
    printf("%d\n", tempo_total);
    free(v);
    return 0;


}