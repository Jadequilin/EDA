#include <stdio.h>

#define MAX_MENORES 100

int mp[MAX_MENORES];
int tm = 0;

int busca_binaria(int *v, int n, int x){
    int e = 0;
    int d = n-1;
    int pos = n;

    while(e <= d){
        int m = (e+d)/2;
        
        if (v[m] == x){
            return -1;
        }else if (v[m] < x){
            e = m + 1;
        }else{ 
            d = m - 1;
            pos = m;
        }
    }
    return pos;
}

void insPlaca(int p){
    if (tm == MAX_MENORES && p >= mp[MAX_MENORES-1]){
        return;
    }
    int pos1 = busca_binaria(mp, tm, p);

    if(pos1 == -1) return;

    if(tm < MAX_MENORES){

        for( int i = tm; i > pos1; i--){
            mp[i] = mp[i-1];
        }
        mp[pos1] = p;
        tm ++;
    }
    else if (pos1 < MAX_MENORES){
        for (int i = MAX_MENORES-1; i> pos1; i--){
            mp[i] = mp[i-1];
        }
        mp[pos1] = p;
    }
}

void imprimir_menores(int T){
    if (T >  MAX_MENORES) T = MAX_MENORES;
    if (T > tm) T = tm;

    for (int i= 0; i < T; i++){
        printf(" %d", mp[i]);
        if ( i < T - 1){
            printf(" ");
        }
    }
    printf("\n");
}

int main(){
    int ope, valor;

    while (scanf(" %d", &ope) != EOF){
        if (ope == 1){
            scanf("%d", & valor);
            insPlaca(valor);

        }else if (ope == 2){
            scanf(" %d", &valor);
            imprimir_menores(valor);
        }
    }
    return 0;
}


