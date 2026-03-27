typedef struct no Lista;

typedef struct no {
    int valor;
    struct no *prox;
} Lista;

Lista *inicializarLista();
Lista *inserirNo(Lista *ponteiro, int valor);
void imprimirListaInversa(Lista *ponteiro);

