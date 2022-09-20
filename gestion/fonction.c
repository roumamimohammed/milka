#include<stdio.h>
#include "fonction.h"

int ajouterproduit( medicament tab[1000],int medicaments){
	 char linebreak[130]="------------------------------------------------------------------------------------------------------------------------+";
        int i,j; 
        
        
   while(1){
     
                printf("(Pour terminer l'ajout veuillez saisir finich)\nVeuillez saisir le nom du medicament: ");
		     	fflush(stdin);
			    scanf("%s",tab[medicaments].nom);
			     if(strcmp(tab[medicaments].nom,"finich")==0){strcpy(tab[medicaments].nom,"");	printf("Ajout terminer\n");
				system("PAUSE");system("cls");break;}
		 for(i=0;i<medicaments;i++){
         if(strcmp(tab[i].nom,tab[medicaments].nom)==0){system("cls");
		     	printf("Un medicament ayant le meme nom '%s' existe deja dans la base de donnees.\n",tab[medicaments].nom);break;}}   
				 printf("Veuillez saisir le code bar du medicament: ");	
            	fflush(stdin);
				scanf("%s",tab[medicaments].codebar);
         for(i=0;i<medicaments;i++){
       		if(strcmp(tab[i].codebar,tab[medicaments].codebar)==0){system("cls");
			   printf("Un medicament ayant le meme code-bar '%s' existe deja dans la base de donnees.\n",tab[medicaments].codebar);break;}}	
       
		       printf("Veuillez saisir le prix du medicament (DH): ");
		       fflush(stdin);
			   scanf("%f",&tab[medicaments].prix);
            	if(tab[medicaments].prix<=0) printf("Erreur. Veuillez reessayer.\n");
             	tab[medicaments].prixTTC=	tab[medicaments].prix*1.15;
              	printf("Veuillez saisir la quantite de ce medicament: ");
             	fflush(stdin);
				scanf("%d",&tab[medicaments].quantite);
		if(tab[medicaments].quantite<=0) printf("Erreur. Veuillez reessayer.\n");
       	medicaments++;
       	system("cls");
	 
		   }	
    	

	return medicaments;
}
    	

	





void acheterproduit( medicament tab[1000],int medicaments){
	int quantite_a_acheter=-1,i;
	char identifiantduproduit[50];
		float totaldelacommande=0,sommedonnee=0,rendudelasommedonne=0;
        		
        	printf("Veuillez saisir le nom ou le code bar du medicament: ");
        	fflush(stdin);
        	scanf("%s",identifiantduproduit);
        	for(i=0;i<medicaments;i++){
        	if((strcmp(tab[i].nom,identifiantduproduit)==0||strcmp(tab[i].codebar,identifiantduproduit)==0)&&tab[i].quantite>0){
        	
			printf("Veuillez saisir la quantite du medicament %s (max=%d): ",tab[i].nom,tab[i].quantite);
             fflush(stdin);
             scanf("%d",&quantite_a_acheter);
		     if(quantite_a_acheter<1 || quantite_a_acheter>tab[i].quantite)printf("Erreur. Veuillez reessayer.\n");
		     else{
             totaldelacommande=quantite_a_acheter*tab[i].prix;
             tab[i].quantite-=quantite_a_acheter;
             printf("Saisir la somme donnee par le client: ");
		      fflush(stdin);scanf("%f",&sommedonnee);
             rendudelasommedonne=sommedonnee-totaldelacommande;
		    if(rendudelasommedonne<0)printf("Rendu negatif Reessayer: ");
		    else{
			
           time_t t; time(&t);
  	       char * time_str = ctime(&t);
    	   time_str[strlen(time_str)-1] = '\0';
		   char linebreak2[73]="+-------------------------------+--------------------+----------------+\n";
		printf("\n%s",linebreak2);
		printf("|  Bon de commande %51s|\n",time_str);
		printf("%s",linebreak2);
		printf("|Nom                            |Quantite            |Somme           |\n");
		printf("%s",linebreak2);
		printf("|%-31s|%-20d|%-16.2f|\n",tab[i].nom,quantite_a_acheter,quantite_a_acheter*tab[i].prix);
		printf("%s",linebreak2);
		printf("|TOTAL DE LA COMMANDE %48.2f|\n",totaldelacommande);
		printf("|ESPECES%62.2f|\n",sommedonnee);
		printf("|RENDU(ESPECES)%55.2f|\n",rendudelasommedonne);
		printf("%s",linebreak2);
			}
			}}else 
			printf("erreur dans le nom ou le code bare ou la qantite");
				system("PAUSE");system("cls");printf("(Pour annuler la commande taper annuler)\n");
	}

	
}
 void inferieur(medicament tab[1000],int medicaments){
	 char linebreak[73]="+-------------------------------+--------------------+----------------+\n";
	 int i;
	printf("\n  les medicaments dont le stock est inferieur a:%d ",3);
		system("cls");printf("%s",linebreak);
	    printf("|  Medicaments dont le stock est inferieur a: %-24d|\n",3);
        printf("%s",linebreak);
		printf("|Index  |Nom                  |CodeBar          |Prix       |Quantite |\n");
		printf("%s",linebreak);
		for(i=0;i<medicaments;i++){
	    if(tab[i].quantite<3 && tab[i].prix!=0)printf("|%-6d |%-20s |%-15s  |%-9.2f  |%-9d|\n",i ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].quantite);}
		printf("%s",linebreak);
        printf("\n");
        system("PAUSE");
       
	
}

