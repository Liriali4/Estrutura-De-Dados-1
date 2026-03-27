#include <stdio.h>

int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1); 
    }
}

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fatorial não está definido para números negativos.\n");
    } else {
        printf("O fatorial de %d é: %d\n", num, fatorial(num));
    }

    return 0;
}

