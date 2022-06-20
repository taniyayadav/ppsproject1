#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
struct Indian_airline
{
	char passport[100];
	char name[100];
    char destination[100];
	char email[100];
	char mobile[100];
	struct Indian_airline *following;
}
*begin, *stream;
struct Indian_airline *dummy;
void main()
{
	system("cls");
	void reserve(int x), cancel(), display(), savefile();
	int choice;
	begin = stream = NULL; 
	int num = 1;
	do
	{
		system("cls");
		printf("\n\n\t\t ********************************************************************");
		printf("\n\t\t         Welcome to Indian airline Ticket reservationb system        ");
		printf("\n\t\t   *******************************************************************");
		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1. Reservation");
		printf("\n\n\t\t 2. Cancel");
		printf("\n\n\t\t 3. DISPLAY RECORDS");
		printf("\n\n\t\t 4. EXIT");
		printf("\n\n\t\t Feel free to contact our helpline");
		printf("\n\n\t\t Enter your choice :");
		scanf("%d", &choice); 
		fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			cancel();
			break;
		case 3:
			display();
			break;
		case 4:
		{
				  savefile();
				  break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-4");
			printf("\n\n\t Do not forget to chose from 1-4");
		}
		getch();
	} 
	while (choice != 4);
	system("cls");
}
void details()
{
	printf("\n\t Enter your passport number:");
	gets(stream->passport); 
	fflush(stdin);
	printf("\n\t Enter your  name:");
	gets(stream->name); 
	fflush(stdin);
	printf("\n\t Enter your email address:");
	gets(stream->email); 
	fflush(stdin);
    printf("\n\t Enter the Mobile number : ");
    gets(stream->mobile);
	fflush(stdin);
	printf("\n\t Enter the Destination : ");
    gets(stream->destination);
	fflush(stdin);
}
void details();
void reserve(int x)
{
	stream = begin;
	system("cls");
	if (begin == NULL)
	{
		begin = stream = (struct Indian_airline*)malloc(sizeof(struct Indian_airline));
		details();
		stream->following = NULL;
		printf("\n\t Seat reservation successful!");
		printf("\n\t Check your mail for further updates and payment");
	}
} 
void savefile()
{
	FILE *fpointer = fopen("Indian records", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;
		Sleep(800);
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6s", stream->passport);
		fprintf(fpointer, "%-15s", stream->name);
		fprintf(fpointer, "%-15s", stream->email);
		fprintf(fpointer, "%-15s", stream->mobile);
        fprintf(fpointer, "%-15s", stream->destination);
        fprintf(fpointer, "\n");
		stream = stream->following;
	}
	printf("\n\n\t Details have been saved to a file (Indian records)");
	fclose(fpointer);
}
void display()
{
	stream = begin;
	while (stream)
	{
		printf("\nPassport Number : %-6s", stream->passport);
		printf("\nName : %-15s", stream->name);
		printf("\nEmail address: %-15s", stream->email);
		printf("\nMobile Number: %-15s", stream->mobile);
        printf("\nDestination:%-15s", stream->destination);
		printf("\n*=====================================================*");
		stream = stream->following;
	}

}
void cancel()
{
	stream = begin;
	system("cls");
	char passport[6];
	printf("\n\t Enter passort number to delete Reservation?:");
	gets(passport); fflush(stdin);
	if (strcmp(begin->passport, passport) == 0)
	{
		dummy = begin;
		begin = begin->following;
		free(dummy);
		printf("\n\tYour Reservation has been deleted");
		Sleep(800);
		return;
	}
	while (stream->following)
	{
		if (strcmp(stream->following->passport, passport) == 0)
		{
			dummy = stream->following;
			stream->following = stream->following->following;
			free(dummy);
			printf("\n\tYour Reservation has been deleted");
			getch();
			Sleep(800);
			return;
		}
		stream = stream->following;
	}
	printf("\n\tEntered passport number is wrong please check your passport");
}