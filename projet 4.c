#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*In this example, you will learn to print all prime numbers between two numbers (entered by the user).

To understand this example, you should have the knowledge of the following C programming topics:

C for Loop
C break and continue
C Functions
C User-defined functions*/
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
