#include <stdio.h>
#include <locale.h>

//Como criar uma calculadora decente

int main(){
	setlocale(LC_ALL,"Portuguese");

	int num1, num2, soma, subtr, divis, mult;
	char opr, rpt;

	printf("\n----- Esta é uma calculadora minimamente decente para operações básicas -----\n\n");
	start:
	printf("Digite a expressão que deseja calcular:\n");
	scanf("%d%c%d", &num1, &opr, &num2);

	soma = num1 + num2;
	subtr = num1 - num2;
	divis = num1 / num2;
	mult = num1 * num2;


	if (opr == '+'){
		printf("Você digitou uma adição.\n");
		printf("O resultado é %d+%d=%d", num1, num2, soma);
	} else if (opr == '-') {
		printf("Você digitou uma subtração.\n");
		printf("O resultado é %d-%d=%d", num1, num2, subtr);
	} else if (opr == '*' || opr == '.') {
		printf("Você digitou uma multiplicação.\n");
		printf("O resultado é %d*%d=%d", num1, num2, mult);
	} else if (opr == '/' || opr == ':') {
		printf("Você digitou uma divisão.\n");
		printf("O resultado é %d/%d=%d", num1, num2, divis);
	}

	printf("\n\n");
	printf("Deseja realizar outra operação? (s/n)\n");
	scanf(" %c", &rpt);
	fflush(stdin);

	if (rpt == 's') {
		goto start;
	}

	return 0;
}