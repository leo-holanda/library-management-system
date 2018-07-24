#include <stdio.h> 
#include <stdlib.h>
#include "functions.h"

typedef struct book
{
	int id;
	char author_name[50];
	char book_name[50];
	char publisher[25];
} book;

char getAnswer(int select)
{
	if (select == 0)
	{
		printf("Livro adicionado com sucesso! Deseja adicionar outro? ");
	}
	else if(select == 1)
	{
		printf("Livro removido com sucesso! Deseja remover outro? ");
	}
	else if (select == 2)
	{
		printf("Deseja checar outro? ");		
	}
	printf("\n");

	char answer;
	scanf("%c", &answer);
	getchar();

	return answer;
}

void addBook()
{
	system("clear");

	book new_book;
	printf("Digite o nome do livro: ");
	fgets(new_book.book_name,50,stdin);
	printf("Digite o nome do autor: ");
	fgets(new_book.author_name,50,stdin);
	printf("Digite o nome da editora: ");
	fgets(new_book.publisher,25,stdin);

	FILE *f = fopen("books//data.txt","a+");
	fprintf(f,"Titulo: %s",new_book.book_name);
	fprintf(f,"Autor: %s",new_book.author_name);
	fprintf(f,"Editora: %s\n",new_book.publisher);
	fclose(f);

	if (getAnswer(0) == 'S')
	{
		addBook();
	}
	else
	{
		showMenu();
	}
}

void removeBook()
{
	system("clear");

	printf("Digite o ID\n");
		
	if (getAnswer(1) == 'S')
	{
		removeBook();
	}
	else
	{
		showMenu();
	}
}

void checkBook()
{
	FILE *f = fopen("books//data.txt","r");

	system("clear");

	if (getAnswer(2) == 'S')
	{
		checkBook();
	}
	else
	{
		showMenu();
	}
}

void showMenu()
{ 
	system("clear");
		
	int command;

	printf("Sistema de Livraria\n");
	printf("1 - Adicionar Livro\n");
	printf("2 - Remover Livro\n");
	printf("3 - Checar Livro\n");
	printf("4 - Sair\n\n");
	printf("O que deseja? ");
	
	scanf("%d", &command);
	getchar();

	switch(command)
	{
		case 1:
		addBook();
		break;

		case 2:
		removeBook();
		break;

		case 3:
		checkBook();
		break;

		case 4:
		system("clear");
		return;

		default :
		printf("Comando invalido, digite novamente.\n");
	}
}