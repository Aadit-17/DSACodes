#include<stdio.h>
#include<stdlib.h>
struct node
{
     struct node *prev;
     int data;
     struct node *next;
}*head=NULL;

void create(int arr[],int n);
void del_val();
void display();

int main()
{
     int choice;
     int arr[]={5,8,45,72,65,34,23}; //pre-set list since just deletion is to be performed
     create(arr,8);
     display(head);
     while(choice!=3)
     {
         printf("Doubly Linked List\n");
         printf("1.Deletion of a particular value\n2.Display\n3.Exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             {
                 del_val();
                 break;
             }
             case 2:
             {
                 display();
                 break;
             }
         }
     }
 }
void create(int arr[],int n)
{
     struct node *t,*temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=arr[0];
     temp->next=NULL;
     head=temp;
     t=head;
     int i;
     for(i=1;i<n;i++)
     {
         t=(struct node *)malloc(sizeof(struct node));
         t->data=arr[i];
         t->next=NULL;
         temp->next=t;
         temp=temp->next;
     }
}

void del_val()
{
     struct node *t,*p,*r;
     int x;
     printf("Enter value of element to be deleted: ");
     scanf("%d",&x);
     t=head;
     p=NULL;
     while(t->data!=x && t!=NULL)
     {
         p=t;
         t=t->next;
     }
     r=t->next;
     if(t==head)
     {
         head=r;
         r->prev=NULL;
         free(t);
     }
     else if(t->next==NULL)
     {
         p->next=NULL;
         free(t);
         free(r);
     }
     else if(r->next==NULL)
     {
        printf("Element not found\n");
     }
     else
     {
         p->next=r;
         r->prev=p;
         free(t);
     }
}

void display()
{
     struct node *t;
     t=head;
     while(t!=NULL)
     {
         printf("%d->",t->data);
         t=t->next;
     }
     printf("NULL\n");
}
