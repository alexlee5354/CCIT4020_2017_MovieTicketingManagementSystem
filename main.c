#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addMov();
void dispMov();
void modMov();
void findMov();
void delMov();
void showmovie();

struct book
{
	int mnum;
	char cname[30];
	char mname[30];
	char mdate[12];
	int mtimehour;
	int mtime;
	char ttype[30];
	int guestsnum;
	int housenum;
	int fee;
}
;
void main()
{	
	int option;
	printf("\n\t*** Welcome to HK Grand SPACE Movie Ticketing Management System 2017 ***\n");
	printf("\n\t*** This system is developed by CCIT4020 CLass No.CL-?? Group No.?? ***\n");
	do
	{
		printf("\n\n--<Basic Functions>--\n");
		printf("\n 1. Add New Movie Ticketing Record(s)\n");
		printf("\n 2. Display All Movie Ticketing Records\n");
		printf("\n 3. Modify Movie Ticketing Record(s)\n");
		printf("\n 4. Search Movie Ticketing Record(s)\n");
		printf("\n 5. Delete Movie Ticketing Record(s)\n");
		printf("\n 6. Quit\n");
		printf("\nWhat is your option (1-6)? ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				addMov(); /* Add New Movie Ticketing Records function go here*/
				break;
			case 2:
				dispMov(); /* Display All Movie Ticketing Records function go here */
				break;
			case 3:
				modMov(); /* Modify Movie Ticketing Records function go here */
				break;
			case 4:
				findMov(); /* Search Movie Ticketing Records function go here */
				break;
			case 5:
				delMov(); /* Delete Movie Ticketing Records function go here */
				break;
			case 6:
				printf("See you next time :)");
				exit(0);
				break;
			default:
				printf("Please select a correct number (1-6)!");
		}
	} while(option!=6);
}

void addMov()
{
	struct book b;
	char op;
	FILE *fp;
	printf("Enter Movie Booking Number (XXXX): ");	
	scanf("%d",&b.mnum);
	while(b.mnum<1||b.mnum>9999)
	{
		printf("Re-enter Movie Booking Number! It should be between 0001 to 9999!: ");	
		scanf("%d",&b.mnum);
	};
	printf("Enetr Name of Customer: ");	
	gets(b.cname);
	gets(b.cname);
	printf("Enetr Name of Movie: ");	
	gets(b.mname);
	printf("Enetr Movie Schedule (DD-MM-YYYY): ");	
	gets(b.mdate);
	printf("Enetr Time (XXXX): ");	
	scanf("%d",&b.mtime);
	while(b.mtime<1000||b.mtime>2300)
	{
		printf("Re-enetr Time! It should be in 24-hour format and between 1000 to 2300!: ");	
		scanf("%d",&b.mtime);
	};
	printf("Enetr Number of Guests: ");	
	scanf("%d",&b.guestsnum);
	printf("Enter House Number: ");
	scanf("%d",&b.housenum);
	printf("Enter Ticket Type: ");
	scanf("%s",b.ttype);
	printf("Enter Total Fee: ");
	scanf("%d",&b.fee);
	fp=fopen("movie.txt","a");
	if(fp == NULL)
	{
		printf("File not found!");
	}
	else
	{
		fprintf(fp,"%d\n%s\n%s\n%s\n%d\n%d\n%d\n%s\n%d\n\n",b.mnum,b.cname,b.mname,b.mdate,b.mtime,b.guestsnum,b.housenum,b.ttype,b.fee);
		printf("Record insert sucessful!");
	}
	printf("\n");
	fclose(fp);
	do
	{
		printf("Add another record (y/n)?");
		scanf("%s",&op);
		switch(op)
		{
			case 'y':
				printf("\n");
				addMov();
			case 'n':
				printf("\n");
				main();
			default:
				printf("Please select (y) or (n)!\n");
		}
	} while(op!='n');
}

void dispMov()
{
	char ch;
	FILE *fp;
	printf("\n");
	fp = fopen("movie.txt","r");
	if(fp == NULL)
	{
		printf("File not found!");
		exit(1);
	}
	else
	{	
		while((ch=fgetc(fp))!=EOF)
		{
			printf("%c",ch);
		}
	}
	fclose(fp);	
}

void modMov()
{
	
}

void findMov()
{   
    char op;
	char bk[100],line[250];
	char bnum[250],cname[250],mname[250],mdate[250],mtime[250],guestsnum[250],housenum[250],ttype[250],fee[250];
	struct book b;
	printf("Enter booking number: ");
	scanf("%s",bk);
	FILE *fp;
	fp =fopen("movie.txt","r");
	if (fp==NULL)
 	{	
	    printf("File not found!");
    }
	else
	{	
		while (fscanf(fp,"%s",bnum) != EOF)
		{
			if (strcmp(bk,bnum)==0)
    		{	  	
			  	printf("\nRecord found.\n\nBooking number: %s", bnum);
				fgets(line,250,fp); //skipping to new line
				fgets(cname,250,fp);
				printf("\nName: %s",cname);
				fgets(mname,250,fp);
			  	printf("Movie name: %s",mname);
			    fgets(mdate,250,fp);
			  	printf("Movie Schedule : %s", mdate);
			  	fgets(mtime,250,fp);
			  	printf("Time: %s",mtime);
				fgets(guestsnum,250,fp);
			  	printf("Number of Guests: %s",guestsnum);
			  	fgets(housenum,250,fp);
				printf("House Number: %s",housenum);
				fgets(ttype,250,fp);
				printf("Type: %s",ttype);
				fgets(fee,250,fp);
				printf("Total fee: %s",fee);
			}
			else
			{
				printf("\nRecord not found!");
				break;
			}
  		}
	}
	do
	{
		printf("\nFind another record (y/n)?");
		scanf("%s",&op);
		switch(op)
		{
			case 'y':
				printf("\n");
				findMov();
			case 'n':
				printf("\n");
				main();
			default:
				printf("Please select (y) or (n)!\n");
		}
	} while(op!='n');	   	
}	

void delMov()
{
	
}


