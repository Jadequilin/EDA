#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    // Caso base: se chegou no meio ou ultrapassou, é PA
    if (primeiro >= ultimo) {
        return 1;
    }

    // Verifica se soma do primeiro com ultimo é igual a soma do próximo com penúltimo
    if (v[primeiro] + v[ultimo] != v[primeiro + 1] + v[ultimo - 1]) {
        return 0; // Não é PA
    }

    // Chamada recursiva para os próximos pares
    return pa_recursiva(v, primeiro + 1, ultimo - 1);
}
