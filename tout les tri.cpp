#include <stdio.h>
#include <stdlib.h>
int tri2(int n,int *T){
int i,j,c;

for(j=1;j<=n;j++) 
    for(i=0;i<n-1;i++)
        if (*(T+i) > *(T+(i+1)) ) {
                 c =*(T+i) ;
            *(T+i) = *(T+(i+1));
           *(T+(i+1)) = c;
        }  
		
		}  
int tri1(int n,int *T){
	int i,j,c;
for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
        if ( *(T+i) > *(T+j) ) {
            c =*(T+i) ;
            *(T+i) = *(T+j);
           *(T+j) = c;
        }
}
int main(){
int *T;
int n,i;
    printf("bonjour entrer le size du tableau:");	
    scanf("%d",&n);
    T = (int *)calloc(n, sizeof(int));
    if(T==NULL){y
    	printf("memoire vide");
    	exit(0);
	}else{
		for(i=0;i<n;++i){
    printf("Enter number:%d\n",i+1);	
    scanf("%d",T+i);	
	}}
    tri2(n,T);	
     for(i=0;i<n;++i){
    printf("T[%d]=%d\n",i+1,*(T+i));	
	    }
 return 0;
}



