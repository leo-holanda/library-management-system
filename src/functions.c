#include "functions.h"

int compareString(char *string_1, char *string_2)
{
	char compare_1[50];
	strcpy(compare_1,string_1);
	char compare_2[50];
	strcpy(compare_2,string_2);

	int i;
	for (i = 0; i < 50; ++i)
	{
		compare_1[i] = tolower(compare_1[i]);
		compare_2[i] = tolower(compare_2[i]);
	}

	compare_1[strlen(compare_1)-1] = '\0';	

	if (strstr(compare_2,compare_1) == NULL)
	{
		return 0;
	}
	
	return 1;
}

int getCommand(int token)
{

	int command;

	if (token == 1)
	{
		printf("-> ");
		scanf("%d", &command);
		getchar();
		
		while(command != 1 && command != 2 && command != 3 && command != 4)
		{
			printf("Comando invalido! Digite novamente -> ");
			scanf("%d", &command);
			getchar();
		}
	}
	else if (token == 2)
	{	
		printf("Digite o comando desejado -> ");
		scanf("%d", &command);
		getchar();
	
		while(command != 1 && command != 2 && command != 3 && command && command !=  4 && command != 5)
		{
			printf("Comando invalido! Digite novamente -> ");
			scanf("%d", &command);
			getchar();
		}
	}

	return command;
}

char getAnswer(int token)
{
	if (token == 0)
	{
		printf("Livro adicionado com sucesso! Deseja adicionar outro?");
	}
	else if (token == 1)
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

void setCategory(char *new_book_category)
{
	printf("\n0 - Generalidades\n");
	printf("1 - Filosofia\n");
	printf("2 - Religiao\n");
	printf("3 - Ciencias sociais\n");
	printf("4 - Linguas\n");
	printf("5 - Ciencias Puras\n");
	printf("6 - Ciencias Aplicadas\n");
	printf("7 - Artes\n");
	printf("8 - Literatura\n");
	printf("9 - Historia e Geografia\n\n");

	printf("Digite o número -> ");

	int category;
	scanf("%d", &category);
	getchar();

	while (category != 0 && category != 1 && category != 2 && category != 3 && category != 4 && 
		category != 5 && category != 6 && category != 7 && category != 8 && category != 9)
	{
		printf("Numero invalido, digite novamente -> ");
		scanf("%d", &category);
		getchar();
	}

	switch(category)
	{
		case 0:
		strcpy(new_book_category,"Generalidades");
		break;	

		case 1:
		strcpy(new_book_category,"Filosofia");
		break;	

		case 2:
		strcpy(new_book_category,"Religiao");
		break;

		case 3:
		strcpy(new_book_category,"Ciencias Sociais");
		break;	

		case 4:
		strcpy(new_book_category,"Linguas");
		break;	

		case 5:
		strcpy(new_book_category,"Ciencias Puras");
		break;	

		case 6:
		strcpy(new_book_category,"Ciencias Aplicadas");
		break;	

		case 7:
		strcpy(new_book_category,"Artes");
		break;	

		case 8:
		strcpy(new_book_category,"Literatura");		
		break;	

		case 9:
		strcpy(new_book_category,"Historia e Geografia");
		break;		
	}
}

struct tm getTime() 
{	    
	time_t t = time(0);
	struct tm *today_time = localtime(&t);
	return *today_time;
}

void addBook()
{
	system("clear");
	
	int isbn;
	char author_name[50];
	char book_title[50];
	char publisher[25];
	char category[20];
	struct tm *today;

	printf("Digite o nome do livro: ");
	fgets(book_title,50,stdin);
	printf("Digite o nome do autor: ");
	fgets(author_name,50,stdin);
	printf("Digite o nome da editora: ");
	fgets(publisher,25,stdin);
	printf("Digite o número de ISBN: ");
	
	scanf("%d", &isbn);
	getchar();
	
	printf("Escolha a categoria\n");
	setCategory(category);
	
	*today = getTime();


	FILE *f = fopen("books//data.txt","a+");
	fprintf(f,"\n%s",book_title);
	fprintf(f,"%s",author_name);
	fprintf(f,"%s",publisher);
	fprintf(f,"%d\n",isbn);
	fprintf(f,"%s\n",category);
	fprintf(f,"%.2d/%.2d/%.2d\n", today->tm_mday, today->tm_mon+1, today->tm_year+1900);
	fclose(f);

	(getAnswer(0)) ? addBook() : showMenu();
}

void showAllBooks()
{
	system("clear");
	
	char book_title[50];
	char author_name[50];
	char publisher[50];
	char isbn[50];
	char category[20];
	char date[15];

	char line[50];
	FILE *f = fopen("books//data.txt","r");

	printf("\n");

	while(fgets(line,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);	
		fgets(isbn,50,f);
		fgets(category,20,f);
		fgets(date,15,f);

		printf("Título: %s", book_title);
		printf("Autor: %s", author_name);
		printf("Editora: %s",publisher);
		printf("ISBN: %s", isbn);
		printf("Categoria: %s", category);
		printf("Dia do cadastro: %s\n", date);
	}

	fclose(f);

	(getAnswer(1)) ? showAllBooks() : showMenu();
}

void checkContent(int command)
{
	system("clear");

	int hasFound = 0;

	char book_title[50];
	char author_name[50];
	char publisher[50];
	char isbn[50];
	char category[20];
	char date[15];

	char *picked_content;
	switch(command)
	{
		case 1:
		printf("Digite o título que deseja buscar: ");
		picked_content = book_title;
		break;

		case 2:
		printf("Digite o autor que deseja buscar: ");
		picked_content = author_name;
		break;

		case 3:
		printf("Digite a editora que deseja buscar: ");
		picked_content = publisher;
		break;

		case 4:
		printf("Digite a categoria que deseja buscar: ");
		picked_content = category;
		break;

		case 5:
		showAllBooks();
		break;
	}
	
	char searched_content[50];
	fgets(searched_content,50,stdin);
	printf("\n");

	FILE *f = fopen("books//data.txt","r");

	char line_break[50];
	while(fgets(line_break,50,f) != NULL)
	{
		fgets(book_title,50,f);
		fgets(author_name,50,f);
		fgets(publisher,50,f);
		fgets(isbn,50,f);
		fgets(category,50,f);
		fgets(date,15,f);

		if (compareString(searched_content,picked_content))
		{
			hasFound = 1;
			printf("Título: %s", book_title);
			printf("Autor: %s", author_name);
			printf("Editora: %s",publisher);
			printf("ISBN: %s", isbn);
			printf("Categoria: %s", category);
			printf("Dia do cadastro: %s\n", date);
		}
	}
	
	fclose(f);

	if (!hasFound)
	{
		printf("Não foi possível encontrar resultados para essa pesquisa.\n");
	}

	(getAnswer(1)) ? checkContent(command) : showMenu();
}

void eraseBooks()
{
	system("clear");
	fclose(fopen("books//data.txt", "w"));
}

void showMenu()
{ 
	system("clear");

	printf("Sistema de Livraria\n\n");
	printf("1 - Adicionar Livro\n");
	printf("2 - Checar Livro\n");
	printf("3 - Apagar dados\n");
	printf("4 - Sair\n\n");
	printf("O que deseja? ");
	
	int command = getCommand(1);
	switch(command)
	{
		case 1:
		addBook();
		break;

		case 2:
		showCheckMenu();
		break;

		case 3:
		eraseBooks();
		break;

		case 4:
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
	printf("4 - Categoria\n");
	printf("5 - Todos os livros\n");

	int command = getCommand(2);
	checkContent(command);
}