void recherchparcode(medicament tab[1000],int medicaments){
	char identifiantduproduit[50];
	int i;
      	printf("Veuillez saisir la qantiter ou le code bar du medicament: ");
   		fflush(stdin);
        scanf("%s",identifiantduproduit);
        for(i=0;i<medicaments;i++){
       	if(strcmp(tab[i].codebar,identifiantduproduit)==0){
		   
	printf("|%d\t\t%s\t\t%s\t\t%.3f\t\t%.3f\t\t%d\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].prixTTC,tab[i].quantite);system("PAUSE");}
	else("code incorrect");
}}
void recherchparquatite(medicament tab[1000],int medicaments){
	int identifiantduproduit;
	int i;
      	printf("Veuillez saisir la qantiter ou le code bar du medicament: ");
   		fflush(stdin);
        scanf("%d",&identifiantduproduit);
        for(i=0;i<medicaments;i++){
       	if(tab[i].quantite==identifiantduproduit){
		   
	printf("|%d\t\t%s\t\t%s\t\t%.3f\t\t%.3f\t\t%d\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].prixTTC,tab[i].quantite);system("PAUSE");}
	else("incorrect");
}}

void alimenter(medicament tab[1000],int medicaments){
	char identifiantduproduit[50];
	int i;
	int quantite_a_acheter=-1;
      	printf("Veuillez saisir le nom ou le code bar du medicament: ");
   		fflush(stdin);
        scanf("%s",identifiantduproduit);
        for(i=0;i<medicaments;i++){
       	if(strcmp(tab[i].nom,identifiantduproduit)==0||strcmp(tab[i].codebar,identifiantduproduit)==0){
		   
		printf("Veuillez saisir la nouvelle quantite du medicament %s: ",tab[i].nom);
		fflush(stdin);
		scanf("%d",&quantite_a_acheter);
      	tab[i].quantite=quantite_a_acheter;
      }	printf("La nouvelle quantite du %s est %d \n",tab[i].nom,tab[i].quantite);system("PAUSE");}
}
int supp(medicament tab[1000],int medicaments){
	char identifiantduproduit[50];
	int i;
	printf("entrer le nom du produit que vous voulez supprimer:");
	fflush(stdin);
	scanf("%s",identifiantduproduit);
	 for(i=0;i<medicaments;i++){
       	if(strcmp(tab[i].nom,identifiantduproduit)==0||strcmp(tab[i].codebar,identifiantduproduit)==0){	   
	         tab[i]=tab[medicaments-1];
		medicaments--;
		printf("produit supprimer\n");system("PAUSE");}	}
    	printf("produit non trouvavle\n");system("PAUSE");
		return medicaments;
      }
	
	



