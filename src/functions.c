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
		printf("Deseja consultar outro? ");		
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
	fprintf(f,"%s",new_book.book_name);
	fprintf(f,"%s",new_book.author_name);
	fprintf(f,"%s\n",new_book.publisher);
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

void showAllBooks()
{
	system("clear");

	int count = 0;
	char line[50];
	FILE *f = fopen("books//data.txt","r");

	while(fgets(line,50,f) != NULL)
	{
		if (count == 0)
		{
			printf("Título: %s", line);
		}
		else if (count == 1)
		{
			printf("Autor(a): %s", line);
		}
		else if (count == 2)
		{
			printf("Editora: %s", line);
		}
		else if (count == 3)
		{
			count = -1;
			printf("%s", line);
		}
		count++;
	}

	if (getAnswer(2) == 'S')
	{
		showAllBooks();
	}
	else
	{
		showMenu();
	}
}

void checkTitle()
{

}

void checkAuthor()
{

}

void checkPublisher()
{

}

void showMenu()
{ 
	system("clear");
		
	int command;

	printf("Sistema de Livraria\n\n");
	printf("1 - Adicionar Livro\n");
	printf("2 - Checar Livro\n");
	printf("3 - Sair\n\n");
	printf("O que deseja? ");
	
	scanf("%d", &command);
	getchar();

	switch(command)
	{
		case 1:
		addBook();
		break;

		case 2:
		showCheckMenu();
		break;

		case 3:
		system("clear");
		return;
	}
}

void showCheckMenu()
{
	printf("Deseja consultar por...\n");
	printf("1 - Título\n");
	printf("2 - Autor\n");
	printf("3 - Editora\n");
	printf("4 - Todos os livros\n");

	int command;
	scanf("%d", &command);
	getchar();

	switch(command)
	{
		case 1:
		checkTitle();
		break;

		case 2:
		checkAuthor();
		break;

		case 3:
		checkPublisher();
		break;

		case 4:
		showAllBooks();
		break;
	}
}













