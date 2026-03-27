#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    float valor_vendido;
    float comissao;
} Intermediario;

int main() {
    Intermediario intermediarios[3];
    int i;
	float total = 0;

    printf("\n--- Formulario ---\n");

    for (i = 0; i < 3; i++) {
        printf("Digite o seu nome: ");
        fgets(intermediarios[i].nome, sizeof(intermediarios[i].nome), stdin);
        // Remover o caractere '\n' adicionado por fgets
        intermediarios[i].nome[strcspn(intermediarios[i].nome, "\n")] = '\0';

        printf("Informe o valor vendido: ");
        // Usar %f para ler float
        scanf("%f", &intermediarios[i].valor_vendido);

        // Limpar o buffer após o scanf
        while (getchar() != '\n');
        
        printf("\n");
    }

    printf("\n--- Lista de intermediarios ---\n");
    for (i = 0; i < 3; i++) {
    	
    	if(intermediarios[i].valor_vendido >=  150000 && intermediarios[i].valor_vendido <= 300000){
    		//9,5%    		
    		intermediarios[i].comissao = intermediarios[i].valor_vendido * 0.095;	
    		
		}else if(intermediarios[i].valor_vendido >  300000){
			//12%
			intermediarios[i].comissao = intermediarios[i].valor_vendido * 0.12;
		}else {
			//7%
			intermediarios[i].comissao = intermediarios[i].valor_vendido * 0.07;
		}
    	    	
        printf("Nome: %s\n", intermediarios[i].nome);
        printf("Valor vendido: %.2f\n", intermediarios[i].valor_vendido);
        printf("Valor da comissao: %.2f\n", intermediarios[i].comissao);
        printf("\n");
    }

    printf("\n--- Total de vendas da empresa ---\n");
    
    for(i=0; i<3; i++){
    	total= total + intermediarios[i].valor_vendido;
	}
	
    printf("Valor total de vendas da empresa: %.2f\n", total);
	
    return 0;
}

