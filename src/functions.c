#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

typedef struct book
{
	int id;
	char author_name[50];
	char book_title[50];
	char publisher[25];
} book;

int compareString(char *string_1, char *string_2)
{
	char compare_1[50];
	strcpy(compare_1,string_1);
	char compare_2[50];
	strcpy(compare_2,string_2);

	int i;
	for (int i = 0; i < 50; ++i)
	{
		compare_1[i] = tolower(compare_1[i]);
		compare_2[i] = tolower(compare_2[i]);
	}

	if (strcmp(compare_1,compare_2) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int getCommand(int select)
{
	int command;
	scanf("%d", &command);
	getchar();

	if (select == 1)
	{
		while(command != 1 && command != 2 && command != 3)
		{
			printf("Comando invalido! Digite novamente (1,2,3) -> ");
			scanf("%d", &command);
			getchar();
		}
	}
	else if (select == 2)
	{
		while(command != 1 && command != 2 && command != 3 && command && command != 4)
		{
			printf("Comando invalido! Digite novamente (1,2,3,4) -> ");
			scanf("%d", &command);
			getchar();
		}
	}

	return command;
}

char getAnswer(int select)
{
	if (select == 0)
	{
		printf("Livro adicionado com sucesso! Deseja adicionar outro?");
	}
	else if (select == 1)
	{
		printf("Deseja consultar novamente?");		
	}
	
	printf(" (s/n) -> ");

	char answer;
	scanf("%c", &answer);
	getchar();
	answer = tolower(answer);
	
	while(answer != 's' && answer != 'n')
	{
		printf("\nComando invalido! Digite novamente -> ");
		scanf("%c", &answer);
		getchar();
		answer = tolower(answer);		
	}

	if (answer == 's')
	{
		return 1;
	}
	else if(answer == 'n')
	{
		return 0;
	}
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

	if (getAnswer(0))
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

	if (getAnswer(1))
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
	int count = 0;
	
	char searched_title[50];
	printf("Digite o título que deseja buscar: ");
	fgets(searched_title,50,stdin);
	printf("\n");

	FILE *f = fopen("books//data.txt","r");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);

		if (compareString(searched_title,book_title))
		{
			count = 1;

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

	if (count == 0)
	{
		printf("Não foi possível encontrar resultados para essa pesquisa.\n");
	}

	if (getAnswer(1))
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
	int count = 0;
	
	char searched_author[50];
	printf("Digite o nome do autor que deseja buscar: ");
	fgets(searched_author,50,stdin);
	printf("\n");

	FILE *f = fopen("books//data.txt","r");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
			
		if (compareString(searched_author,author_name))
		{
			count = 1;

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

	if (count == 0)
	{
		printf("Não foi possível encontrar resultados para essa pesquisa.\n");
	}

	if (getAnswer(1))
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
	int count = 0;

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
		
		if (compareString(searched_publisher,publisher))
		{
			count = 1;
			printf("Título: %s", book_title);
			printf("Autor: %s", author_name);
			printf("Editora: %s\n",publisher);
		}
	}

	if (count == 0)
	{
		printf("Não foi possível encontrar resultados para essa pesquisa.\n");
	}

	if (getAnswer(1))
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

	printf("Sistema de Livraria\n\n");
	printf("1 - Adicionar Livro\n");
	printf("2 - Checar Livro\n");
	printf("3 - Sair\n\n");
	printf("O que deseja? ");
	
	int command;
	command = getCommand(1);

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
	command = getCommand(2);

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


// switch case - usar while para receber command evitar entradas erradas x
// mostrar "não foram encontrados resultados" nas check functions x
// melhorar tela
// adicionar ISBN e categoria na struct book
// adicionar busca por ISBN(?) e categoria