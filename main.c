#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int i,j,n,T[100];

     	printf("entrer le nombres des eleves: ");
	    char  in[255];
	    fgets(in,255,stdin);
	    sscanf(in,"%d",&n);
	    
	    

    //remplissage
	for(i=0;i<n;i++)
	{
		
		char input[255];
		printf("entrer la note d'eleve %d : ",i+1);
		renter:
		fgets(input,255,stdin);
		if( (sscanf(input,"%d",&T[i]) !=1) || ( T[i]<0  ||  T[i]>20) ){
			printf("erreur renter la note : ");
			goto renter;
		}
	}
	
	for(i=0;i<n;i++){
		printf("les notes sonts eleve:%d: %d\n",i+1,T[i]);
	}
	
	return 0;
}

