#include <stdio.h>

int main() {
    int num, i, j, soma, contPerfeitos = 0;

    printf("Digite 9 numeros inteiros:\n");

    for (i = 1; i <= 9; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &num);

        soma = 0;
        
        for (j = 1; j <= num / 2; j++) {
            if (num % j == 0) {
                soma += j;
            }
        }

        if (soma == num && num != 0) {
            printf("%d e um numero perfeito.\n", num);
            contPerfeitos++;
        }
    }

    printf("\nQuantidade de números perfeitos: %d\n", contPerfeitos);

    return 0;
}

