#include<stdio.h>
struct Passenger
{
int pnr;
char name[100];
int fare;
};

struct waitingListQueue
{
struct Passenger w[100];
int rear;
int front;
};
void enqueue(struct waitingListQueue *pw);
void dequeue(struct waitingListQueue *pw);
void print(struct waitingListQueue *pw);

void main()
{
struct waitingListQueue w;
struct Passenger p;
w.front=w.rear=-1;

int x;
labelx:
	printf("to enqueue a new passenger, press 1\n");
	printf("to dequeue a passenger, press 2\n");
    printf("to print the waiting list, press 3\n");
   
     scanf("%d",&x);
	if (x==1) goto label1;
	else if (x==2) goto label2;
	else if (x==3) goto label3;
	

label1: enqueue(&w); goto labelx;
label2: dequeue(&w); goto labelx;
label3: print(&w); goto labelx;


}

void enqueue(struct waitingListQueue *pw)
{
	if(pw->rear==99)
		printf("waiting list is full\n");
	else
	{
		pw->rear=pw->rear+1;
		printf("enter the pnr of new passenger\n");
        scanf("%d",&pw->w[pw->rear].pnr);
	    printf("enter the name of new passenger\n");
        scanf("%s",pw->w[pw->rear].name);
        printf("enter the fare of new passenger\n");
        scanf("%d",&pw->w[pw->rear].fare);
	}
	if(pw->rear==0)
	pw->front=0;
}

void dequeue(struct waitingListQueue *pw)
{
	if((pw->front==-1) || (pw->front>pw->rear))
		printf("waiting list is empty\n");
	else 
	{
    
    printf("ticket is confirmed for\n");
    printf("passenger pnr %d\n",pw->w[pw->front].pnr);
printf("passenger name %s\n",pw->w[pw->front].name);
printf("passenger fare %d\n",pw->w[pw->front].fare);             
printf("\n");
pw->front=pw->front+1;
}
}

void print(struct waitingListQueue *pw)
{printf("\n");
if((pw->front==-1) || (pw->front>pw->rear))
		printf("waiting list is empty\n");
else
for(int i=pw->front; i<=pw->rear; i++)
{
printf("passenger %d\n", i);
printf("pnr of passenger is %d\n",pw->w[i].pnr);
printf("name of passenger is %s\n",pw->w[i].name);
printf("fare of passenger is %d\n",pw->w[i].fare);
printf("\n");
}
printf("\n");
}




