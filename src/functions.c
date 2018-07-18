#include <stdio.h>
#include "functions.h"

void add_book()
{
	printf("Adiciona\n");
}

void remove_book()
{
	printf("Remove\n");
}

void check_the_book()
{
	printf("Checa\n");
}

void show_menu()
{
	int command;

	printf("Sistema de Livraria\n");
	printf("1 - Adicionar Livro\n");
	printf("2 - Remover Livro\n");
	printf("3 - Checar Livro\n");
	printf("4 - Sair\n\n");
	printf("O que deseja? ");
	
	scanf("%d", &command);

	switch(command)
	{
		case 1 :
		add_book();
		break;

		case 2 :
		remove_book();
		break;

		case 3 :
		check_the_book();
		break;
	}
}