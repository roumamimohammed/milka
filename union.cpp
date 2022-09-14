#include <stdio.h>
#include <string.h>
union unionJob
{
   //defining a union
   char name[32];
   float salary;
   int workerNo;
} uJob;

typedef struct structJob
{
   char name[32];
   float salary;
   int workerNo;
} sJob;

int main()
{
	uJob test={3};

	uJob.salary = 12;
    uJob.workerNo = 100; 
   
   printf("Salary = %.1f\n", test.salary);
   printf("Number of workers = %d\n", test.workerNo);
  /*
   printf("size of union = %d bytes", sizeof(uJob));
   printf("\nsize of structure = %d bytes", sizeof(sJob));*/
   return 0;
}
