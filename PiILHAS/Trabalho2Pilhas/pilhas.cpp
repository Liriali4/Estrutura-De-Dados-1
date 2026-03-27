#include <stdio.h>
#include <stdlib.h>

// Definição do nó da pilha
typedef struct No {
    int dado;
    int min; 
    int max; 
    struct No* proximo;
} No;

// Estrutura da pilha
typedef struct Pilha {
    No* topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

// Função para empilhar (push)
void push(Pilha* pilha, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Memoria insuficiente para alocar o no.\n");
        exit(1);
    }
    novoNo->dado = valor;

    // Atualizar min e max
    if (pilhaVazia(pilha)) {
        novoNo->min = valor;
        novoNo->max = valor;
    } else {
        novoNo->min = valor < pilha->topo->min ? valor : pilha->topo->min;
        novoNo->max = valor > pilha->topo->max ? valor : pilha->topo->max;
    }

    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    printf("Elemento %d inserido na pilha.\n", valor);
}

// Função para desempilhar (pop)
int pop(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Nao e possivel remover elementos.\n");
        exit(1);
    }
    No* aux = pilha->topo;
    int valorRemovido = aux->dado;
    pilha->topo = aux->proximo;
    free(aux);
    printf("Elemento %d removido da pilha.\n", valorRemovido);
    return valorRemovido;
}

// Função para remover n elementos do topo da pilha
void popN(Pilha* pilha, int n) {
    printf("\nRemovendo %d elementos do topo da pilha:\n", n);
    for (int i = 0; i < n; i++) {
        if (!pilhaVazia(pilha)) {
            pop(pilha);
        } else {
            printf("Pilha ja esta vazia. Não ha mais elementos para remover.\n");
            break;
        }
    }
}

// Função para imprimir os elementos da pilha sem destruí-la
void imprimirPilha(Pilha* pilha) {
    printf("\nElementos da pilha:\n");
    No* atual = pilha->topo;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função para substituir um elemento na pilha
void substituirElemento(Pilha* pilha, int antigo, int novo) {
    printf("\nSubstituindo elemento %d por %d na pilha:\n", antigo, novo);
    No* atual = pilha->topo;
    int encontrado = 0;
    while (atual != NULL) {
        if (atual->dado == antigo) {
            atual->dado = novo;
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    }
    if (encontrado) {
        printf("Elemento %d substituido com sucesso por %d.\n", antigo, novo);
    } else {
        printf("Elemento %d nao encontrado na pilha.\n", antigo);
    }
}

// Função para retornar o valor mínimo da pilha
int minimo(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Nao ha elemento minimo.\n");
        exit(1);
    }
    return pilha->topo->min;
}

// Função para retornar o valor máximo da pilha
int maximo(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia. Nao ha elemento maximo.\n");
        exit(1);
    }
    return pilha->topo->max;
}

// Função para eliminar a pilha
void eliminarPilha(Pilha* pilha) {
    printf("\nEliminando a pilha:\n");
    while (!pilhaVazia(pilha)) {
        pop(pilha);
    }
    printf("Pilha eliminada com sucesso.\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    // Teste das operações
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 5);
    push(&pilha, 40);

    // Impressão da pilha
    imprimirPilha(&pilha);

    // Obter valores mínimo e máximo
    printf("Valor minimo da pilha: %d\n", minimo(&pilha));
    printf("Valor maximo da pilha: %d\n", maximo(&pilha));

    // Remover n elementos
    popN(&pilha, 2);

    // Impressão após remoção
    imprimirPilha(&pilha);

    // Obter valores mínimo e máximo novamente
    printf("Valor minimo da pilha: %d\n", minimo(&pilha));
    printf("Valor maximo da pilha: %d\n", maximo(&pilha));

    // Eliminar a pilha
    eliminarPilha(&pilha);

    return 0;
}
