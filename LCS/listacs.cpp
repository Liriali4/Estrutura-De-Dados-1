#include <stdio.h>
#include <stdlib.h>
#include "listacs.h"


//#####################################################################
//					Exercício nº  Listas circulares simples
//#####################################################################



// Inicializar a lista
LCS* inicializarLista() {
    return NULL;
}

// Criar um novo nó
LCS* criarNo(int valor) {
    LCS* novoNo = (LCS*)malloc(sizeof(LCS));
    if (!novoNo) {
        printf("Erro ao alocar memï¿½ria.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

// Inserir nó em uma posição específica
void inserirNo(LCS* ponteiro, int valor, int posicao) {
    LCS novoNo = criarNo(valor);
    if (*ponteiro == NULL) {
        *ponteiro = novoNo;
        novoNo->proximo = novoNo; // Lista circular
        return;
    }
    
    LCS atual = *ponteiro;
    if (posicao == 0) {
        // Inserir no ínicio
        while (atual->proximo != *ponteiro) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
        novoNo->proximo = *ponteiro;
        *ponteiro = novoNo;
    } else {
        // Inserir em outra posição
        for (int i = 0; i < posicao - 1 && atual->proximo != *ponteiro; i++) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

// Remover nó
void removerNo(LCS* ponteiro, int valor) {
    if (*ponteiro == NULL) return;

    LCS atual = *ponteiro;
    LCS anterior = NULL;

    do {
        if (atual->valor == valor) {
            if (anterior == NULL) { // Remover o primeiro nó
                LCS temp = *ponteiro;
                while (atual->proximo != *ponteiro) {
                    atual = atual->proximo;
                }
                if (*ponteiro == (*ponteiro)->proximo) { // Apenas um nó
                    *ponteiro = NULL;
                } else {
                    atual->proximo = (*ponteiro)->proximo;
                    *ponteiro = (*ponteiro)->proximo;
                }
                free(temp);
            } else {
                anterior->proximo = atual->proximo;
                free(atual);
            }
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != *ponteiro);
}

// Imprimir lista
void imprimirLista(LCS ponteiro) {
    if (ponteiro == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    LCS atual = ponteiro;
    do {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    } while (atual != ponteiro);
    printf("(circular)\n");
}

// Procurar elemento
int procurarElemento(LCS ponteiro, int valor) {
    if (ponteiro == NULL) return 0;

    LCS atual = ponteiro;
    do {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    } while (atual != ponteiro);
    return 0;
}

// Remover valores repetidos
void removerDuplicados(LCS* ponteiro) {
    if (*ponteiro == NULL) return;

    LCS atual = *ponteiro;
    do {
        LCS comparador = atual;
        while (comparador->proximo != *ponteiro) {
            if (comparador->proximo->valor == atual->valor) {
                LCS temp = comparador->proximo;
                comparador->proximo = comparador->proximo->proximo;
                free(temp);
            } else {
                comparador = comparador->proximo;
            }
        }
        atual = atual->proximo;
    } while (atual->proximo != *ponteiro);
}

// Eliminar a lista
void eliminarLista(LCS* ponteiro) {
    if (*ponteiro == NULL) return;

    LCS atual = *ponteiro;
    LCS temp;

    while (atual->proximo != *ponteiro) {
        temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(atual);
    *ponteiro = NULL;
}



//#####################################################################
//					Exercício nº 2 Listas duplamente ligadas
//#####################################################################


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

// Inicializando a lista duplamente ligada
void inicializarListaDupla(ListaDuplamenteLigada* lista) {
    lista->cabeca = NULL;
}

// Criação e inicialização de um novo nó
NoDuplo* criarNoDuplo(int dado) {
    NoDuplo* novoNo = (NoDuplo*)malloc(sizeof(NoDuplo));
    novoNo->valor = dado;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}


// Inserção em uma posição específica na lista duplamente ligada
void inserirNaPosicaoDupla(ListaDuplamenteLigada* lista, int dado, int posicao) {
    if (posicao < 0) {
        printf("Posicao invalida! Deve ser maior ou igual a zero.\n");
        return;
    }

    NoDuplo* novoNo = criarNoDuplo(dado);

    if (posicao == 0) {
        novoNo->proximo = lista->cabeca;
        if (lista->cabeca != NULL) {
            lista->cabeca->anterior = novoNo;
        }
        lista->cabeca = novoNo;
        printf("Valor %d inserido com sucesso na posicao %d!\n", dado, posicao);
        return;
    }

    NoDuplo* temp = lista->cabeca;
    for (int i = 0; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Posicao invalida!\n");
        free(novoNo);
        return;
    }

    novoNo->proximo = temp->proximo;
    if (temp->proximo != NULL) {
        temp->proximo->anterior = novoNo;
    }
    temp->proximo = novoNo;
    novoNo->anterior = temp;
    
    printf("Valor %d inserido com sucesso na posicao %d!\n", dado, posicao);
}

case 1:
                	int valor, posicao;
                	printf("Digite o valor a inserir: ");
                	scanf("%d", &valor);
                	printf("Digite a posicao onde inserir (0 para inicio): ");
                	scanf("%d", &posicao);
                	inserirNaPosicaoDupla(&listaDupla, valor, posicao);
break;



// Função para remover um nó com um dado valor
void removerNoPorValor(ListaDuplamenteLigada* lista, int valor) {
    if (lista->cabeca == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    NoDuplo* temp = lista->cabeca;
    while (temp != NULL) {
        if (temp->valor == valor) {
            // Remover o nó
            if (temp == lista->cabeca) {
                lista->cabeca = temp->proximo;
                if (lista->cabeca != NULL) {
                    lista->cabeca->anterior = NULL;
                }
            } else {
                temp->anterior->proximo = temp->proximo;
                if (temp->proximo != NULL) {
                    temp->proximo->anterior = temp->anterior;
                }
            }
            free(temp);
            printf("Valor %d removido com sucesso!\n", valor);
            return; // Encontrou e removeu, pode sair do loop
        }
        temp = temp->proximo;
    }
    printf("Valor %d nao encontrado na lista.\n", valor);
} 

case 2:
            		printf("Digite o valor do no a remover: ");
            		scanf("%d", &valor);
            		removerNoPorValor(&listaDupla, valor);
break;


// Função para imprimir os elementos da lista duplamente ligada
void imprimirLista(ListaDuplamenteLigada* lista) {
    NoDuplo* temp = lista->cabeca;
    printf("Elementos da lista: ");
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}

// Função para procurar um elemento na lista duplamete ligada
int procurarElemento(ListaDuplamenteLigada* lista, int dado) {
    NoDuplo* temp = lista->cabeca;
    int posicao = 0;
    while (temp != NULL) {
        if (temp->valor == dado) {
            return posicao;
        }
        temp = temp->proximo;
        posicao++;
    }
    return -1;
}

// Função para eliminar a lista duplamente ligada
void eliminarLista(ListaDuplamenteLigada* lista) {
    NoDuplo* temp = lista->cabeca;
    while (temp != NULL) {
        NoDuplo* proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    lista->cabeca = NULL;
    printf("Lista eliminada com sucesso.\n");
}

// Função para inverter a lista duplamente ligada
void inverterLista(ListaDuplamenteLigada* lista) {
    if (lista->cabeca == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    NoDuplo* atual = lista->cabeca;
    NoDuplo* temp = NULL;

    // Troca os ponteiros anterior e próximo para cada nó
    while (atual != NULL) {
        temp = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = temp;
        atual = atual->anterior;
    }

    // Atualiza a cabeça da lista
    if (temp != NULL) {
        lista->cabeca = temp->anterior;
    }

    printf("Lista invertida com sucesso.\n");
}


//#####################################################################
// 							Função principal para testar
//#####################################################################

int main() {
    //#########################################################################
    //Teste do 1º exercício
    //#########################################################################
    
	
	LCS lista = inicializarLista();

    // Testes
    inserirNo(&lista, 10, 0);
    inserirNo(&lista, 20, 1);
    inserirNo(&lista, 30, 2);
    inserirNo(&lista, 20, 1); // Inserir valor repetido

    printf("Lista inicial:\n");
    imprimirLista(lista);

    printf("\nRemovendo duplicados:\n");
    removerDuplicados(&lista);
    imprimirLista(lista);

    printf("\nProcurando elemento 30: %s\n", procurarElemento(lista, 30) ? "Encontrado" : "Não encontrado");

    printf("\nRemovendo elemento 30:\n");
    removerNo(&lista, 30);
    imprimirLista(lista);

    printf("\nEliminando a lista:\n");
    eliminarLista(&lista);
    imprimirLista(lista);
    
    //#########################################################################
    //Teste do 2º exercício
    //#########################################################################
    
    int tipoLista, opcao, valor, posicao;

    printf("Escolha o tipo de lista:\n");
    printf("1. Lista Circular\n");
    printf("2. Lista Duplamente Ligada\n");
    printf("Escolha: ");
    scanf("%d", &tipoLista);

    if (tipoLista == 1) {
        NoCircular *listaCircular = inicializarListaCircular();

        do {
        printf("\nMENU - Lista Circular:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Imprimir lista\n");
        printf("4. Procurar elemento\n");
        printf("5. Remover repetidos\n");
        printf("6. Eliminar lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                	printf("Digite o valor a ser inserido: ");
                	scanf("%d", &valor);
                	printf("Digite a posicao para inserir (0 para inicio): ");
                	scanf("%d", &posicao);
                	listaCircular = inserirNoCircular(listaCircular, valor, posicao);
                	printf("Elemento inserido com sucesso.\n");
                break;
                case 2:
                	printf("Digite o valor a ser removido: ");
                	scanf("%d", &valor);
                	listaCircular = removerNoCircular(listaCircular, valor);
                	printf("Elemento removido.\n");
                    break;
                case 3:
                    printf("Lista atual: ");
                	imprimirListaCircular(listaCircular);
                    break;
                case 4:
                	printf("Digite o valor a procurar: ");
                	scanf("%d", &valor);
                	printf("Elemento %s.\n", procurarElementoCircular(listaCircular, valor) ? "encontrado" : "nao encontrado");
                break;
                case 5:
                	listaCircular = removerRepetidosCircular(listaCircular);
                	printf("Repetidos removidos.\n");
                break;
            	case 6:
                	eliminarListaCircular(listaCircular);
                	listaCircular = NULL;
                	printf("Lista eliminada.\n");
                break;
                case 0:
                    printf("Saindo...\n");
                	eliminarListaCircular(listaCircular);
                    break;
                default:
                    printf("Opcao invalida.\n");
            }
        } while (opcao != 0);

    } else if (tipoLista == 2) {
        ListaDuplamenteLigada listaDupla;
        inicializarListaDupla(&listaDupla);

        do {
            printf("\nMenu - Lista Duplamente Ligada:\n");
        	printf("1. Inserir no\n");
        	printf("2. Remover no\n");
        	printf("3. Imprimir lista\n");
        	printf("4. Procurar elemento\n");
        	printf("5. Inverter lista\n");
        	printf("6. Eliminar lista\n");
        	printf("0. Sair\n");
        	printf("Escolha uma opcao: ");
        	scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                	int valor, posicao;
                	printf("Digite o valor a inserir: ");
                	scanf("%d", &valor);
                	printf("Digite a posicao onde inserir (0 para inicio): ");
                	scanf("%d", &posicao);
                	inserirNaPosicaoDupla(&listaDupla, valor, posicao);
                    break;
                case 2:
                	printf("Digite a posicao do no a remover: ");
                	scanf("%d", &posicao);
                	removerNoDuplo(&listaDupla, posicao);
                    break;
                case 3:
                    imprimirLista(&listaDupla);
                    break;
                case 4: {
                int valor;
                	printf("Digite o valor a procurar: ");
                	scanf("%d", &valor);
                	int posicaoEncontrada = procurarElemento(&listaDupla, valor);
                	if (posicaoEncontrada != -1) {
                    printf("Elemento encontrado na posicao: %d\n", posicaoEncontrada);
                	} else {
                    printf("Elemento nao encontrado.\n");
                	}
                break;
            }
            	case 5:
                	inverterLista(&listaDupla);
                break;
            	case 6:
                	eliminarLista(&listaDupla);
                break;
                case 0:
                   printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida! Tente novamente.\n");
            }
        } while (opcao != 0);
    } else {
        printf("Tipo de lista invalido.\n");
    }

    return 0;
    
    

    return 0;
}

