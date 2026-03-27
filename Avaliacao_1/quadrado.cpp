#include <stdio.h>

int ehQuadradoPerfeito(int n) {
    

    return soma == n;
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);
    
    int soma = 0;
    int impar = 1;

    while (soma < numero) {
        soma += impar;
        impar += 2;
    }

    if (soma == numero) {
        printf("%d é um quadrado perfeito.\n", numero);
    } else {
        printf("%d não é um quadrado perfeito.\n", numero);
    }

    return 0;
}

