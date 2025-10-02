#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>

// Code for printing table os numbers

int main(){
	setlocale(LC_ALL,"Portuguese");

	int i, num, rsult;
	char rpt;

	start:
	printf("-------------- Gerador de Tabuadas --------------\n\n"); //table generator
	printf("Digite o número para o qual deseja consultar a tabuada:"); //insert number you'd like to see table
	scanf("%d", &num);
	fflush(stdin);

		for (i=0; i <= 10; i++){
			printf("%d x %d = %d\n", num, i, i * num);
		}

	printf("\n\nGostaria de imprimir outra tabuada? (s/n)\n"); //Would you like to get another table?
	scanf(" %c", &rpt);
	fflush(stdin);

		if (rpt == 's'){
			system("clear");
			goto start;
		}

	sleep(1);
	return 0;
}