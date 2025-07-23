#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int *v, int n, int x){
    int e = -1;
    int d = n;
    while ( e < d - 1){
        int m = (e+d)/2;
        if( x == v[m]) return m;
        if(x > v[m]) { e = m;
        } else{ 
            d = m; 
        } 
    }
    return d;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    
    int *v = malloc(N * sizeof(int));
    for( int i = 0; i < N; i++){
        scanf(" %d", &v[i]);
    }
    
    for(int i  = 0; i < M; i++){
        int x;
        scanf(" %d", &x);
        int j = BuscaBinaria(v, N, x);
        printf(" %d\n", j);
    }
    free(v);
    return 0;
}