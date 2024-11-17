#include<stdio.h>
#include<stdlib.h>

struct node
{
 int coefficient;
 int power;
 struct node *nptr;
};

//create empty list
struct node *hptr=NULL;

void insert(int pos,int x,int y);
int delete(int pos);
void printList();
int funcval(int x);

void main()
{
int r;
labelx:
printf("to insert a term, press 1\n");
printf("to delete a term, press 2\n");
printf("to print the polynomial, press 3\n");
printf("to return the value of the polynomial at a given point, press 4\n");
scanf("%d",&r);
if(r==1)
{printf("enter the position in which you wish to enter, coefficient, and exponent of x\n");
int pos,x,y;
scanf("%d %d %d",&pos,&x,&y);
insert(pos,x,y);
goto labelx;
}
if(r==2)
{printf("enter the position in which you wish to delete\n");
int pos1;
scanf("%d",&pos1);
printf("the deleted term is %d\n",delete(pos1));
goto labelx;
}
if(r==3)
{
printList();
goto labelx;
}

if(r==4)
{
int point;
printf("enter the value of x at which you wish to get the value of the function\n");
scanf("%d",&point);
printf("the value of the function at x=%d is %d\n",point,funcval(point));
goto labelx;
}



}


void insert(int pos,int x,int y)
{
 struct node *tmp = malloc(sizeof(struct node));
 tmp->coefficient=x;
 tmp->power=y;
 if(pos==1)
 {
    tmp->nptr=hptr;
    hptr=tmp;
 }   
 else
 {
   int i=1;
   struct node *thptr=hptr;
   while(i<pos-1) //loop breaks when i= pos-1
   {
    thptr=thptr->nptr;
    i++;
   }
   tmp->nptr=thptr->nptr;
   thptr->nptr=tmp;
 }
 
}

int delete(int pos)
{
 struct node *thptr=hptr;
 int i=1,x,y;
 if(pos==1)
 {
  x=hptr->coefficient;
  y=hptr->power;

  hptr=hptr->nptr;
 }
 else
 {
  while(i<pos-1)
  {
   thptr=thptr->nptr;
   i++;
  }
  x=(thptr->nptr)->coefficient;
  y=(thptr->nptr)->power;
  
  thptr->nptr=(thptr->nptr)->nptr;
 }
 return(x);
}

void printList()
{
 struct node *tmp=hptr;
 do 
 {
  printf("%dx^%d ",tmp->coefficient,tmp->power);
  tmp=tmp->nptr;
 }while(tmp!=NULL);
printf("\n"); 
}

int funcval(int x)
{
struct node *tmp=hptr;
int val=0;
int coefficient,power;
do
{
coefficient=tmp->coefficient;
power=tmp->power;
int term=coefficient;
for(int i=0; i<power; i++)
{
term=term*x; 
}

val = val + term;
tmp=tmp->nptr;

}
while(tmp!=NULL);
return val;
}






	
