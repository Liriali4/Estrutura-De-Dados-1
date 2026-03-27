#include <stdio.h>

int parOuImpar(n) {
	if(n % 2 == 0){
		return 1;
	}else{
		return 0;
	}
    int num;

    return 0;
}


int main() {
    int num;
	printf("Numero: ");
    scanf("%d", &num);
    
   if(parOuImpar(num)){
   	
	printf("O %d e par", num);
   }else{
	printf("O %d e impar", num);
   }

    return 0;
}

