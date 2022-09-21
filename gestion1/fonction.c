#include<stdio.h>
#include "fonction.h"



float statistique1(medicament tabcopie[1000],int medicaments,float S){
	
	int i;
	for(i=0;i<medicaments;i++){
	   	S=S+(tabcopie[i].prixTTC*tabcopie[i].quantite);	
    }	printf("               le total des prix des produits vendus en journee courante:%f\n\n\n",S);
    
    	
	return S;
	
}
float statistique2(medicament tabcopie[1000],int medicaments,float S,float Q){
	
	int i,j;
	medicament tmp;
    	for(i=0;i<medicaments;i++){
    	Q=Q+tabcopie[i].quantite;
		}printf("               la moyenne des prix des produits vendus en journée courante:%f\n\n\n",S/Q);
		
		
	   
for(i=0;i<medicaments;i++){
		for(j=i+1;j<=medicaments;j++){
			if(tabcopie[j].prixTTC>tabcopie[i].prixTTC){
			tmp=tabcopie[i];
			tabcopie[i]=tabcopie[j];
			tabcopie[j]=tmp	;
			}		
	      }	
	   } 
	printf("               le Max des prix des produits vendus en journée courante:%f\n\n\n",tabcopie[0].prixTTC);
	printf("               le Min des prix des produits vendus en journée courante:%f\n\n\n",tabcopie[medicaments-1].prixTTC);
	return Q;
	
}
int ajouterproduit( medicament tab[1000],int medicaments){
	 char linebreak[130]="+-----------------------------------------------------------------------------------------------------------------------+";
        int i,j; 
        
        
   while(1){
      printf("                                             Ajouter un nouveau produit                                                      \n\n");
	
                printf("(Pour terminer l'ajout veuillez saisir finish)\n\n\nVeuillez saisir le nom du medicament: ");
		     	fflush(stdin);
			    scanf("%s",tab[medicaments].nom);
			     if(strcmp(tab[medicaments].nom,"finish")==0){strcpy(tab[medicaments].nom,"");	printf("Ajout terminer\n");
				system("PAUSE");system("cls");break;}
		 for(i=0;i<medicaments;i++){
         if(strcmp(tab[i].nom,tab[medicaments].nom)==0){system("cls");
		     	printf("\n\nUn medicament ayant le meme nom %s existe deja dans la base de donnees.\n",tab[medicaments].nom);break;}}   
				 printf("\n\nVeuillez saisir le code bar du medicament: ");	
            	fflush(stdin);
				scanf("%s",tab[medicaments].codebar);
         for(i=0;i<medicaments;i++){
       		if(strcmp(tab[i].codebar,tab[medicaments].codebar)==0){system("cls");
			   printf("\n\nUn medicament ayant le meme code-bar %s existe deja dans la base de donnees.\n",tab[medicaments].codebar);break;}}	
       
		       printf("\n\nVeuillez saisir le prix du medicament (DH): ");
		       fflush(stdin);
			   scanf("%f",&tab[medicaments].prix);
            	if(tab[medicaments].prix<=0) {printf("Erreur. Veuillez reessayer.\n");break;}
             	tab[medicaments].prixTTC=	tab[medicaments].prix*1.15;
              	printf("\n\nVeuillez saisir la quantite de ce medicament: ");
             	fflush(stdin);
				scanf("%d",&tab[medicaments].quantite);
		if(tab[medicaments].quantite<=0) printf("\n\nErreur. Veuillez reessayer.\n");
       	medicaments++;
       	system("cls");
	 
		   }	
    	

	return medicaments;
}
    	

	





