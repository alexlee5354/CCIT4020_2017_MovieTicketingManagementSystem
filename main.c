#include <stdio.h>
void menu();

int main()
{
	printf("\n\t*** Welcome to HK Grand SPACE Movie Ticketing Management System 2017 ***\n");
	printf("\n\t*** This system is developed by CCIT4020 CLass No.CL-?? Group No.?? ***\n");
	menu();
	
	return 0;
}

void menu()
{
	char option, phantom;
	
	printf("\n\n--<Basic Functions>--\n");
	printf("\n 1. Add New Movie Ticketing Record(s):\n");
	printf("\n 2. Display All Movie Ticketing Records:\n");
	printf("\n 3. Modify Movie Ticketing Record(s):\n");
	printf("\n 4. Search Movie Ticketing Record(s):\n");
	printf("\n 5. Delete Movie Ticketing Record(s):\n");
	printf("\n What is your option (1-5)? ");
	scanf("%c%c", &option, &phantom);
	
	switch(option)
	{
		case '1':
		break;
		case '2':
		break;
		case '3':
		break;
		case '4':
		break;
		case '5':
		break;
		default:
		printf(" Please select a correct number (1-5)!");
		menu();
	}
}
