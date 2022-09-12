// Program to create a simple calculator
#include <stdio.h>
#include<math.h>
int main() {
    char operation;
    double n1, n2;

    printf("Enter an operator (+, -, *, /,s,c,t): ");
    scanf("%c", &operation);
    printf("Enter two operands: ");
    scanf("%lf %lf",&n1, &n2);

    switch(operation)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf",n1, n2, n1+n2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
            break;
        case 's':
            printf("sin(%.1lf) / sin(%.1lf)",sin(n1), sin(n2));
            break;
        case 'c':
            printf("cos(%.1lf) / cos(%.1lf)",cos(n1), cos(n2));
            break;
        case 't':
            printf("tan(%.1lf) / tan(%.1lf)",sin(n1)/cos(n1), sin(n2)/cos(n2));
            break;

        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}

