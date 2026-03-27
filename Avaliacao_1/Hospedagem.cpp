#include <stdio.h>

int main() {
    int tipoSite, meses, gbExtras;
    float valorMensal, valorExtras, valorTotal;

    printf("Escolha o tipo de site (1 para simples, 2 para complexo): ");
    scanf("%d", &tipoSite);

    printf("Digite a quantidade de meses que o site ficará hospedado: ");
    scanf("%d", &meses);

    printf("Digite a quantidade de gigabytes extras: ");
    scanf("%d", &gbExtras);

    switch (tipoSite) {
        case 1:  
            valorMensal = 25000; 

            
            if (gbExtras <= 5) {
                valorExtras = gbExtras * 2500;
            } else if (gbExtras > 5)  {
                valorExtras = gbExtras * 5000
            }
            break;

        case 2: 
            valorMensal = 65000; 


            if (gbExtras <= 10) {
                valorExtras = gbExtras * 8500;
            } else  if (gbExtras > 10) {
                valorExtras = gbExtras 12000
            }
            break;

        default:
            printf("Tipo de site inválido.\n");
            return 1;
    }

    valorTotal = (valorMensal * meses) + valorExtras;


    printf("O valor total a pagar é: %.2f Kz\n", valorTotal);

    return 0;
}

