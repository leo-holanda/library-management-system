#include <stdio.h>
#include "functions.h"

typedef struct book
{
	int id;
	char nome_do_autor[10];
	char nome_do_livro[10];
	char nome_da_editora[10];
} book;

void addBook(book *list)
{
	book new_book;
	printf("Digite o nome do livro: ");
	fgets(new_book.nome_do_livro,10,stdin);
	printf("Digite o nome do autor: ");
	fgets(new_book.nome_do_autor,10,stdin);
	printf("Digite o nome da editora: ");
	fgets(new_book.nome_da_editora,10,stdin);

	int i = 0;
	while(list[i].id != -1)
	{
		i++;
	}

	new_book.id=i;
	list[i]=new_book;
	showMenu(list);
}

void removeBook(book *list)
{
	printf("Digite o ID\n");
	
	int id;
	scanf("%d", &id);

	list[id].id = -1;
	showMenu(list);
}

void checkTheBook(book *list)
{
	printf("Digite o ID\n");

	int id;
	scanf("%d", &id);

	puts(list[id].nome_do_livro);
	puts(list[id].nome_do_autor);
	puts(list[id].nome_da_editora);	
	showMenu(list);
}

void showMenu(book *list)
{ 
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
		case 1 :
		addBook(list);
		break;

		case 2 :
		removeBook(list);
		break;

		case 3 :
		checkTheBook(list);
		break;
	}
}