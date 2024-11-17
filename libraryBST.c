#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Tnode
{
	char data[100];
	int accno;
	char author[100];
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};
struct Tnode *rptr=NULL;
void insert()
{
   
   char name [100];
        printf("enter the name of the book\n");
	scanf("%s",name);
	
	
	struct Tnode *tmp=malloc(sizeof(struct Tnode));
        strcpy(tmp->data,name);
	int acc;
	printf("enter the account number\n");
	scanf("%d",&acc);
	tmp->accno = acc;
	printf("enter the author name\n");
	scanf("%s",name);
	    strcpy(tmp->author,name);
	tmp->lcptr=NULL;
        tmp->rcptr=NULL;
   if(rptr==NULL)
	{	
		rptr=tmp;
	}
	else
	{
		struct Tnode *ptr=rptr;
		struct Tnode *pptr=NULL;
      while(ptr!=NULL)
		{
			pptr=ptr;
			
         if(strcmp(name,ptr->data)<0)
			{
				ptr=ptr->lcptr;	
			}
			else
			{
				ptr=ptr->rcptr;
			}
		}
		if(strcmp(name,pptr->data)<0)
			pptr->lcptr=tmp;
		else
			pptr->rcptr=tmp;	
	}	

}
void Inorder(struct Tnode *ptr)
{
if(rptr==NULL)
{printf("library is empty\n"); return;}



	if(ptr!=NULL)
	{
		Inorder(ptr->lcptr);
		printf("%30s%30d%30s\n",ptr->data,ptr->accno,ptr->author);
		Inorder(ptr->rcptr);
	}
}

void delete()
{
	if(rptr==NULL)
{printf("library is empty\n"); return;}
	char x[100];
        printf("enter the name of the book to be deleted\n");
	scanf("%s",x);
	
	
	char b[100];
   struct Tnode *ptmp=NULL;
	struct Tnode *ptr=rptr;
	struct Tnode *pptr=NULL;	
	while(ptr!=NULL && strcmp(ptr->data,x)!=0)
	{
		pptr=ptr;		
		if(strcmp(x,ptr->data)>=0)
			ptr=ptr->rcptr;	
		else 
			ptr=ptr->lcptr;
	}	
	if(ptr==NULL)
	{
		printf("\nDeletion Fails\n");
	}
	else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
	{
		strcpy(b,rptr->data);		
		rptr=NULL;	
	}
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL) //Case 1:Delete Leaf Node
	{
		strcpy(b,ptr->data);		
		if(strcmp(x,pptr->data)<0)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
	{
		strcpy(b,ptr->data);		
		if(strcmp(x,pptr->data)<0 && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if(strcmp(x,pptr->data)<0 && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(strcmp(x,pptr->data)>=0 && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;   
	}
	else
	{		
		struct Tnode *tmp=ptr;
      ptmp=tmp;		
		tmp=tmp->rcptr;
      
		while(tmp->lcptr!=NULL)
		{
         ptmp=tmp;
			tmp=tmp->lcptr;
		}
		strcpy(b,ptr->data);		
		strcpy(ptr->data,tmp->data);	
			

		//To delete suc node pointed to by tmp, and its parent is ptmp
      
       if(strcmp(tmp->data,ptmp->data)<0)
         ptmp->lcptr=tmp->rcptr;
       else
        ptmp->rcptr=tmp->rcptr;

	}


}

void search()
{
if(rptr==NULL)
{printf("library is empty\n"); return;}
char string[100];
printf("enter the name of the book to be searched\n");
scanf("%s",string);
struct Tnode *ptr=rptr;
while( strcmp(ptr->data,string)!=0 && ptr!=NULL)
{
if (strcmp(string,ptr->data)<0)  
{
if(ptr->lcptr!=NULL) 
ptr=ptr->lcptr;
else break;
}
else
{
if(ptr->rcptr!=NULL)
ptr=ptr->rcptr;
else break;
}
}
if(strcmp(ptr->data,string)==0)
{printf("book found\n");
printf("%s\n",ptr->data);}
else 
printf("book not found\n");


}

void main()
{
printf("This is a library management system\n\nTo insert a new book, press 1\nTo delete a book, press 2\nTo print the library, press 3\nTo search for a book,press 4\n\n");
   int x;
   label: printf("enter your choice\n");
   scanf("%d",&x);
     
    if (x==1) {printf("\n");insert();printf("\n");}
	else if (x==2) {printf("\n");delete();printf("\n");}
    else if (x==3) {printf("\n");
    if(rptr!=NULL)printf("                     Book Name                          accno                       author         \n\n");Inorder(rptr);printf("\n");}
    else if(x==4) {printf("\n");search();printf("\n");}
goto label;	
}
