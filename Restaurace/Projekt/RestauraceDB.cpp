#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"RestauraceDB.h"

void pridat(char* nazev, struct t_restaurace** uk_prvni)
{
	struct t_restaurace* novarestaurace; 
	struct t_restaurace* aktrestaurace;

	novarestaurace = (struct t_restaurace*)malloc(sizeof(struct t_restaurace));

	strcpy_s(novarestaurace->nazev, NAZEV_SIZE, nazev); 
	novarestaurace->dalsi = NULL;

	if (*uk_prvni == NULL)
	{
		*uk_prvni = novarestaurace;
		return;
	}
	else if (strcmp(novarestaurace->nazev, (*uk_prvni)->nazev) < 0)
	{
		novarestaurace->dalsi = *uk_prvni;
		*uk_prvni = novarestaurace;
		return;
	}

	aktrestaurace = *uk_prvni;
	while (aktrestaurace)
	{
		if (aktrestaurace->dalsi == NULL)
		{
			aktrestaurace->dalsi = novarestaurace;
			return;
		}
		else if (strcmp(novarestaurace->nazev, aktrestaurace->dalsi->nazev) < 0)
		{
			novarestaurace->dalsi = aktrestaurace->dalsi;
			aktrestaurace->dalsi = novarestaurace;
			return;
		}
		aktrestaurace = aktrestaurace->dalsi;
	}
	
}

void smazat(int sindex, struct t_restaurace** uk_prvni)
{
	struct t_restaurace* aktrestaurace;
	
	while (*uk_prvni && (*uk_prvni)->index == sindex)
	{
		struct t_restaurace* newPrvni = (*uk_prvni)->dalsi;
		free(*uk_prvni); 
		*uk_prvni = newPrvni;
	}

	aktrestaurace = *uk_prvni;
	while (aktrestaurace && aktrestaurace->dalsi) 
	{
		if (aktrestaurace->dalsi->index == sindex)
		{
			struct t_restaurace* newDalsi = aktrestaurace->dalsi->dalsi;
			free(aktrestaurace->dalsi);
			aktrestaurace->dalsi = newDalsi;
		}
		aktrestaurace = aktrestaurace->dalsi; 
	}
}

t_hodnoceni *hodnoceni(int sindex, char* komentar, int hvezdy, struct t_hodnoceni** huk_prvni)
{	
	struct t_hodnoceni* novehodnoceni;
	struct t_hodnoceni* akthodnoceni;
	novehodnoceni = (struct t_hodnoceni*)malloc(sizeof(struct t_hodnoceni));

	strcpy_s(novehodnoceni->komentar, COMM_SIZE, komentar);
	novehodnoceni->hvezdy = hvezdy;
	novehodnoceni->dalsi = NULL;

	if (*huk_prvni == NULL) // linearni seznam je prazdny
	{
		*huk_prvni = novehodnoceni;
		return akthodnoceni;
	}
	akthodnoceni = *huk_prvni;
	while(akthodnoceni!=NULL) // prochazeni seznamu
	{
		if (akthodnoceni->dalsi == NULL) // jsme na poslednim 
		{
			akthodnoceni = novehodnoceni; // pridavame na konec
			return akthodnoceni;
		}
		akthodnoceni = akthodnoceni->dalsi;
	}
	
}

void searchRestaurant(int sindex, char* komentar, int hvezdy, struct t_restaurace** uk_prvni, struct t_hodnoceni** huk_prvni)
{
	struct t_hodnoceni* akthodnoceni;
	struct t_restaurace* aktrestaurace;

	while (*uk_prvni && (*uk_prvni)->index == sindex)
	{
		struct t_restaurace* newPrvni = (*uk_prvni)->dalsi;
		//hodnoceni(hvezdy, komentar, hvezdy, &*huk_prvni);
		aktrestaurace->hodnoceni = hodnoceni(hvezdy, komentar, hvezdy, &*huk_prvni);
		*uk_prvni = newPrvni;
	}

	aktrestaurace = *uk_prvni;
	while (aktrestaurace && aktrestaurace->dalsi)
	{
		if (aktrestaurace->dalsi->index == sindex)
		{
			struct t_restaurace* newDalsi = aktrestaurace->dalsi->dalsi;
			hodnoceni(hvezdy, komentar, hvezdy, &*huk_prvni);
			aktrestaurace->dalsi = newDalsi;
		}
		aktrestaurace = aktrestaurace->dalsi;
	}
}

void SortRestaurace(int sindex, char* komentar, int hvezdy, struct t_hodnoceni** huk_prvni)
{
	struct t_hodnoceni* novehodnoceni;
	struct t_hodnoceni* akthodnoceni;

	/*if (*huk_prvni == NULL)
	{
		*huk_prvni = novehodnoceni;
		return;
	}
	else if (strcmp(novehodnoceni->komentar, (*huk_prvni)->komentar) < 0)
	{
		novehodnoceni->dalsi = *huk_prvni;
		*huk_prvni = novehodnoceni;
		return;
	}

	akthodnoceni = *huk_prvni;
	while (akthodnoceni)
	{
		if (akthodnoceni->dalsi == NULL)
		{
			akthodnoceni->dalsi = novehodnoceni;
			return;
		}
		else if (strcmp(novehodnoceni->komentar, akthodnoceni->dalsi->komentar) < 0)
		{
			novehodnoceni->dalsi = akthodnoceni->dalsi;
			akthodnoceni->dalsi = novehodnoceni;
			return;
		}
		akthodnoceni = akthodnoceni->dalsi;
	}*/
}

