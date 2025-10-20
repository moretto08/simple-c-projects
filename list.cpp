#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#include <locale.h>

using namespace std;

struct lista{
	string nome;
	string cpf;
};

void printList(lista *pointer, int *size){
	int i;

	for(i=0;i<*size;i++)
		cout<<i+1<<"- "<<pointer[i].nome<<" | CPF: "<<pointer[i].cpf<<"\n";
}

void addBegin(lista *&pointer, string nome, string cpf, int *size);
void addFinal(lista *&pointer, string nome, string cpf, int *size);
void addN(lista *&pointer, string nome, string cpf, int *size, int pos);
void removeFirst(lista *&pointer, int *size);
void removeLast(lista *&pointer, int *size);
void removeN(lista *&pointer, int *size,int pos);
string search(lista *pointer, int *size, string cpg);

int main(int argc, char const *argv[])
{	setlocale(LC_ALL, "");
	
	lista *pointer;

	int size=0;
	int desiredOpt=1;
	
	while(desiredOpt<9&&desiredOpt>0){
		cout<<"Operações: \n";
		cout<<"1- Inserção de um node no início da lista\n";
		cout<<"2- Inserção de um node no fim da lista\n";
		cout<<"3- Inserção de um node na posição N\n";
		cout<<"4- Retirar um node do início da lista\n";
		cout<<"5- Retirar um node do fim da lista\n";
		cout<<"6- Retirar um node na posição N\n";
		cout<<"7- Procurar um node pelo CPF\n";
		cout<<"8- Imprimir a Lista\n";
		cout<<"9- Sair\n";
		cout<<"\nEscolha a opção desejada:\n";
		cin>>desiredOpt;
		system("clear");

		string nome;
		string cpf;
		int pos;

		switch(desiredOpt){
			case 1:
				cout<<"Função selecionada: 1- Inserção de um node no início da lista\n";
				cout<<"Digite o nome:\n";
				cin>>nome;
				fflush(stdin);
				cout<<"Digite o CPF:\n";
				cin>>cpf;
				fflush(stdin);

				addBegin(pointer, nome, cpf, &size);
				break;
			case 2:
				cout<<"Função selecionada: 2- Inserção de um node no fim da lista\n";
				cout<<"Digite o nome:\n";
				cin>>nome;
				fflush(stdin);
				cout<<"Digite o CPF:\n";
				cin>>cpf;
				fflush(stdin);
				if(size==0){
					addBegin(pointer,nome,cpf, &size);
				}else{
					addFinal(pointer,nome,cpf,&size);
				}

				break;
			case 3:
				cout<<"Função selecionada: 3- Inserção de um node na posição N\n";
				cout<<"Digite a posição desejada:\n";
				cin>>pos;
				fflush(stdin);
				cout<<"Digite o nome:\n";
				cin>>nome;
				fflush(stdin);
				cout<<"Digite o CPF:\n";
				cin>>cpf;
				fflush(stdin);

				if(pos==0){
					addBegin(pointer,nome,cpf, &size);
				}else if(pos==size){
					addFinal(pointer,nome,cpf,&size);
				}else{
					addN(pointer,nome,cpf,&size,pos);
				}
				break;
			case 4:
				cout<<"Função selecionada: 4- Retirar um node do início da lista\n";
				if(size==0){
					cout<<"Lista Vazia!\n";
				}else{
					removeFirst(pointer,&size);
				}
				break;
			case 5:
				cout<<"Função selecionada: 5- Retirar um node do fim da lista\n";
				if(size==0){
					cout<<"Lista Vazia!\n";
				}else{
					removeLast(pointer,&size);
				}
				break;
			case 6:
				cout<<"Função selecionada: 6- Retirar um node na posição N\n";
				cout<<"Digite a posição da lista que deseja remover:\n";
				cin>>pos;
				if(size==0){
					cout<<"Lista Vazia!\n";
				}else{
					removeN(pointer,&size,pos);
				}
				break;
			case 7:
				cout<<"Função selecionada: 7- Procurar um node pelo CPF\n";
				if(size==0){
					cout<<"\nLista vazia!\n";
				}else{
					cout<<"Digite o CPF desejado:\n";
					cin>>cpf;
					fflush(stdin);
					cout<<"\nO seguinte nome está cadastrado no CPF informado:"<<search(pointer, &size, cpf)<<"\n\n";
				}
				break;
			case 8:
				printList(pointer, &size);
				break;
		}
	}

	
	return 0;
}

void addBegin(lista *&pointer, string nome, string cpf, int *size){
	if(*size==0){
		lista *newList=new lista[1];
		newList[0].nome=nome;
		newList[0].cpf=cpf;
		pointer=newList;

	}else{

		lista *newList = new lista[*size+1];
		newList[0].nome=nome;
		newList[0].cpf=cpf;

		int i;
		for(i=0;i<*size;i++){
			newList[i+1].nome=pointer[i].nome;
			newList[i+1].cpf=pointer[i].cpf;
		}
		pointer=newList;
	}	
	*size=*size+1;
}

void addFinal(lista *&pointer, string nome, string cpf, int *size){

	lista *newList=new lista[*size+1];
	int i;
	for(i=0;i<*size;i++){
		newList[i].nome=pointer[i].nome;
		newList[i].cpf=pointer[i].cpf;
	}
	newList[*size].nome=nome;
	newList[*size].cpf=cpf;

	pointer=newList;
	*size=*size+1;
}

void addN(lista *&pointer, string nome, string cpf, int *size, int pos){
	lista *newList = new lista[*size+1];
	int i;
	for(i=0;i<pos-1;i++){
		newList[i].nome=pointer[i].nome;
		newList[i].cpf=pointer[i].cpf;
	}
	newList[pos-1].nome=nome;
	newList[pos-1].cpf=cpf;
	for(i=pos;i<*size+1;i++){
		newList[i].nome=pointer[i-1].nome;
		newList[i].cpf=pointer[i-1].cpf;
	}
	pointer=newList;
	*size=*size+1;
}

void removeFirst(lista *&pointer, int *size){
	lista *newList = new lista[*size-1];
	int i;
	for(i=1;i<*size;i++){
		newList[i-1].nome=pointer[i].nome;
		newList[i-1].cpf=pointer[i].cpf;
	}
	pointer=newList;
	*size=*size-1;
}

void removeLast(lista *&pointer, int *size){
	lista *newList=new lista[*size-1];
	int i;
	for(i=0;i<*size-1;i++){
		newList[i].nome=pointer[i].nome;
		newList[i].cpf=pointer[i].cpf;
	}
	pointer=newList;
	*size=*size-1;
}

void removeN(lista *&pointer, int *size, int pos){
	lista *newList=new lista[*size-1];
	int i;
	pos=pos-1;
	for(i=0;i<*size-1;i++){
		if(i<pos){
			newList[i].nome=pointer[i].nome;
			newList[i].cpf=pointer[i].cpf;
		}else{
			newList[i].nome=pointer[i+1].nome;
			newList[i].cpf=pointer[i+1].cpf;
		}
	}
	pointer=newList;
	*size=*size-1;
}

string search(lista *pointer, int *size, string cpf){
	int i;
	string nome="\nNão encontrado!\n";
	for(i=0;i<*size;i++){
		if(pointer[i].cpf==cpf){
			nome=pointer[i].nome;
		}
	}
	return nome;
}