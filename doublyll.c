#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct node
{
    struct node *prev;
    char n[100];
    struct node *next;
}*h,*temp,*temp1,*temp2,*temp4,*temp5;
 
void insert1();
void insert2();
void insert3();
void delete();
void play(); 
void playlist();
void printnext();
void printprevious();
int count = 0;
 
void main()
{
    int ch;
 
    h = NULL;
    temp = temp1 = temp5 = NULL;
 
    while (1)
    {
    printf("1 - Insert a song at beginning\n");
    printf("2 - Insert a song at end\n");
    printf("3 - Insert a song at position i\n");
    printf("4 - Delete a song\n");
    printf("5 - to show playlist\n");
    printf("6 - play a song\n");
    printf("7 - play next song\n");
    printf("8 - play previous song\n\n");
    printf("Enter choice :\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert1();
            break;
        case 2:
            insert2();
            break;
        case 3:
            insert3();
            break;
        case 4:
            delete();
            break;
        case 5:
            playlist();
            break;
        case 6:
            play();
            break;
        case 7:
            printnext();
            break;
        case 8:
            printprevious();
            break;
        }
    }
}
 

void create()
{ 
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("Enter name of the song:\n");
    scanf("%s", temp->n);
    count++;
}
 

void insert1()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
 

void insert2()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
 
void insert3()
{
    int pos, i = 2;
 
    printf("Enter position to be inserted : \n");
    scanf("%d", &pos);
    temp2 = h;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("Position out of range to insert\n ");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("Empty list cannot insert other than 1st position\n ");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create();
        h = temp;
        temp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}
 

void delete()
{
    int i = 1, pos;
 
    printf("Enter position to be deleted : \n");
    scanf("%d", &pos);
    temp2 = h;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("Error : Position out of range to delete\n");
        return;
    }
    if (h == NULL)
    {
        printf("Error : Empty list no elements to delete\n");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("Node deleted from list\n");
                free(temp2);
                temp2 = h = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("Node deleted from list\n");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;    
        if (i == 1)
            h = temp2->next;
        printf("Node deleted\n");
        free(temp2);
    }
    count--;
}


void playlist()
{
    temp2 = h;
 
    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("playlist is :\n");
 
    while (temp2->next != NULL)
    {
        printf("__%s__\n", temp2->n);
        temp2 = temp2->next;
    }
    printf("__%s__\n", temp2->n);
    printf("\n\n");
}

void play()
{
    char data[100]; count = 0;
    temp2 = h;
 
    if (temp2 == NULL)
    {
        printf("Error : List empty to search for data\n");
        return;
    }
    printf("Enter name of the song to play :\n");
    scanf("%s", data);
    while (temp2 != NULL)
    {
        if (!strcmp(temp2->n,data))
        {   temp5=temp2;
            printf("\n_____%s_____\n\n",temp2->n);
            return;
        }
        else
             temp2 = temp2->next;
            count++;
    }
    printf("Error : %s not found in list\n", data);
}


void printnext()
{
if(temp5==NULL)
{printf("not possible\n\n");
return;
}
temp5=temp5->next;
if(temp5==NULL)
{printf("not possible\n\n");
return;
}

printf("\n_____%s_____\n\n",temp5->n);
 }

void printprevious()
{
if(temp5==NULL)
{printf("not possible\n\n");
return;}

temp5=temp5->prev;

if(temp5==NULL)
{printf("not possible\n\n");
return;}

printf("\n_____%s_____\n\n",temp5->n);
 }

