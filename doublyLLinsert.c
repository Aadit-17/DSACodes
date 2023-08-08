#include<stdio.h>
#include<stdlib.h>
struct node
{
     struct node *prev;
     int data;
     struct node *next;
}*head=NULL;

void ins_beg();
void ins_end();
void ins_pos();
void display();

int main()
{
     int choice;
     while(choice!=5)
     {
         printf("Doubly Linked List\n");
         printf("1.Insertion at beginning\n2.Insertion at end\n3.Insertion at particular place\n4.Display list\n5.Exit\n");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:
             {
                 ins_beg();
                 break;
             }
             case 2:
             {
                 ins_end();
                 break;
             }
             case 3:
             {
                 ins_pos();
                 break;
             }
             case 4:
             {
                 display();
                 break;
             }
         }
     }
}
void ins_beg()
 {
     struct node *temp,*t;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->prev=NULL;
     temp->next=NULL;
     int x;
     t=head;
     scanf("%d",&x);
     temp->data=x;
     if(head==NULL)
     {
        head=temp;
     }
     else
     {
         temp->next=t;
         head=temp;
         t->prev=temp;
     }
}

void ins_end()
 {
     struct node *temp,*t;
     t=head;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->prev=NULL;
     temp->next=NULL;
     int x;
     t=head;
     scanf("%d",&x);
     temp->data=x;
     if(t==NULL)
     {
        head=temp;
     }
     else
     {
        while(t->next!=NULL)
        {
        t=t->next;
        }
        t->next=temp;
        temp->prev=t;
     }
}

void ins_pos()
 {
     struct node *temp,*t,*p;
     temp=(struct node*)malloc(sizeof(struct node*));
     int x;
     printf("Enter value\n");
     scanf("%d",&x);
     int n;
     printf("Enter position\n");
     scanf("%d",&n);
     temp->data=x;
     temp->prev=NULL;
     temp->next=NULL;
     t=head;
     p=head;
     int i;
     if(n==1)
     {
         head=temp;
         temp->next=t;
     }
     else
     {
         for(i=1;i<n;i++)
         {
             p=t;
             t=t->next;
         }
         p->next=temp;
         temp->prev=p;
         temp->next=t;
         t->prev=temp;
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
