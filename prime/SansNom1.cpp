#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime(int n);
int main() {
	int f;
	scanf("%d",&f);
    prime(f);
	return 0;
}

void prime(int n){
	int i,r=0;
	for(i=2;i<n;i++){
	 while((n%i)==0){
	  r=r+1;
	   i++;}
	}
	if(r>0)
	printf("no prime number");
	else
	   printf("prime number");
}
