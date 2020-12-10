#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"RestauraceDB.h"

struct t_restaurace* prvni = NULL;
struct t_hodnoceni* hprvni = NULL;
int j = 0;

void ppridat() 
{
    char nazev[NAZEV_SIZE];
	char komentar[COMM_SIZE];
    int hodnoceni;

    printf("\nNazev restaurace kterou chcete pridat: ");         
    scanf_s("%[^\n]s", nazev, NAZEV_SIZE);
	while (getchar() != '\n');

    pridat(nazev, &prvni);
	
}

void psmazat()
{
	int sindex = 0;

	printf("\nZadejte cislo restaurace, kterou chcete smazat: ");
	scanf_s("%d", &sindex);
	while (getchar() != '\n');
	smazat(sindex, &prvni);        
}

void tisk()
{
	int index = 1;
	int i = 0;
	//int count = 0;
	struct t_restaurace* aktrestaurace = prvni;
	struct t_hodnoceni* akthodnoceni = hprvni;
	printf("\n\n");
	

	while (aktrestaurace!=NULL)
	{
		aktrestaurace->index = i; 
		printf("%i) %s\n", aktrestaurace->index, aktrestaurace->nazev);
		if (aktrestaurace->hodnoceni != NULL)
		{
			printf("%i %s\n", aktrestaurace->hodnoceni->hvezdy, aktrestaurace->hodnoceni->komentar);
			aktrestaurace->hodnoceni = aktrestaurace->hodnoceni->dalsi;
		}
		aktrestaurace = aktrestaurace->dalsi;
		i++;
	}
}

void phodnoceni()
{
	char komentar[COMM_SIZE];
	int sindex = 0, hvezdy;

	printf("\nZadejte cislo restaurace, kterou chcete hodnotit: ");
	scanf_s("%d", &sindex);
	while (getchar() != '\n');
	printf("\nZadejte komentar: ");
	scanf_s("%[^\n]s", komentar, COMM_SIZE);
	while (getchar() != '\n');
	printf("\nHvezdicky: ");
	scanf_s("%d", &hvezdy);
	while (getchar() != '\n');

	searchRestaurant(sindex, komentar, hvezdy, &prvni, &hprvni);
	
}

int main()
{
	char  volba;

	do
	{
		system("cls");	
		printf("1: Pridat\n");
		printf("2: Smazat\n");
		printf("3: Tisk\n");
		printf("4: Hodnoceni\n");
		printf("5: Konec\n\n");

		volba = getchar();
		while (getchar() != '\n');

		switch (volba)
		{
		case '1':
			ppridat();
			break;
		case '2':
			tisk(); 
			psmazat();
			break;
		case '3':
			tisk();
			getchar();
			break;
		case '4':
			tisk();
			phodnoceni();
			break;
		default: 
			if (volba != '5') { printf("Zadejte validni volbu\n\n"); }
		}
	} while (volba != '5');   
	return 0;
}