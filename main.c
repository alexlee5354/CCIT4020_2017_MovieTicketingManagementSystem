#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void addMov();
void dispMov();
void modMov();
void findMov();
void delMov();

struct book
{
	int mnum;
	char cname[30];
	char mname[30];
	char mdate[50];
	int mtime;
	char ttype[30];
	int guestsnum;
	int housenum;
	int fee;
};

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
		printf("\n What is your option (1-6)? ");
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
				printf(" See you next time :)");
				exit(0);
				break;
			default:
				printf(" Please select a correct number (1-6)!");
		}
	} while(option!='6');
}

void addMov()
{
	char op, ph;
	FILE *fp;
	struct book b;
	printf("Enetr Movie Booking Number (XXXX): ");	
	scanf("%d",&b.mnum);
	printf("Enetr Name of Customer: ");	
	scanf("%s",b.cname);
	printf("Enetr Name of Movie: ");	
	scanf("%s",b.mname);
	printf("Enetr Movie Schedule (DD-MM-YYYY): ");	
	scanf("%s",b.mdate);
	printf("Enetr Time (XXXX):");	
	scanf("%d",&b.mtime);
	printf("Enetr Number of Guests: ");	
	scanf("%d",&b.guestsnum);
	printf("Enter House Number: ");
	scanf("%d",&b.housenum);
	printf("Enter Ticket Type: ");
	scanf("%s",b.ttype);
	printf("Enter Total Fee: ");
	scanf("%d",&b.fee);

	fp=fopen("ticket.txt","a");
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
	fp = fopen("ticket.txt","r");
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
	char usernum[100],line[250];
	char bn[250],cn[250],mn[250],sch[250],gn[250],hn[250],t[250],f[250];
	struct book b;
	printf("Enter your booking number:");
	scanf("%s",usernum);
	FILE *movieFILE;
	movieFILE=fopen("movie.txt","r");
	if (movieFILE==NULL)
 	{	
	    printf("FILE not found.");
    }
	else
	{	
	 while (fscanf(movieFILE,"%s",bn) != EOF)
	{
	  if (strcmp(usernum,bn)==0)
    {	  	
	  	printf("Record found.\n\n|1|Booking number: %s", bn);
	  	
		fgets(line,250,movieFILE); //skipping to new line
		
		fgets(cn,250,movieFILE);
		printf("\n\n|2|Your name: %s",cn);
		  	
		fgets(mn,250,movieFILE);
	  	printf("\n|3|Movie name: %s",mn);
	  	
	    fgets(sch,250,movieFILE);
	  	printf("\n|4|Schedule: %s", sch);
	  	
		fgets(gn,250,movieFILE);
	  	printf("\n|5|Number of Guests: %s",gn);
		  	
	  	fgets(hn,250,movieFILE);
		printf("\n|6|House Number: %s",hn);
	  	
		fgets(t,250,movieFILE);
		printf("\n|7|Type: %s",t);
	  	
		fgets(f,250,movieFILE);
		printf("\n|8|Total fee: %s",f);
	}
	
		do
	{
		printf("Add another record (y/n)?");
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
    }
		   	
}	


void delMov()
{
	
}
