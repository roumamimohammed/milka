#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonction.h"




int main(int argc, char *argv[]) {
	int	nomexiste,codebarexiste;	
	 medicament tab[1000],medajoute[1000],tmp;
	char identifiantduproduit[50];
	char linebreak1[120]="+----------------------------------------------+----------------------------------------+\n";
	char linebreak[120]="+----------------------------------------------+----------------------------------------+\n";
    int n,j, i = 0,medicaments=0, autremedicament=1,quantite_a_acheter=0,k;
	float totaldelacommande=0,sommedonnee=0,rendudelasommedonne=0;
		while(1){	
		printf("%s",linebreak1);
    	printf("|                                        MENU PRINCIPALE                                |\n");
		printf("%s",linebreak1);
	printf("|   Ajouter un nouveau produit                 |                [1]                     |\n");
	printf("%s",linebreak1);
 	printf("|   Acheter produit                            |                [2]                     |\n");
 	printf("%s",linebreak1);
  	printf("|   recherchparcode                            |                [3]                     |\n");
  	printf("%s",linebreak1);
   	printf("|   Etat du stock (>3)                         |                [4]                     |\n");
   	printf("%s",linebreak1);
	printf("|   Alimenter le stock                         |                [5]                     |\n");
	printf("%s",linebreak1);
  	printf("|   sortir du programme                        |                [6]                     |\n");	
	  printf("%s\n\n\n",linebreak1);	
    printf("mon choix:");
    scanf("%d",&n);
    
  	switch(n){
  	    
        case 1: 
       medicaments=ajouterproduit(tab,medicaments);
       
         break;
        case 2:
	    	acheterproduit( tab, medicaments);
	    	system("cls");
         break;
        case 3:
		 recherchparcode(tab,medicaments);
		 system("cls");
		 case 4:
		 recherchparquatite(tab,medicaments);
		 system("cls");
         break;
         case 5:
		 inferieur(tab,medicaments);
		 system("cls");
         break;
         case 6:
        alimenter(tab,medicaments);
        system("cls");
         break;
         case 7:
         for(i=0;i<medicaments-1;i++){
		for(j=i+1;j<medicaments;j++){
			if (strcasecmp(tab[j].nom,tab[i].nom)<0){
			tmp=tab[i];
			tab[i]=tab[j];
			tab[j]=tmp;
			}		
	      }	
	   } 
	   for(i=0;i<medicaments;i++){
		printf("|%d\t\t%s\t\t%s\t\t%.3f\t\t%.3f\t\t%d\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].prixTTC,tab[i].quantite);system("PAUSE");
	}	
         system("cls");
         break;
         case 8:
         for(i=0;i<medicaments;i++){
		for(j=i+1;j<=medicaments;j++){
			if(tab[j].prix>tab[i].prix){
			tmp=tab[i];
			tab[i]=tab[j];
			tab[j]=tmp	;
			}		
	      }	
	   } 
	   for(i=0;i<medicaments;i++){
		printf("|%d\t\t%s\t\t%s\t\t%.3f\t\t%.3f\t\t%d\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].prixTTC,tab[i].quantite);system("PAUSE");
	}	
         system("cls");
         break;
         case 9:
      medicaments=supp(tab,medicaments);
		break;
		case 10:
		printf("A bientot!");
		exit(0);
		break;
        default:
		printf("Erreur.\n");
		system("PAUSE");
    	break;} }
	return 0;
}

