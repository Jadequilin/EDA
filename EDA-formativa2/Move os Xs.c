#include <stdio.h>
#include <string.h>

void moveX(char *str, int pos, int write_pos, int x_count) {
    if (str[pos] == '\0') {
        memset(str + write_pos, 'x', x_count);
        str[write_pos + x_count] = '\0';
        return;
    }

    if (str[pos] == 'x') {
        moveX(str, pos + 1, write_pos, x_count + 1);
    } else {
        str[write_pos] = str[pos];
        moveX(str, pos + 1, write_pos + 1, x_count);
    }
}

int main() {
    char str[101];

    if (!fgets(str, sizeof(str), stdin)) {
        return 1; // erro na leitura
    }

    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    moveX(str, 0, 0, 0);

    printf("%s\n", str);

    return 0;
}
