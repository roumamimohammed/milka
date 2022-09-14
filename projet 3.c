#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop
Write a C program to get the indices of the two numbers of a given array of integers, such that the sum of the two numbers equal to a specific target. Go to the editor
Expected Output:

Original Array: 4  2  1  5  
Target Value: 7
Indices of the two numbers whose sum equal to target value: 7
1 3 */

int main() {
	char a;
	double n1,n2;

    scanf("%lf ",&n1);
	scanf("%c",&a);
    scanf("%lf",&n2);

     switch(a){
	 case '+' :
	 	printf("la valeur est: %lf",n1+n2);
	 	 break;
	 case '-':
	 	printf("la valeur est: %lf",n1-n2);
	 	 break;
	 case '*':
	 	printf("la valeur est: %lf",n1*n2);
	 	 break;
	case '/':
	 	printf("la valeur est: %.2lf",n1/n2);
	 	 break;
   	case '^':
	 	printf("la valeur est: %lf",pow(n1,n2));
	 	 break;
    case 's':
	 	printf("la valeur de sin n1 est: %lf\n",sin(n1));
	 	printf("la valeur  sin n2 est : %lf",sin(n2));
	 	 break;
    case 's':
	 	printf("la valeur de sin n1 est: %lf\n",sin(n1));
	 	printf("la valeur  sin n2 est : %lf",sin(n2));
	 	 break;
	default:
         printf("Error! operator is not correct");
	 
	 
	 }
	return 0;
}
