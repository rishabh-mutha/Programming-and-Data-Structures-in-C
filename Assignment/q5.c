#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *nptr;
};

struct node *hptr1=NULL;
struct node *hptr2=NULL;

void print(struct node *temp,int x)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        print(temp->nptr,x);
    }
    else if(!x)
    {
        printf("\n");
    }
}

int check=0;

void checking(struct node* temp , int value)
{
    if(temp!=NULL)
    {
        if(value==temp->data)
        {
            check=1;
        }
        checking(temp->nptr,value);
    }
}

void unionn()
{
    print(hptr1,1);
    struct node* temp=hptr2;
    while(temp!=NULL)
    {
        check=0;
        checking(hptr1,temp->data);
        if(!check)
        {
            printf("%d ",temp->data);
        }
        temp=temp->nptr;
    }
    printf("\n");
}

void intersection()
{
    struct node* temp=hptr2;
    while(temp!=NULL)
    {
        check=0;
        checking(hptr1,temp->data);
        if(check)
        {
            printf("%d ",temp->data);
        }
        temp=temp->nptr;
    }
    printf("\n");
}

void complement(struct node *temp,struct node *temp1)
{
    while(temp!=NULL)
    {
        check=0;
        checking(temp1,temp->data);
        if(!check)
        {
            printf("%d ",temp->data);
        }
        temp=temp->nptr;
    }
    printf("\n");
}

int main()
{
    printf("Enter the elements for set 1 with spaces : \n");
    char c;
    do
    {
        struct node *temp=malloc(sizeof(struct node));
        struct node *temp1=hptr1;
        struct node *temp2=hptr1;
        scanf("%d%c",&temp->data,&c);
        temp->nptr=NULL;
        if(hptr1==NULL)
        {
            hptr1=temp;
        }
        else
        {
            int check=0;
            while(temp1!=NULL)
            {
                temp2=temp1;
                if(temp1->data==temp->data)
                {
                    check=1;
                }
                temp1=temp1->nptr;
            }
            if(!check)
            {
                temp2->nptr=temp;
            }
        }
    }while(c!='\n');
    printf("Enter the elememts in set 2 with spaces : \n");
    do
    {
        struct node *temp=malloc(sizeof(struct node));
        struct node *temp1=hptr2;
        struct node *temp2=hptr2;
        scanf("%d%c",&temp->data,&c);
        temp->nptr=NULL;
        if(hptr2==NULL)
        {
            hptr2=temp;
        }
        else
        {
            int check=0;
            while(temp1!=NULL)
            {
                temp2=temp1;
                if(temp1->data==temp->data)
                {
                    check=1;  
                }
                temp1=temp1->nptr;
            }
            if(!check)
            {
                temp2->nptr=temp;
            }
        }
    }while(c!='\n');
    
    printf("The elements in set 1 are : \n");
    print(hptr1,0);
    printf("The elements in set 2 are : \n");
    print(hptr2,0);
    printf("The Union of the two sets is : \n");
    unionn();
    printf("The intersection of the two sets is : \n");
    intersection();
    printf("The complement of set 1 wrt set 2 :\n");
    complement(hptr2,hptr1);
    printf("The complement of set 2 wrt set 1 :\n");
    complement(hptr1,hptr2);
}