medicament acheterproduit( medicament tab[1000],medicament tabcopie[1000],int medicaments){
	int quantite_a_acheter=-1,i;
	char identifiantduproduit[50];
		float totaldelacommande=0,sommedonnee=0,rendudelasommedonne=0;
        printf("                             Acheter produit                                                \n\n\n");

        	printf("Veuillez saisir le nom ou le code bar du medicament: ");
        	fflush(stdin);
        	scanf("%s",identifiantduproduit);
        	while(1){ 
        	for(i=0;i<medicaments;i++){
        	if((strcmp(tab[i].nom,identifiantduproduit)==0||strcmp(tab[i].codebar,identifiantduproduit)==0)&&tab[i].quantite>0){
        	strcpy(tabcopie[i].nom,identifiantduproduit);
        	
			printf("Veuillez saisir la quantite du medicament %s (max=%d): ",tab[i].nom,tab[i].quantite);
             fflush(stdin);
             scanf("%d",&quantite_a_acheter);
		     if(quantite_a_acheter<1 || quantite_a_acheter>tab[i].quantite){
			 printf("Erreur. Veuillez reessayer.\n");
			 system("PAUSE");system("cls");break;}
		     
		     	
             totaldelacommande=quantite_a_acheter*tab[i].prixTTC;
             
             printf("Saisir la somme donnee par le client: ");
		      fflush(stdin);scanf("%f",&sommedonnee);
             rendudelasommedonne=sommedonnee-totaldelacommande;
		    if(rendudelasommedonne<0){printf("Rendu negatif Reessayer:\n ");  system("PAUSE");system("cls"); break;}
		    tabcopie[i].quantite=quantite_a_acheter;
		     	tabcopie[i].prixTTC=tab[i].prixTTC;
			tab[i].quantite-=quantite_a_acheter;
          
		   char linebreak2[73]="+-------------------------------+--------------------+----------------+\n";
		printf("\n%s",linebreak2);
		printf("|  Bon de commande                                                    |\n");    
		printf("%s",linebreak2);
		printf("|Nom                            |Quantite            |Somme           |\n");
		printf("%s",linebreak2);
		printf("|%-31s|%-20d|%-16.2f|\n",tab[i].nom,quantite_a_acheter,quantite_a_acheter*tab[i].prixTTC);
		printf("%s",linebreak2);
		printf("|TOTAL DE LA COMMANDE %48.2f|\n",totaldelacommande);
		printf("|ESPECES%62.2f|\n",sommedonnee);
		printf("|RENDU(ESPECES)%55.2f|\n",rendudelasommedonne);
		printf("%s",linebreak2);
	
			}
			
				system("PAUSE");system("cls");
	}	
		break;break;}
return tabcopie[medicaments];
	
}
 void inferieur(medicament tab[1000],int medicaments){
	 char linebreak[180]="+-----------------------------------------------------------------------------------------+\n";
	 int i;
	printf("\n  les medicaments dont le stock est inferieur a:%d ",3);
		system("cls");printf("%s",linebreak);
	    printf("|  Medicaments dont le stock est inferieur a: %d\n",3);
        printf("%s",linebreak);
		printf("|Index     |       Nom        |          CodeBar     |        Prix              Quantite \n");
		printf("%s",linebreak);
		for(i=0;i<medicaments;i++){
	    if(tab[i].quantite<3 && tab[i].prix!=0)
		printf("|%d                %s                   %s                   %.2f                  %d\n",i ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].quantite);}
		printf("%s",linebreak);
        printf("\n");
        system("PAUSE");
       
	
}

void recherchparcode(medicament tab[1000],int medicaments){
	char identifiantduproduit[50];
	int i;
      	printf("Veuillez saisir le code bar du medicament: ");
   		fflush(stdin);
        scanf("%s",identifiantduproduit);
        printf("|Index\t\t|Nom\t\t|CodeBar\t\t|Prix\t\t|Quantite \n");
        for(i=0;i<medicaments;i++){
       	if(strcmp(tab[i].codebar,identifiantduproduit)==0){
		    
	printf("|%d\t\t|%s\t\t|%s\t\t\t|%.3f\t\t|%d\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].quantite);system("PAUSE");}
	else("code incorrect");
}}
void recherchparquatite(medicament tab[1000],int medicaments){
	int identifiantduproduit;
	int i;
	char linebreak[180]="+-----------------------------------------------------------------------------------------+\n";
      	printf("Veuillez saisir la qantiter  du medicament: ");
   		fflush(stdin);
        scanf("%d",&identifiantduproduit);
        	printf("|Index\t\t|Nom\t\t|CodeBar\t\t|Prix\t\t|Quantite \n");
		printf("%s",linebreak);
		
	
        for(i=0;i<medicaments;i++){
       	if(tab[i].quantite==identifiantduproduit){
		   	
	printf("|%d\t\t|%s\t\t|%s\t\t\t|%.3f\t\t|%d\n",i+1 ,tab[i].nom,tab[i].codebar,tab[i].prix,tab[i].quantite);system("PAUSE");}
	else("incorrect");
}}

void alimenter(medicament tab[1000],int medicaments){
	char identifiantduproduit[50];
	int i;
	char linebreak[130]="+-----------------------------------------------------------------------------------------------------------------------+";
      
	int quantite_a_acheter=-1;
	printf("%s",linebreak);
      	printf("               Veuillez saisir le nom ou le code bar du medicament: ");
      	printf("%s",linebreak);
   		fflush(stdin);
        scanf("%s",identifiantduproduit);
        for(i=0;i<medicaments;i++){
       	if(strcmp(tab[i].nom,identifiantduproduit)==0||strcmp(tab[i].codebar,identifiantduproduit)==0){
		   printf("%s",linebreak);
		printf("               Veuillez saisir la nouvelle quantite du medicament %s: ",tab[i].nom);
		printf("%s",linebreak);
		fflush(stdin);
		scanf("%d",&quantite_a_acheter);
      	tab[i].quantite=quantite_a_acheter;
      }printf("%s",linebreak);	printf("               La nouvelle quantite du %s est %d \n\n\n",tab[i].nom,tab[i].quantite);system("PAUSE");}
}
int supp(medicament tab[1000],int medicaments){
	char identifiantduproduit[50];
	int i;
	printf("               entrer le nom du produit que vous voulez supprimer:");
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
	
	



