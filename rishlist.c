#include <stdio.h>
struct List
{
	int a[20];
	int lsize;
};
void insert(struct List *pl,int pos, int x);
int del(struct List *pl,int pos);
void print(struct List pll);
int search(struct List *pl, int x);
int isFull(struct List l);
int isEmpty(struct List l);



void main()
{
	int x;   int position, value;
	struct List l;
	l.lsize=0;
	
	labelx:
	printf("to insert a new element, press 1\n");
	printf("to delete an element, press 2\n");
     printf("to search an element, press 3\n");
     printf("to check isFull, press 4\n");
     printf("to check isEmpty, press 5\n");
     printf("to print the list, press 6\n");
     
     scanf("%d",&x);
	if (x==1) goto label1;
	else if (x==2) goto label2;
	else if (x==3) goto label3;
	else if (x==4) goto label4;
	else if (x==5) goto label5;
	else if (x==6) goto label6;
	
	label1:printf("enter the position and value of the element to be inserted\n");
	scanf("%d %d",&position, &value);
	if(position<=l.lsize && position>=0)
	insert(&l,position,value);	
	else 
	{printf("invalid position. enter again\n");goto label1;}
     print(l);
	goto labelx;
	
	
	label2:
	if(l.lsize<=0)
	{printf("list is empty. please insert some elements first\n");
	goto labelx;}  
	printf("enter the position of the element to be deleted\n");
     scanf("%d",&position);
     if(position<=l.lsize && position>=0)
     printf("the deleted value is %d\n",del(&l,position));
     else 
     {printf("invalid position. enter again\n");goto label2;}
     print(l);
     goto labelx;

     label3: 
     if(l.lsize<=0)
	{printf("list is empty. please insert some elements first\n");
	goto labelx;}
     printf("enter the element to be searched\n");
     scanf("%d",&value);
     printf("%d\n",search(&l,value));
     goto labelx;


     label4: printf("%d\n",isFull(l));
     goto labelx; 
	
     
     label5: printf("%d\n",isEmpty(l));
     goto labelx;
     
     
     
	
	
	label6: 
	if(l.lsize<=0)
	{printf("list is empty. please insert some elements first\n");
	goto labelx;}
	print(l);
	goto labelx;
	/*
    	insert(&l,0,20);
    	insert(&l,1,10);
	insert(&l,1,40);
	insert(&l,1,50);
	insert(&l,1,60);
    	print(l);
	printf("the deleted value is %d\n",del(&l,0));
	print(l);
        printf("%d\n",search(&l,40));
	printf("%d",isEmpty(l));
	printf("\n%d",isFull(l));
	*/
	
	
}








void insert(struct List *pl,int pos, int x)
{
	int i;
	
	for(i=pl->lsize;i>=pos;i--)
		pl->a[i+1]=pl->a[i];
	pl->a[pos]=x;
	pl->lsize++;
}
void print(struct List pll)
{    printf("the list is\n"); 
     if (pll.lsize <=0)
     {printf("empty\n");return;}
	int j;
	for(j=0;j<pll.lsize;j++)
    	printf("%d\n",pll.a[j]);
     
}

int del(struct List *pl,int pos)
{
	int i,x=pl->a[pos];
	for(i=pos+1;i<pl->lsize;i++)
	{
		pl->a[i-1]=pl->a[i];
	}
	(pl->lsize)--;
	return(x);
		
}

int search(struct List *pl, int x)
{
	int i,pos=-1;
	
	for(i=0;i<pl->lsize;i++)
		if(pl->a[i]==x)
		{
			pos=i;			
			break;
		}
		if (pos==-1) { printf("element does not exist in the list\n");return(pos); }
	return(pos);
}

int isEmpty(struct List l)
{
	if(l.lsize==0)
 		return(1);
	else
		return(0);

}

int isFull(struct List l)
{
	if(l.lsize==20)
 		return(1);
	else
		return(0);

}

