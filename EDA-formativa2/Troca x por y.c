#include <stdio.h>
#include <string.h>

void replace_x_with_y(char *str) {
    if (*str == '\0') return;
    if (*str == 'x') *str = 'y';
    replace_x_with_y(str + 1);
}

int main() {
    char str[251];  // buffer maior

    if (!fgets(str, sizeof(str), stdin)) {
        return 1; // erro na leitura
    }

    // Remove '\n' do final, se existir
    size_t len = strlen(str);
    if (len > 0 && str[len -1] == '\n') {
        str[len -1] = '\0';
    }

    replace_x_with_y(str);

    printf("%s\n", str);

    return 0;
}
