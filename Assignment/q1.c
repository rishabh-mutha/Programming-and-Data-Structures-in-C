#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *nptr;
};

struct node* hptr1=NULL;
struct node* hptr2=NULL;
struct node* hptr3=NULL;
struct node* summing=NULL;



void sum(struct node *temp,struct node *temp1)
{
    int carry=0;
    while(temp!=NULL)
    {
        int x=0;
        if(temp1!=NULL)
        {
            x+=temp1->data;
        }
        x+=temp->data+carry;
        struct node *tmp=malloc(sizeof(struct node));
        if(temp->nptr==NULL)
        {
            tmp->data=x;
        }
        else
        {
            tmp->data=x%10;
        }
        carry=x/10;
        if(hptr3==NULL)
        {
            hptr3=tmp;
            tmp->nptr=NULL;
        }
        else
        {
            tmp->nptr=hptr3;
            hptr3=tmp;
        }
        temp=temp->nptr;
        if(temp1!=NULL)
        {
            temp1=temp1->nptr;
        }
    }
}

void subtract(struct node *temp,struct node *temp1)
{
    int borrow=0;
    while(temp!=NULL)
    {
        int x=0;
        if(temp1!=NULL)
        {
            x=temp->data-temp1->data-borrow;
        }
        else
        {
            x=temp->data-borrow;
        }
        if(x<0)
        {
            x+=10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        struct node *tmp=malloc(sizeof(struct node));
        tmp->data=x;
        if(hptr3==NULL)
        {
            hptr3=tmp;
            tmp->nptr=NULL;
        }
        else
        {
            tmp->nptr=hptr3;
            hptr3=tmp;
        }
         if(temp->nptr==NULL && borrow)
        {
            struct node* rtr=hptr3;
            while(rtr!=NULL)
            {
                if(rtr->nptr==NULL)
                {
                    rtr->data=9-rtr->data+1;
                }
                else if(rtr==hptr3)
                {
                    rtr->data=rtr->data-9;
                }
                else
                {
                    rtr->data=9-rtr->data;
                }
                rtr=rtr->nptr;
            }
        }
        temp=temp->nptr;
        if(temp1!=NULL)
        {
            temp1=temp1->nptr;
        }
    }
}
void subtract1(struct node *temp,struct node *temp1)
{ struct node *s=temp,*q;
struct node *mem1=temp;
struct node *mem2=temp1;
int carry=1;int s1=0,s2=0;

   
    while(s!=NULL)
       { s1++;
        s=s->nptr;
       }
       s=temp1;
         while(s!=NULL)
       { s2++;q=s;
        s=s->nptr;
       }

       for(int i=0;i<s1-s2;i++)
       {
             struct node *a=malloc(sizeof(struct node));
             a->data=0;
             q->nptr=a;
             q=a;

       }
       s=temp1;int g=0;
       while(s!=NULL)
       {
        s->data=9-s->data;
        printf("%d",s->data );
        if(s->data==9)
            g=1;
        s=s->nptr;
        
       }
       s=temp;printf("\n");
         while(s!=NULL)
       {
        
        printf("%d",s->data );
        s=s->nptr;

       }printf("\n");


temp=mem1;
temp1=mem2;
    while(temp!=NULL)
    {
        int x=0;
        if(temp1!=NULL)
        {
            x+=temp1->data;
        }
        x+=temp->data+carry;
        struct node *tmp=malloc(sizeof(struct node));
        if(temp->nptr==NULL)
        {
            tmp->data=x;
        }
        else
        {
            tmp->data=x%10;
        }
        carry=x/10;
        if(hptr3==NULL)
        {
            hptr3=tmp;
            tmp->nptr=NULL;
        }
        else
        {
            tmp->nptr=hptr3;
            hptr3=tmp;
        }
        temp=temp->nptr;
        if(temp1!=NULL)
        {
            temp1=temp1->nptr;
        }
    }
     struct node *z=hptr3;
      

 while(z!=NULL)
    
       
    {
        printf("%d",z->data);
        z=z->nptr;
    }
    
    {
        printf("\n");
    }
       
}
void print(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d",temp->data);
        print(temp->nptr);
    }
    else
    {
        printf("\n");
    }
    
}
int main()
{
   
    //print(hptr1);
    //print(hptr2);
    int loop=1;
    while(loop)
    { printf("Enter the two numbers to perform arithemetic operations\n");
    char x[30],y[30];
    printf("Enter number 1 : ");
    scanf("%s",x);
    printf("Enter number 2 : ");
    scanf("%s",y);
    for(int i=0;i<strlen(x);i++)
    {
        struct node* temp=malloc(sizeof(struct node));
        temp->data=x[i]-48;
        if(hptr1==NULL)
        {
            hptr1=temp;
            temp->nptr=NULL;
        }
        else
        {
            temp->nptr=hptr1;
            hptr1=temp;
        }
    }
    for(int i=0;i<strlen(y);i++)
    {
        struct node* temp=malloc(sizeof(struct node));
        temp->data=y[i]-48;
        if(hptr2==NULL)
        {
            hptr2=temp;
            temp->nptr=NULL;
        }
        else
        {
            temp->nptr=hptr2;
            hptr2=temp;
        }
    }
        printf("Enter the following operations to be done :\n1 : Addition\n2 : Subtraction\n3 : Increment\n4 : Decrement\n");
        int value;
        scanf("%d",&value);
        switch(value)
        {
            case 1 :
                printf("The sum of two numbers is : \n");
                if(strlen(x)>=strlen(y))
                {
                    sum(hptr1,hptr2);
                }
                else
                {
                    sum(hptr2,hptr1);
                }
                print(hptr3);
                hptr3=NULL;
                break;
            case 2 :
                printf("The subtraction of two numbers is : \n");
                if(strlen(x)>=strlen(y))
                {
                    subtract(hptr1,hptr2);
                }
                else
                {
                    subtract(hptr2,hptr1);
                    printf("-");
                }
                print(hptr3);
                hptr3=NULL;
                break;
            case 3 :
                summing=malloc(sizeof(struct node));
                summing->nptr=NULL;
                summing->data=1;
                sum(hptr1,summing);
                printf("The increment value of number 1 is :");
                print(hptr3);
                hptr3=NULL;
                printf("The increment value of number 2 is :");
                sum(hptr2,summing);
                print(hptr3);
                hptr3=NULL;
                break;
            case 4 :
                summing=malloc(sizeof(struct node));
                summing->nptr=NULL;
                summing->data=1;
                subtract(hptr1,summing);
                printf("The decrement value of number 1 is : ");
                print(hptr3);
                hptr3=NULL;
                printf("The decrement value of number 2 is : ");
                subtract(hptr2,summing);
                print(hptr3);
                hptr3=NULL;
                break;
            default:
                loop=0;
        }
    }
}