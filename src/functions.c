#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "functions.h"

typedef struct book
{
	int id;
	char author_name[50];
	char book_title[50];
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
	fgets(new_book.book_title,50,stdin);
	printf("Digite o nome do autor: ");
	fgets(new_book.author_name,50,stdin);
	printf("Digite o nome da editora: ");
	fgets(new_book.publisher,25,stdin);

	FILE *f = fopen("books//data.txt","a+");
	fprintf(f,"\n%s",new_book.book_title);
	fprintf(f,"%s",new_book.author_name);
	fprintf(f,"%s",new_book.publisher);
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
		if (count == 1)
		{
			printf("Título: %s", line);
		}
		else if (count == 2)
		{
			printf("Autor(a): %s", line);
		}
		else if (count == 3)
		{
			printf("Editora: %s\n", line);
			count = -1;
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
	system("clear");

	char book_title[50];
	char author_name[50];
	char publisher[50];
	char line[50];
	
	char searched_title[50];
	printf("Digite o título que deseja buscar: ");
	fgets(searched_title,50,stdin);
	printf("\n");

	FILE *f = fopen("books//data.txt","r");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);

		if (strcmp(searched_title,book_title) ==0 )
		{
			fgets(author_name,50,f);
			fgets(publisher,50,f);
		
			printf("Título: %s", book_title);
			printf("Autor: %s", author_name);
			printf("Editora: %s\n",publisher);
		}
		else
		{
			fgets(line,50,f);
			fgets(line,50,f);
		}
	}

	if (getAnswer(2) == 'S')
	{
		checkTitle();
	}
	else
	{
		showMenu();
	}	
}

void checkAuthor()
{
	system("clear");

	char book_title[50];
	char author_name[50];
	char publisher[50];
	char line[50];
	
	char searched_author[50];
	printf("Digite o nome do autor que deseja buscar: ");
	fgets(searched_author,50,stdin);
	printf("\n");

	FILE *f = fopen("books//data.txt","r");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
			
		if (strcmp(searched_author,author_name) ==0 )
		{
			fgets(publisher,50,f);
		
			printf("Título: %s", book_title);
			printf("Autor: %s", author_name);
			printf("Editora: %s\n",publisher);
		}
		else
		{
			fgets(line,50,f);
		}
	}

	if (getAnswer(2) == 'S')
	{
		checkAuthor();
	}
	else
	{
		showMenu();
	}	
}

void checkPublisher()
{
	system("clear");

	char book_title[50];
	char author_name[50];
	char publisher[50];
	char line[50];
	
	char searched_publisher[50];
	printf("Digite o nome do autor que deseja buscar: ");
	fgets(searched_publisher,50,stdin);
	printf("\n");

	FILE *f = fopen("books//data.txt","r");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);	
		
		if (strcmp(searched_publisher,publisher) ==0 )
		{
			printf("Título: %s", book_title);
			printf("Autor: %s", author_name);
			printf("Editora: %s\n",publisher);
		}
	}

	if (getAnswer(2) == 'S')
	{
		checkPublisher();
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
	system("clear");
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













