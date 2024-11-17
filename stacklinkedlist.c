#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *nptr;
};

struct node *top=NULL;

void push(int x);
int pop();
void print();

void main()
{
int x,y;
label:
printf("to push,press 1\nto pop,press 2\nto print,press 3\n");
scanf("%d",&x);
if(x==1)
{
printf("enter the element to be pushed\n");
scanf("%d",&y);
push(y);
}

else if(x==2)
printf("the element popped is %d\n",pop());

else if(x==3)
print();

goto label;
}

void push(int x)
{
struct node *tmp=malloc(sizeof(struct node));
tmp->data=x;

tmp->nptr=top;
top=tmp;
}

int pop()
{

if (top==NULL)
{printf("error/cannot pop\n");
return -666;}
int x=top->data;
top=top->nptr;
return x;
}

void print()
{
struct node *thptr=top;
do
{
printf("%d ",thptr->data);
thptr=thptr->nptr;
}
while(thptr!=NULL);
printf("\n");
}
