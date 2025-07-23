 #include <stdio.h>
 #include <string.h>

 void inverter(char *str, int inicio, int fim){
        if (inicio >= fim){
            return;
        }
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inverter(str, inicio + 1, fim -1);
 }
 int main(void){
    char str[501];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n'){
        str[len -1] = '\0';
        len--;
    }
inverter(str, 0, len - 1);
    printf("%s\n", str);
    return 0;
 }