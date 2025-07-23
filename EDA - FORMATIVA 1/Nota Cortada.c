#include <stdio.h>

int main() {
    // Definindo as dimensões da nota como constantes
    const int h = 160;  // Largura da nota
    const int w = 70;   // Altura da nota
    
    int B,T;
    
    // Lê a distância do corte na base
    scanf("%d", &B);
    scanf("%d", &T);

    // Calcula a área total da nota e metade da área
    int area_total = (B + T) * w ;   // A área total da nota
    int metade_area = area_total / 2;  // Metade da área total

    // Verifica quem tem o pedaço que vale 100 reais
    if ( metade_area > w/2 * h) {
        printf("1\n");  // Eduardo ficou com o pedaço maior
    } else if (metade_area < w/2 * h) {
        printf("2\n");  // Daiane ficou com o pedaço maior
    } else {
        printf("0\n");  // A nota perdeu o valor
    }
    
    return 0;
}
