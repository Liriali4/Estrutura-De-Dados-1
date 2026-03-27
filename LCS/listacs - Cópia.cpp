#include <stdio.h>
#include <stdlib.h>

// Defini��o do n�
typedef struct no {
	int valor;
    struct no* proximo;
} LCS;

// Inicializar a lista (retorna o ponteiro para o n� cabe�a)
LCS* initializeList() {
    return NULL;
}

// Criar um novo n�
LCS* createNode(int data) {
    LCS* newNode = (LCS*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erro ao alocar mem�ria.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Inserir n� em uma posi��o espec�fica
void insertNode(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Circular
        return;
    }
    
    Node* current = *head;
    if (position == 0) {
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
        *head = newNode;
    } else {
        for (int i = 0; i < position - 1 && current->next != *head; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Remover n�
void removeNode(Node** head, int data) {
    if (*head == NULL) return;

    Node* current = *head;
    Node* previous = NULL;

    do {
        if (current->data == data) {
            if (previous == NULL) { // Remo��o do primeiro n�
                Node* temp = *head;
                while (current->next != *head) {
                    current = current->next;
                }
                if (*head == (*head)->next) { // Lista com um �nico n�
                    *head = NULL;
                } else {
                    current->next = (*head)->next;
                    *head = (*head)->next;
                }
                free(temp);
            } else {
                previous->next = current->next;
                free(current);
            }
            return;
        }
        previous = current;
        current = current->next;
    } while (current != *head);
}

// Imprimir lista
void printList(Node* head) {
    if (head == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(circular)\n");
}

// Procurar elemento
int searchElement(Node* head, int data) {
    if (head == NULL) return 0;

    Node* current = head;
    do {
        if (current->data == data) return 1;
        current = current->next;
    } while (current != head);
    return 0;
}

// Remover valores repetidos
void removeDuplicates(Node** head) {
    if (*head == NULL) return;

    Node* current = *head;
    do {
        Node* runner = current;
        while (runner->next != *head) {
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    } while (current->next != *head);
}

// Eliminar a lista
void deleteList(Node** head) {
    if (*head == NULL) return;

    Node* current = *head;
    Node* temp;

    while (current->next != *head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    free(current);
    *head = NULL;
}

// Fun��o principal para testar
int main() {
    Node* list = initializeList();

    // Testes
    insertNode(&list, 10, 0);
    insertNode(&list, 20, 1);
    insertNode(&list, 30, 2);
    insertNode(&list, 20, 1); // Inserir valor repetido

    printf("Lista inicial:\n");
    printList(list);

    printf("\nRemovendo duplicatas:\n");
    removeDuplicates(&list);
    printList(list);

    printf("\nProcurando elemento 30: %s\n", searchElement(list, 30) ? "Encontrado" : "N�o encontrado");

    printf("\nRemovendo elemento 30:\n");
    removeNode(&list, 30);
    printList(list);

    printf("\nEliminando a lista:\n");
    deleteList(&list);
    printList(list);

    return 0;
}

