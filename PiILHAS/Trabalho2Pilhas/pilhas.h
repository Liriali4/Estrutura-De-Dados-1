#ifndef PILHA_H
#define PILHA_H

// Estruturas
typedef struct No {
    int dado;
    int min; 
    int max; 
    struct No* proximo;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

// Funções do TAD Pilha
void inicializarPilha(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
void popN(Pilha* pilha, int n);
void imprimirPilha(Pilha* pilha);
void substituirElemento(Pilha* pilha, int antigo, int novo);
int minimo(Pilha* pilha);
int maximo(Pilha* pilha);
void eliminarPilha(Pilha* pilha);

#endif
