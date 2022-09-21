#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonction.h"




int main(int argc, char *argv[]) {
	int	nomexiste,codebarexiste;	
	 medicament tab[1000],tabcopie[1000],tmp;
	char identifiantduproduit[50];
	char linebreak1[120]="               +----------------------------------------------+----------------------------------------+\n";
	char linebreak[130]="\n+-----------------------------------------------------------------------------------------------------------------------+\n";
    int n,j, i = 0,medicaments=0, autremedicament=1,quantite_a_acheter=0;
    float S=0,Q=0;
	float totaldelacommande=0,sommedonnee=0,rendudelasommedonne=0;
		while(1){	
		printf("%s",linebreak1);
		
    	printf("               |                                        MENU PRINCIPALE                                |\n");
		printf("%s",linebreak1);
		system("color B");
	printf("               |   Ajouter un nouveau produit                 |                [1]                     |\n");
	printf("%s",linebreak1);
	
 	printf("               |   Lister tous les produits alph              |                [2]                     |\n");
 	printf("%s",linebreak1);
  	printf("               |   Lister tous les produits prix              |                [3]                     |\n");
  	printf("%s",linebreak1);
   	printf("               |   Acheter produit                            |                [4]                     |\n");
   	printf("%s",linebreak1);
	printf("               |   Rechercher les produits Par code           |                [5]                     |\n");
	printf("%s",linebreak1);
  	printf("               |   Rechercher les produits Par quantite       |                [6]                     |\n");
	  printf("%s",linebreak1);
  	printf("               |   Etat du stock                              |                [7]                     |\n");
	  printf("%s",linebreak1);
  	printf("               |   Alimenter le stock                         |                [8]                     |\n");
	  printf("%s",linebreak1);
  	printf("               |   Supprimer les produits                     |                [9]                     |\n");
	  printf("%s",linebreak1);
  	printf("               |   Statistique de vente                       |                [10]                    |\n");
	  printf("%s",linebreak1);
  	printf("               |   sortir du programme                        |                [11]                    |\n");	
  	
	  printf("%s\n\n\n",linebreak1);	
    printf("mon choix:");
    scanf("%d",&n);
    
  	switch(n){
  	    system("color C");
        case 1: 
        system("cls");
       
 	 
       medicaments=ajouterproduit(tab,medicaments);
       system("cls");
         break;
         case 2:
         	system("cls");
         	printf("                       Lister tous les produits alpha                                                 \n\n\n");
         	printf("|Index\t\t|Nom\t\t|CodeBar\t\t|Prix\t\t|Quantite \n");
         	printf("%s",linebreak);
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
		printf("|%d\t\t%s\t\t%s\t\t\t%.3f\t\t%d\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].quantite);system("PAUSE");
	}	
         system("cls");
         break;
         case 3:
         	system("cls");
         	printf("                       Lister tous les produits prix                                                 \n\n\n");
         	printf("|Index\t\t|Nom\t\t|CodeBar\t\t|Prix\t\t|Quantite \n");
         	printf("%s",linebreak);
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
		printf("|%d\t\t%s\t\t%s\t\t\t%.3f\t\t%d\n\n\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].quantite);system("PAUSE");
	}	
         system("cls");
         break;
        case 4:
        	system("cls");
	    	tabcopie[medicaments]=acheterproduit( tab,tabcopie, medicaments);
	    	system("cls");
         break;
        case 5:
        	system("cls");
        	printf("                          Rechercher les produits Par code                             \n\n\n");
		 recherchparcode(tab,medicaments);
		 system("cls");
		 break;
		 case 6:
		 system("cls");
		 	printf("                          Rechercher les produits Par quantite                             \n\n\n");
		 recherchparquatite(tab,medicaments);
		 system("cls");
         break;
         case 7:
		 system("cls");
		  printf("                                    Etat du stock                                                   \n");
		 inferieur(tab,medicaments);
		 system("cls");
         break;
         case 8:
         	  
		 system("cls");
		 printf("                                     Alimenter le stock                                                   \n\n\n\n");
        alimenter(tab,medicaments);
        system("cls");
         break;
         case 9:
		 system("cls");
         system("color C");
         printf("                                     Supprimer les produits                                           \n\n\n\n");
         medicaments=supp(tab,medicaments);
		system("cls");
		 
			break;
         case 10:
         	system("cls");
         		printf("                                            Statistique de vente                                             \n\n\n");
         	S=statistique1(tabcopie,medicaments,S);
	    	Q=statistique2(tabcopie,medicaments,S,Q);
	    	
		break;
		case 11:
		printf("A bientot!");
		exit(0);
		break;
		
        default:
		printf("Erreur.\n");
		system("PAUSE");
		exit(0);
    	break;} }
	return 0;
}

