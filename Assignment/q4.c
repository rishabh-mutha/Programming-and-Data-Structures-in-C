#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char name[20];
    int age;
    struct node* lptr;
    struct node* rptr;
    int height;
};

struct node* rtr=NULL;
int check=0;

int max(int h1,int h2)
{
    return h1>h2?h1:h2;
}

int height(struct node* temp)
{
    if(temp==NULL)
    {
        return 0; 
    }
    else
    {
        int h1=height(temp->lptr)+1;
        int h2=height(temp->rptr)+1;
        return max(h1,h2);
    }
}

void heightupdate(struct node* temp)
{
    temp->height=height(temp);
}

int balanceCheck(struct node* temp)
{
    return height(temp->lptr)-height(temp->rptr);
}

struct node* LeftRotate(struct node* temp)
{
    struct node* x=temp->rptr;
    struct node* y=x->lptr;

    temp->rptr=y;
    x->lptr=temp;

    heightupdate(temp);
    heightupdate(x);

    return x;
}

struct node* RightRotate(struct node* temp)
{
    struct node* x=temp->lptr;
    struct node* y=x->rptr;

    temp->lptr=y;
    x->rptr=temp;

    heightupdate(temp);
    heightupdate(x);

    return x;
}

struct node* insert(struct node* temp,char x[])
{
    if(temp==NULL)
    {
        temp=malloc(sizeof(struct node));
        strcpy(temp->name,x);
        printf("Enter the age of the passenger : ");
        scanf("%d",&temp->age);
        temp->lptr=NULL;
        temp->rptr=NULL;
        temp->height=1;
    }
    else
    {
        if(strcmp(x,temp->name)<0)
        {
            temp->lptr=insert(temp->lptr,x);
        }
        else
        {
            temp->rptr=insert(temp->rptr,x);
        }
    }
    heightupdate(temp);
    int balance=balanceCheck(temp);
    if(balance>1)
    {
        if(strcmp(x,temp->name)<0)
        {
            temp=RightRotate(temp);
        }
        else
        {
            temp->lptr=LeftRotate(temp->lptr);
            temp=RightRotate(temp);
        }
    }
    else if(balance<-1)
    {
        if(strcmp(x,temp->name)>0)
        {
            temp=LeftRotate(temp);
        }
        else
        {
            temp->rptr=RightRotate(temp->rptr);
            temp=LeftRotate(temp);
        }
    }
    return temp;
}

void print(struct node* temp)
{
    if(temp!=NULL)
    {
        printf("%s ",temp->name);
        print(temp->lptr);
        print(temp->rptr);
    }
}

void search(struct node* temp,char x[])
{
    if(temp!=NULL)
    {
        if(strcmp(temp->name,x)==0)
        {
            printf("Element found\n");
            check=1;
        }
        print(temp->lptr);
        print(temp->rptr);
    }
}

struct node* loop_check(struct node* temp,char x[])
{
    if(temp==NULL)
    {
        return NULL;
    }
    else
    {
        heightupdate(temp);
        temp->lptr=loop_check(temp->lptr,x);
        temp->rptr=loop_check(temp->rptr,x);
    }
    int balance=balanceCheck(temp);
    if(balance>1)
    {
        if(strcmp(x,temp->name)>0)
        {
            temp=RightRotate(temp);
        }
        else
        {
            temp->lptr=LeftRotate(temp->lptr);
            temp=RightRotate(temp);
        }
    }
    else if(balance<-1)
    {
        if(strcmp(x,temp->name)<0)
        {
            temp=LeftRotate(temp);
        }
        else
        {
            temp->rptr=RightRotate(temp->rptr);
            temp=LeftRotate(temp);
        }
    }
    return temp;
}

