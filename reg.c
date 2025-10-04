#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/*Code for customers registrations. Saves the customer's infos at 
'clients.txt' in prog's dir*/

int criar_arquivo(const char *nome);

struct clientes {
	char nome[50];
	char cpf[12];
	char cep[9];
	char dnasc[10];
};

int main(int argc, char const *argv[]){
	setlocale(LC_ALL,"Portuguese");
	start:
	struct clientes c1;

	printf("Iniciando cadastro de cliente...\n");
	printf("Nome:\t");
	fflush(stdin);
	scanf(" %50[^\n]s", c1.nome);
	fflush(stdin);

	printf("CPF (apenas números):\t");
	scanf(" %12[^\n]s", c1.cpf);
	fflush(stdin);

	printf("Data de nascimento:\t");
	scanf("%s", c1.dnasc);
	fflush(stdin);

	printf("CEP (apenas números):\t");
	scanf("%s", c1.cep);
	fflush(stdin);

	int r = criar_arquivo("clients.txt");

    if (r == 1) printf("\n\nArquivo criado!\n");
    else if (r == 0) printf("\n\nArquivo já existe.\n");
    else printf("\n\nErro ao criar arquivo.\n");

	FILE *arquivo = fopen("clients.txt", "a");
	fprintf(arquivo, "\n\nNome: %s | CPF: %s | Data de Nascimento: %s | CEP: %s\n", c1.nome, c1.cpf, c1.dnasc, c1.cep);

	printf("\n\nDados salvos em 'clients.txt'!\n");

	char rpt;
	printf("\nDeseja cadastrar outro cliente? (s/n)\n");
	scanf(" %c", &rpt);
	if (rpt == 's')
		goto start;

	return 0;
}

int criar_arquivo(const char *nome) {
    FILE *f = fopen(nome, "r");
    if (f != NULL) {
        fclose(f);
        return 0;
    }
	f = fopen(nome, "w");
    if (f == NULL) return -1;

    fclose(f);
    return 1;
}