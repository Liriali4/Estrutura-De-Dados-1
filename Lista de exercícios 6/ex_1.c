#include <stdio.h>
#include "ex_1.h"

//Cria uma lista vazia
Lista * inicializarLista()
{
return NULL;
}

Lista *inserirNo(Lista *ponteiro, int valor) {
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = ponteiro;
        
    } else {
        printf("Erro de alocação!\n");
    }
    return novo; // Certifique-se de retornar o novo ponteiro
}


// Imprime a lista na ordem inversa usando recursão
void imprimirListaInversa(Lista *ponteiro) {
	while(ponteiro->prox != NULL){
		printf("%d ", ponteiro->valor);
	}
    /*if (ponteiro != NULL) {
        imprimirListaInversa(ponteiro->prox);
        printf("%d ", ponteiro->valor);
    }else{
        printf("ponteiro != NULL!\n");
	}*/
}

