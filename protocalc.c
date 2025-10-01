#include <stdio.h>
#include <unistd.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"Portuguese");

	start:
	int A, B, opr, soma, subtr, divis, mult;
	char rpt;
	char null[1];
	
	printf("\n\nCalculadora Simples\n\n");
	printf("Digite o primeiro valor:\n");
	scanf("%d", &A);
	fflush(stdin);
	
	printf("Digite a operação desejada:\n");
	printf("Utilize:\n 1=adição\n 2=subtração\n 3=multiplicação\n 4=divisão\n");
	scanf("%d", &opr);
	fflush(stdin);
	
	printf("Digite o segundo valor:\n");
	scanf("%d", &B);
	fflush(stdin);
	
	soma= A+B;
	subtr= A-B;
	mult= A*B;
	divis= A/B;
	
	switch ( opr )
	{
		case 1 :
		printf("O resultado de %d+%d é: %d\n", A, B, soma);
		break;
		
		case 2 :
		printf("O resultadode %d-%d é: %d\n", A, B, subtr);
		break;
		
		case 3 :
		printf("O resultado de %d*%d é: %d\n", A, B, mult);
		break;
		
		case 4 :
		printf("O resultado de %d:%d é: %d\n", A, B, divis);
		break;
		
		default :
		printf("Operação inválida.\n");
	}
	
	sleep(3);

	rpt='s';
	
	printf("Gostaria de realizar outra operação? (s/n)\n");
	scanf(" %c", &rpt);
	fflush(stdin);
	
	if(rpt=='s') {	
		goto start;
	}	
	
	return 0;	
}