void delete(char x[])
{
    struct node* temp=rtr;
    struct node* temp1=rtr;
    while(temp!=NULL&&strcmp(temp->name,x)!=0)
    {
        temp1=temp;
        if(strcmp(temp->name,x)>0)
        {
            temp=temp->lptr;
        }
        else
        {
            temp=temp->rptr;
        }
    }
    if(temp==NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        if(temp==rtr)
        {
            if(temp->lptr==NULL&&temp->rptr==NULL)
            {
                rtr=NULL;
            }
            else if(temp->lptr==NULL)
            {
                struct node* loop=rtr->rptr;
                struct node* loop1=rtr;
                while(loop->lptr!=NULL)
                {
                    loop1=loop;
                    loop=loop->lptr;
                }
                strcpy(temp->name,loop->name);
                temp->age=loop->age;
                if(loop1==rtr)
                {
                    loop1->rptr=NULL;
                }
                else
                {
                    loop1->lptr=NULL;
                }
            }
            else if(temp->rptr==NULL)
            {
                struct node* loop=rtr->lptr;
                struct node* loop1=rtr;
                while(loop->rptr!=NULL)
                {
                    loop1=loop;
                    loop=loop->rptr;
                }
                strcpy(temp->name,loop->name);
                temp->age=loop->age;
                if(loop1==rtr)
                {
                    loop1->lptr=NULL;
                }
                else
                {
                    loop1->rptr=NULL;
                }
            }
            else
            {
                struct node* loop=rtr->rptr;
                struct node* loop1=rtr;
                while(loop->lptr!=NULL)
                {
                    loop1=loop;
                    loop=loop->lptr;
                }
                strcpy(temp->name,loop->name);
                temp->age=loop->age;
                if(loop1==rtr)
                {
                    loop1->rptr=NULL;
                }
                else
                {
                    loop1->lptr=NULL;
                }
            }
        }
        else if(temp->lptr==NULL&&temp->rptr==NULL)
        {
            if(strcmp(temp1->name,temp->name)>0)
            {
                temp1->lptr=NULL;
            }
            else
            {
                temp1->rptr=NULL;
            }
        }
        else if(temp->lptr==NULL)
        {
            if(strcmp(temp1->name,temp->name)>0)
            {
                temp1->lptr=temp->rptr;
            }
            else
            {
                temp1->rptr=temp->rptr;
            }
        }
        else if(temp->rptr==NULL)
        {
            if(strcmp(temp1->name,temp->name)>0)
            {
                temp1->lptr=temp->lptr;
            }
            else
            {
                temp1->rptr=temp->lptr;
            }
        }
        else 
        {
            struct node* loop=temp->rptr;
            struct node* loop1=temp;
            while(loop->lptr!=NULL)
            {
                loop1=loop;
                loop=loop->lptr;
            }
            strcpy(temp->name,loop->name);
            temp->age=loop->age;
            if(loop1==temp)
            {
                loop1->rptr=NULL;
            }
            else
            {
                loop1->lptr=NULL;
            }
        }
    }
    rtr = loop_check(rtr,x);
}

void main()
{
    int loop=1;
    char passenger[20];
    char y[20];
    while(loop)
    {
        printf("Consider the following operations to be done :\n1 : Book a Ticket\n2 : Cancelation\n3 : Search for Details\n4 : Print\n5 : Quit\n");
        int value;
        scanf("%d",&value);
        switch(value)
        {
            case 1:
                printf("Enter the passenger name : ");
                scanf("%s",passenger);
                rtr=insert(rtr,passenger);
                break;
            case 2:
                printf("Enter the name to be deleted : ");
                scanf("%s",y);
                delete(y);
                break;
            case 3:
                printf("Enter the name to search : ");
                scanf("%s",y);
                check=0;
                search(rtr,y);
                if(!check)
                {
                    printf("Element Not Found\n");
                }
                break;
            case 4:
                printf("The preorder traversal of the tickets is  : \n");
                print(rtr);
                printf("\n");
                break;
            case 5:
                loop=0;
        }
    }
return 0;
}
