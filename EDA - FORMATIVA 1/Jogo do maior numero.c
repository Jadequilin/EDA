#include <stdio.h>
#include <math.h>

int main() {
    int a, b, n;
    
    // Lê os inteiros a, b para a exponenciação e o número n para o fatorial
    scanf("%d %d", &a, &b);
    scanf("%d", &n);
    
    // Calcular logaritmo de a^b, que é b * log(a)
    double log_lucas = b * log(a);
    
    // Calcular logaritmo de n! somando log(1), log(2), ..., log(n)
    double log_pedro = 0.0;
    for (int i = 1; i <= n; i++) {
        log_pedro += log(i);
    }
    
    // Comparar os dois logaritmos
    if (log_lucas > log_pedro) {
        printf("Lucas\n");
    } else {
        printf("Pedro\n");
    }
    
    return 0;
}
