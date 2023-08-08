#include<stdio.h>
#include<stdlib.h>
struct Node
{
     int data;
     struct Node *next;
}*first=NULL;
void create(int arr[], int sz)
{
     struct Node *t,*last=NULL;
     int i;
     first=(struct Node*)malloc(sizeof(struct Node));
     first->data=arr[0];
     first->next=first;
     last=first;
     for(i=1;i<sz;i++)
     {
         t=(struct Node*)malloc(sizeof(struct Node));
         t->data=arr[i];
         t->next=last->next;
         last->next=t;
         last=t;
     }
}
int length_CLL(struct Node*p)
{
     int len = 0;
     do
     {
         len++;
         p=p->next;
     }
     while(p!=first);
     return len;
}
void insert_begin(struct Node *p, int x)
{
     struct Node *t;
     t = (struct Node*)malloc(sizeof(struct Node));
     t->data = x;
     if(first==NULL)
     {
         first = t;;
         first->next=first;
     }
     else
     {
         while(p->next!=first)
         p=p->next;
         p->next=t;
         t->next = first;
         first=t;
     }
}
void insert_end(struct Node *p, int x)
{
     struct Node *t, *q;
     t = (struct Node *)malloc(sizeof(struct Node));
     t->data = x;
     q = first;
     while(q->next != first)
     {
        q = q->next;
     }
     q->next = t;
     t->next = first;
}
void delete_begin(struct Node *p)
{
     int x;
     while(p->next!=first)
     {
        p = p->next;
     }
     x=first->data;
     if(first==p)
     {
         free(first);
         first = NULL;
     }
     else
     {
         p->next = first->next;
         free(first);
         first = p->next;
     }
     printf("Element deleted is %d.\n", x);
}
void delete_end( struct Node *p)
{
     struct Node *t, *q;
     int x;
     if (first ->next == first)
     {
         x=first->data;
         first = NULL;
         free(first);
     }
     else
     {
         t = first;
         while(t ->next != first)
         {
             q=t;
             t = t->next;
         }
         x=t->data;
         q->next = t -> next;
         free(t);
     }
     printf("Element deleted is %d.\n", x);
}
void display(struct Node*p)
{
     do
     {
         printf("%d ", p->data);
         p=p->next;
     }
     while(p!=first);
     printf("\n");
}
int main()
{
     int n,i,x,pos,err=0;
     printf("Enter no. of elements: ");
     scanf("%d", &n);
     int A[n];
     for(i=0;i<n;i++)
     {
         printf("Enter element %d: ", i+1);
         scanf("%d",&A[i]);
     }
     create(A,n);
     printf("Select your choice: "
     "\n\t1.\tInsertion at the beginning of the list"
     "\n\t2.\tInsertion at the end of the list"
     "\n\t3.\tDeletion at the beginning of the list"
     "\n\t4.\tDeletion at the end of the list"
     "\n\t5.\tDisplay list"
     "\n\t6.\tStop and exit\n");
     int ch=0;
     do
     {
         printf("Enter your choice: ");
         scanf("%d", &ch);
         switch(ch)
         {
             case 1:
             {
                 printf("Enter element to be inserted at the beginning: ");
                 scanf("%d", &x);
                 insert_begin(first,x);
                 err = 0;
             }
             break;
             case 2:
             {
                 printf("Enter element to be inserted at the end: ");
                 scanf("%d", &x);
                 insert_end(first,x);
                 err = 0;
             }
             break;
             case 3:
             {
                 delete_begin(first);
                 err = 0;
             }
             break;
             case 4:
             {
                 delete_end(first);
                 err = 0;
             }
             break;
             case 5:
                 display(first);
                 break;
             case 6:
                 exit(0);
             default:
             {
                 err++;
                 if(err==3)
                 {
                    exit(0);
                 }
                 printf("Enter a valid choice.\n");
             }
         }
     }
     while(ch>=0);
     return 0;
}
