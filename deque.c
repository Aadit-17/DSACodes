#include<stdio.h>
#include<process.h>
#include<conio.h>
#define MAX 30
typedef struct double_ended_queue

{
    int data[MAX];
    int rear,front;
}double_ended_queue;

void initialize(double_ended_queue *p);
int empty(double_ended_queue *p);
int full(double_ended_queue *p);
void enqueueR(double_ended_queue *p,int x);
void enqueueF(double_ended_queue *p,int x);
int dequeueF(double_ended_queue *p);
int dequeueR(double_ended_queue *p);
void print(double_ended_queue *p);
void main()
{
    int i,x,op,n;
    double_ended_queue q;
    initialize(&q);
    do
    {
        printf("\n1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)");
        printf("\n5.Delete(front)\n6.Display\n7.Exit\nEnter your choice:");
        scanf("%d",&op);
        switch(op)
        {
            case 1: printf("\nEnter number of elements:");
            scanf("%d",&n);
            initialize(&q);
            printf("\nEnter the data:");
            for(i=0;i<n;i++)
            {
                scanf("%d",&x);
                if(full(&q))
                {
                    printf("\nQueue is full!!");
                    exit(0);
                }
                enqueueR(&q,x);
            }
            break;
            case 2: printf("\nEnter element to be inserted:");
            scanf("%d",&x);
            if(full(&q))
            {
                printf("\nQueue is full!!");
                exit(0);
            }
            enqueueR(&q,x);
            break;
            case 3: printf("\nEnter the element to be inserted:");
            scanf("%d",&x);
            if(full(&q))
            {
                printf("\nQueue is full!!");
                exit(0);
            }
            enqueueF(&q,x);
            break;
            case 4: if(empty(&q))
            {
                printf("\nQueue is empty!!");
                exit(0);
            }
            x=dequeueR(&q);
            printf("\nElement deleted is %d\n",x);
            break;
            case 5: if(empty(&q))
            {
                printf("\nQueue is empty!!");
                exit(0);
            }
            x=dequeueF(&q);
            printf("\nElement deleted is %d\n",x);
            break;
            case 6: print(&q);
            break;
            default: break;
        }
    }while(op!=7);
    getch();
}

void initialize(double_ended_queue *P)
{
    P->rear=-1;
    P->front=-1;
}

int empty(double_ended_queue *P)
{
    if(P->rear==-1)
    return(1);
    return(0);
}

int full(double_ended_queue *P)
{
    if((P->rear+1)%MAX==P->front)
    return(1);
    return(0);
}

void enqueueR(double_ended_queue *P,int x)
{
    if(empty(P))
    {
        P->rear=0;
        P->front=0;
        P->data[0]=x;
    }
    else
    {
        P->rear=(P->rear+1)%MAX;
        P->data[P->rear]=x;
    }
}

void enqueueF(double_ended_queue *P,int x)
{
    if(empty(P))
    {
        P->rear=0;
        P->front=0;
        P->data[0]=x;
    }
    else
    {
        P->front=(P->front-1+MAX)%MAX;
        P->data[P->front]=x;
    }
}

int dequeueF(double_ended_queue *P)
{
    int x;
    x=P->data[P->front];
    if(P->rear==P->front) //delete the last element
    initialize(P);
    else
    P->front=(P->front+1)%MAX;
    return(x);
}

int dequeueR(double_ended_queue *P)
{
    int x;
    x=P->data[P->rear];
    if(P->rear==P->front)
    initialize(P);
    else
    P->rear=(P->rear-1+MAX)%MAX;
    return(x);
}

void print(double_ended_queue *P)
{
    if(empty(P))
    {
        printf("\nQueue is empty!!");
        exit(0);
    }
    int i;
    i=P->front;
    while(i!=P->rear)
    {
        printf("\n%d",P->data[i]);
        i=(i+1)%MAX;
    }
    printf("\n%d\n",P->data[P->rear]);
}
