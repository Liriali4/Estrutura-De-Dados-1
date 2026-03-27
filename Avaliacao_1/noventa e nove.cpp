#include <stdio.h>

int main() {
    int lido, guardado;
	 	 
	printf("Digite:");
    scanf("%d", &lido);
	guardado = lido
	 
	if(lido == 99){
		
	printf("%i", guardado);
	 	return 0
	}
	while (lido != 99){
	 	printf("Digite:");
    	scanf("%d", &lido);
    	    	
    	if (lido > guardado){
			guardado = lido;
		}
	}
	 
	printf("%i", guardado);

    return 0;
}

