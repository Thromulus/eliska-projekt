#pragma once
#define NAZEV_SIZE 30
#define COMM_SIZE 50

typedef struct t_hodnoceni
{
    char komentar[COMM_SIZE];
    int hvezdy;

    struct t_hodnoceni* dalsi;
}hod;

typedef struct t_restaurace
{
    char nazev[NAZEV_SIZE];
    int index;

    struct t_restaurace* dalsi;
    struct t_hodnoceni* hodnoceni;
}res;



void pridat(char* nazev, struct t_restaurace** uk_prvni);
void smazat(int sindex, struct t_restaurace** uk_prvni);
//void hodnoceni(int sindex, char* komentar, int hvezdy, struct t_hodnoceni** huk_prvni);
void searchRestaurant(int sindex, char* komentar, int hvezdy, struct t_restaurace** uk_prvni, struct t_hodnoceni** huk_prvni);
void SortRestaurace(int sindex, char* komentar, int hvezdy, struct t_hodnoceni** huk_prvni);

