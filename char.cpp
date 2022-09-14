#include<stdio.h>
#include<stdlib.h>


int main(){

int  n , i ;
char *ptr ;

printf("enter size of element ");
scanf("%d",&n);
ptr = (char*)malloc(n * sizeof(char));
if(ptr == NULL){
    printf("memory empty");
    exit(0);
    }else{
        printf("enter an element :");
        for ( i = 0; i < n; i++)
        {
           scanf("%c",ptr + i);

        }}
        for( i = 0; i < n; i++){
        	printf("%s",*(ptr+i));
		}
        return 0;

}
