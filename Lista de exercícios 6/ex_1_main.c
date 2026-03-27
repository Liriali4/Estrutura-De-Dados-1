#include <stdio.h>
#include <stdlib.h>
#include "ex_1.c"

int main() {
    Lista *lista = inicializarLista(); // Inicializa a lista vazia
    int numero;

    printf("Digite numeros para adicionar à lista (digite -1 para terminar):\n");

    // Lê números do utilizador até ele digitar -1
    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero == -1) break; // Sai do loop se o número for -1

    	lista = inserirNo(lista, numero); // Insere o número na lista
    }

    printf("\nLista na ordem inversa:\n");
    imprimirListaInversa(lista); // Imprime a lista na ordem inversa
    printf("\n");

    return 0;
}

