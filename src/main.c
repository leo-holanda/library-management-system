#include "functions.c"

int main()
{
	int i = 0;
	book list[10];
	
	while(i != 10)
	{
		list[i].id = -1;
		i++;
	}
	
	showMenu(list);

	return 0;
}	