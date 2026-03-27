#include <stdio.h>

char* lastOccur(char* str, char ch) {
    char* last = NULL;  // Ponteiro para armazenar a última ocorrência

    // Percorre a string até o final
    while (*str != '\0') {
        if (*str == ch) {
            last = str;  // Atualiza o ponteiro se encontrar o caractere
        }
        str++;
    }

    return last;  // Retorna a última ocorrência ou NULL se não encontrado
}

int main() {
    char str[100];  // Define uma string com espaço suficiente
    char ch;

    printf("Digite uma string: ");
    scanf("%s", str);  // Lê a string sem '&' (não necessário para arrays)

    printf("Digite um caractere: ");
    scanf(" %c", &ch);  // Espaço antes de %c para ignorar '\n' anterior

    char* result = lastOccur(str, ch);  // Chama a função

    if (result != NULL) {
        printf("Última ocorrência de '%c': %ld\n", ch, result - str);
    } else {
        printf("Caractere '%c' não encontrado na string.\n", ch);
    }

    return 0;
}

