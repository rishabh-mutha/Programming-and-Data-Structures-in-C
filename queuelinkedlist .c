#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *nptr;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int x);
int dequeue();
void print();

void main()
{
int x,y;
label:
printf("to enqueue,press 1\nto dequeue,press 2\nto print,press 3\n");
scanf("%d",&x);
if(x==1)
{
printf("enter the element to be enqueued\n");
scanf("%d",&y);
enqueue(y);
}

else if(x==2)
printf("the element dequeued is %d\n",dequeue());

else if(x==3)
print();

goto label;
}

void enqueue(int x)
{
struct node *tmp=malloc(sizeof(struct node));
tmp->data=x;

if(front==NULL)
{tmp->nptr=NULL;
front=tmp;
rear=tmp;
}

else 
{
tmp->nptr=NULL;
rear->nptr=tmp;
rear=rear->nptr;
}

}

int dequeue()
{

if (rear==NULL)
{printf("error/cannot dequeue\n");
return -666;}
int x=front->data;
front=front->nptr;
return x;
}

void print()
{
if(front==NULL)
{printf("error; queue is empty\n"); return;}
struct node *thptr=front;
do
{
printf("%d ",thptr->data);
thptr=thptr->nptr;
}
while(thptr!=NULL);
printf("\n");
}
