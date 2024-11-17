#include<stdio.h>
int n=3;
struct Cqueue
{
int a[3];
int front;
int rear;
};

void enqueue(struct Cqueue *pq,int x);
int dequeue(struct Cqueue *pq);
void isfull(struct Cqueue *pq);
void isempty(struct Cqueue *pq);
void print(struct Cqueue *pq);

void main()
{
struct Cqueue pq;
pq.front=-1;
pq.rear=-1;
int x,y;
labelx:
printf("to enqueue, press 1\nto dequeue, press 2\nto check isfull, press 3\nto check isempty, press 4\nto print the queue, press 5\n");
scanf("%d",&x);
switch(x)
{
case 1:{printf("enter the element to be enqueued\n");
scanf("%d",&y);
enqueue(&pq,y);
break;}

case 2:
{printf("%d\n",dequeue(&pq));
break;
}
case 3:
{isfull(&pq);
break;}

case 4:
{isempty(&pq);
break;}

case 5:
{print(&pq);
break;}


}

goto labelx;
}

void enqueue(struct Cqueue *pq,int x)
{
if ((pq->rear+1)%n==pq->front)
printf("Queue is full\n");

else if(pq->front==-1)
{
pq->front=0;
pq->rear=0;
pq->a[pq->rear]=x;
} 

else
{
pq->rear=(pq->rear+1)%n;
pq->a[pq->rear]=x;
}

}


int dequeue(struct Cqueue *pq)
{
if(pq->rear==-1)
return -666;

else if(pq->front==pq->rear)
{
int x=pq->a[pq->front];
pq->front=-1;
pq->rear=-1;
return x;
}

else 
{
int x=pq->a[pq->front];
pq->front=(pq->front+1)%n;
return x;
}

}

void isfull(struct Cqueue *pq)
{
if ((pq->rear+1)%n==pq->front)
printf("Queue is full\n");
else 
printf("Queue is not full\n");
}

void isempty(struct Cqueue *pq)
{
if ((pq->rear)==-1)
printf("Queue is empty\n");
else 
printf("Queue is not empty\n");
}


void print(struct Cqueue *pq)
{
if ((pq->rear)==-1)
{printf("Queue is empty\n");
return;}
int i;
printf("the circular queue is\n");

if(pq->rear>=pq->front)
{
for(int i=pq->front;i<=pq->rear;i++)
printf("%d\n",pq->a[i]);
}
else 
{
for(int i=pq->front; i<n; i++)
printf("%d\n",pq->a[i]);

for(int i=0; i<=pq->rear; i++)
printf("%d\n",pq->a[i]);

}


}






