#include <stdio.h>

unsigned long long soma_digitos(unsigned long long n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + soma_digitos(n / 10);
    }
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    printf("%llu\n", soma_digitos(n));
    return 0;
}
