typedef struct no LCS;


typedef struct no {
    int valor;         
    struct no* proximo; 
} LCS;



LCS* inicializarLista();               
LCS* criarNo(int valor);             
void inserirNo(LCS** cabeca, int valor, int posicao); 
void removerNo(LCS** cabeca, int valor);  
void imprimirLista(LCS* cabeca);    
int procurarElemento(LCS* cabeca, int valor); 
void removerDuplicados(LCS** cabeca);  
void eliminarLista(LCS** cabeca);      



#define LISTA_DUPLAMENTE_LIGADA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista duplamente ligada
typedef struct NoDuplo {
    int valor;
    struct NoDuplo* anterior;
    struct NoDuplo* proximo;
} NoDuplo;

// Estrutura da lista duplamente ligada
typedef struct {
    NoDuplo* cabeca;
} ListaDuplamenteLigada;

// Prototipos das funções
void inicializarListaDupla(ListaDuplamenteLigada* lista);
NoDuplo* criarNoDuplo(int dado);
void inserirNaPosicaoDupla(ListaDuplamenteLigada* lista, int dado, int posicao);
void removerNoPorValor(ListaDuplamenteLigada* lista, int valor);
void imprimirLista(ListaDuplamenteLigada* lista);
int procurarElemento(ListaDuplamenteLigada* lista, int dado);
void eliminarLista(ListaDuplamenteLigada* lista);
void inverterLista(ListaDuplamenteLigada* lista);

#endif // LISTA_DUPLAMENTE_LIGADA_H


