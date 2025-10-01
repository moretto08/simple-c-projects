#include <stdio.h>

int nota;

int main(){
	printf("Digite a nota:\n");
	scanf("%d", &nota);
	fflush(stdin);

	/* if (nota >=70)
		printf("Aprovado");
	else
		printf("Reprovado"); */

	printf("%s", nota >=70 ? "Aprovado" : "Reprovado");

	// Lembrar que para estruturas if/else simples se pode usar qualquer uma 
	// das duas estruturas acima. 

	// Ainda, lembrar que as chaves só são obrigatórias em blocos de comandos,
	// não sendo em comando simples, como neste código.

	return 0;
}
