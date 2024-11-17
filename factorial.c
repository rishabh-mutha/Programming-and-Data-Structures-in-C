#include<stdio.h>
void main()
{
int n;
printf("enter the number whose factorial is to be found\n");
scanf("%d",&n);
printf("the factorial of %d is %d\n",n,factorial(n));
}

int factorial(int x)
{
if(x==0) return 1;
else return factorial(x-1)*x;
}
