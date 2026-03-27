#include <stdio.h>


int main() {
    int idade, peso;
    char nome[6];
    
    printf("Digite o seu nome: ");
    scanf("%s", &nome);
    printf("Digite a sua idade: ");
    scanf("%d", &idade);
    printf("Digite o seu peso: ");
    scanf("%d", &peso);



    printf("Nome: %s endereco= %p",nome, &nome);
    printf("Idade: %d endereco= %p",idade, &idade);
    printf("Nome: %d endereco= %p",peso, &peso);
    
    return 0;
}

