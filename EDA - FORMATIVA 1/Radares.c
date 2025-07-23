#include <stdio.h>

// Função para calcular a velocidade média entre dois radares
double calculaVelocidadeMedia(int tA, int tB, double distancia) {
    // Calcula a diferença de tempo (em segundos) entre os dois radares
    int tempo = tB - tA;

    // Calcula a velocidade média (distância/tempo) e converte para km/h
    double velocidadeMedia = (distancia / tempo) * 3600.0;

    return velocidadeMedia;
}

// Função para verificar se o motorista levou multa
int levouMulta(int tA, int tB, double distancia, double velocidadeMaxima) {
    // Calcula a velocidade média usando a função anterior
    double velocidadeMedia = calculaVelocidadeMedia(tA, tB, distancia);

    // Verifica se a velocidade média ultrapassa a velocidade máxima permitida
    if (velocidadeMedia > velocidadeMaxima) {
        return 1;  // Motorista deve ser multado
    } else {
        return 0;  // Motorista não levou multa
    }
}
