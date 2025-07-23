#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1003

char map[MAX][MAX];
bool visited[MAX][MAX];
int rows = 0, cols = 0;

typedef struct {
    int row, col;
} Position;

Position start, end;

// Direções: cima, baixo, esquerda, direita
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool isValid(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

// Função BFS modificada para contar apenas buracos ('o') no caminho S -> E
int countHoles() {
    Position queue[MAX * MAX];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start.row][start.col] = true;

    int holes = 0;

    while (front < rear) {
        Position current = queue[front++];

        // Se chegou ao destino, retorna o número de buracos
        if (current.row == end.row && current.col == end.col) {
            return holes;
        }

        // Explora as 4 direções
        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];

            if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                // Se for parte da ponte ('_' ou 'o') ou o destino ('E')
                if (map[newRow][newCol] == '_' || map[newRow][newCol] == 'o' || map[newRow][newCol] == 'E') {
                    visited[newRow][newCol] = true;
                    queue[rear++] = (Position){newRow, newCol};

                    // Conta apenas os buracos ('o')
                    if (map[newRow][newCol] == 'o') {
                        holes++;
                    }
                }
            }
        }
    }

    // Nunca será executado (pois o caminho S->E é garantido)
    return -1;
}

int main() {
    int P;
    scanf("%d", &P);

    // Leitura do mapa
    while (scanf("%s", map[rows]) != EOF) {
        cols = strlen(map[rows]);
        for (int col = 0; col < cols; col++) {
            if (map[rows][col] == 'S') {
                start.row = rows;
                start.col = col;
            } else if (map[rows][col] == 'E') {
                end.row = rows;
                end.col = col;
            }
        }
        rows++;
    }

    // Conta os buracos no caminho (caminho S->E é garantido)
    int holes = countHoles();

    // Calcula patos sobreviventes
    int survived = P - holes;

    // Saída conforme as condições
    if (survived <= 0) {
        printf("Todos morreram :)\n");
    } else if (holes == 0) {
        printf("Nenhum morreu :(\n");
    } else {
        printf("%d encontraram o vovo\n", survived);
    }

    return 0;
}
