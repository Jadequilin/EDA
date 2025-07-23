#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(long long int *r, int n, long long int dist){
    int e = 0;
    int d = n-1;
    while(e <= d){
        int m = (e+d)/2;
        if (dist > r[m]){
            e = m + 1;
        }else{
         d = m - 1;
        }
    }  
    return e;
}

int main(){
    int C, T;
    scanf(" %d %d", &C, &T);

    long long int *r = malloc(C * sizeof(long long int));
    if ( r == NULL) return 1;

    for (int i = 0; i < C; i++){
        int R;
        scanf(" %d", &R);
        r[i] = (long long int)R * R;
    }

    long long int pt = 0;
    for(int i = 0; i < T; i++){
        int X, Y;
        scanf(" %d %d", &X, &Y);
        long long int dist = (long long int)X *X + (long long int)Y*Y;
        pt += C - buscaBinaria(r, C, dist);
    }
    printf("%lld\n", pt);
    free(r);
    return 0;
}

