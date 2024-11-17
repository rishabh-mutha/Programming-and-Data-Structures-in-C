#include<stdio.h>

struct book
{
int accountnumber;
char booktitle[100];
char author[100];
};

struct library 
{
int top;
struct book b[100]; 	
};

void push(struct library *ps);
void print(struct library *ps);
void isfull(struct library *ps);
void isempty(struct library *ps);
void pop(struct library *ps);
void search(struct library *ps);

void main()
{
struct library l;
struct book b;
l.top=-1;
int x;
labelx:
	printf("to push a new book, press 1\n");
	printf("to pop a book, press 2\n");
     printf("to search an element, press 3\n");
     printf("to check isFull, press 4\n");
     printf("to check isEmpty, press 5\n");
     printf("to print the library, press 6\n");
     
     scanf("%d",&x);
	if (x==1) goto label1;
	else if (x==2) goto label2;
	else if (x==3) goto label3;
	else if (x==4) goto label4;
	else if (x==5) goto label5;
	else if (x==6) goto label6;


label1: push(&l); goto labelx;
label2: pop(&l); goto labelx;
label3: search(&l); goto labelx;
label4: isfull(&l); goto labelx;
label5: isempty(&l); goto labelx;
label6: print(&l); goto labelx;

/*
push(&l);
push(&l);

print(&l);
pop(&l);
print(&l);
isfull(&l);
isempty(&l);
*/
} 


void push(struct library *ps)
{
	if(ps->top==99)
		printf("library is full\n");
	else
	{ps->top=ps->top+1;
 	 printf("enter the account number\n");
	 scanf("%d",&ps->b[ps->top].accountnumber);

         printf("enter the book title\n");
         scanf("%s",ps->b[ps->top].booktitle);

	 printf("enter the author name\n");
         scanf("%s",ps->b[ps->top].author);
//ps->top=ps->top+1;
//ps->a[ps->top]=x;
	}

}

void print(struct library *ps)
{       
if(ps->top==-1)
		printf("library is empty\n");

	else 
        {int i;
	for(i=0;i<=ps->top;i++)

{
printf("book %d\n",i);
printf("acc no - %d\n",ps->b[i].accountnumber);
printf("book title - %s\n",ps->b[i].booktitle);
printf("author name - %s\n",ps->b[i].author);
printf("\n");
}

}
}

void isfull(struct library *ps)
{
	if(ps->top==99)
		printf("full\n");
	else 
		printf("not full\n");
}
void isempty(struct library *ps)
{
	if(ps->top==-1)
		printf("empty\n");
	else 
		printf("not empty\n");
}

void pop(struct library *ps)
{	        if(ps->top>-1)
		ps->top=ps->top-1;
	else printf("library is empty\n");
	
}

void search(struct library *ps)
{
if(ps->top==-1)
		{printf("library is empty\n"); return;}

int flag=0;
int x;
printf("enter the acc no of the book to be searched\n");
scanf("%d",&x);

int i;
	for(i=0;i<=ps->top;i++)

{
if (x==ps->b[i].accountnumber)

{
printf("book %d\n",i);
printf("acc no - %d\n",ps->b[i].accountnumber);
printf("book title - %s\n",ps->b[i].booktitle);
printf("author name - %s\n",ps->b[i].author);
printf("\n"); flag++;
}

}
if (flag==0) printf("not found\n"); 


}




	

