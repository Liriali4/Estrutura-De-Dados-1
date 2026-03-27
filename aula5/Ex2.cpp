#include <stdio.h>

void contarCarateres(char * p){
	char * str = p;
	int c = 0;
	for(*str != '\0'){
		pt++;
		c++;
	}
	return c;
}

int main() {
    char nome[20];
    
    printf("Digite o seu nome: ");
    scanf("%s", &nome);
    
   
    printf("%d", contarCarateres(nome)); 
    
    return 0;
}
s
