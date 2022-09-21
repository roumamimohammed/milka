#ifndef fonction_h
#define fonction_h
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct medicament{
    char nom[50],codebar[50];
    int quantite;
	float prix;
	float prixTTC;}medicament;
 int ajouterproduit( medicament tab[1000],int medicaments);
 medicament acheterproduit( medicament tab[1000],medicament tabcopie[1000],int medicaments);
 float statistique1(medicament tabcopie[1000],int medicaments,float S);
 float statistique2(medicament tabcopie[1000],int medicaments,float S,float Q);
 void inferieur(medicament tab[1000],int medicaments);
 void recherchparcode(medicament tab[1000],int medicaments);
 void alimenter(medicament tab[1000],int medicaments);
 #endif
