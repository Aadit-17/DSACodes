#include<stdio.h>
#include<stdlib.h>
struct Node
{
     int reg;
     int age;
     long int phone;
     char name[50];
     struct Node *next;
}*first=NULL;
void insert()
{
     struct Node *p,*q,*t,*temp;
     int cn=0;
     if(first==NULL)
     {
         temp=(struct Node*)malloc(sizeof(struct Node));
         printf("\tEnter register no.: ");
         scanf("%d",&temp->reg);
         printf("\tEnter name: ");
         scanf("%s",&temp->name);
         printf("\tEnter age: ");
         scanf("%d",&temp->age);
         printf("\tEnter phone no.: ");
         scanf("%ld",&temp->phone);
         temp->next=NULL;
         first=temp;
     }
     else
     {
         p=first;
         q=NULL;
         temp=(struct Node*)malloc(sizeof(struct Node));
         printf("\tEnter register no.: ");
         scanf("%d",&temp->reg);
         printf("\tEnter name: ");
         scanf("%s",&temp->name);
         printf("\tEnter age: ");
         scanf("%d",&temp->age);
         printf("\tEnter phone no.: ");
          scanf("%ld",&temp->phone);
         t=first;
         while(t!=NULL)
         {
             if(temp->age==t->age)
             cn++;
             t=t->next;
         }
         if(cn==5)
         {
             printf("Five members have been filled.\nInvalid Record.\n");
             return;
         }
         else
         {
             while(p && p->reg<temp->reg)
             {
                 q=p;
                 p=p->next;
             }
             temp->next=q->next;
             q->next=temp;
         }
     }
}
void del(int val)
{
     struct Node *p,*q=NULL;
     int x=1;
     p=first;
     while(p->reg != val)
     {
         q = p;
         p = p->next;
         x++;
     }
     q->next=p->next;
     free(p);
     printf("Player with registration no.- %d deleted successfully from list.\n", val);
}
void display(struct Node *p)
{
     int i=1;
     printf("--------------------------------\n");
     while(p!=NULL)
     {
         printf("Player %d details:\n", i);
         printf("\tRegister No.: %d\n",p->reg);
         printf("\tName: %s\n",p->name);
         printf("\tAge: %d\n",p->age);
         printf("\tPhone Number: %ld\n",p->phone);
         p=p->next;
         i++;
     }
     printf("--------------------------------\n");
     printf("\n");
}
int main()
{
     int err=0,x,ch=0;
     printf("Select your choice: "
     "\n\t1. Insertion"
     "\n\t2. Deletion"
     "\n\t3. Display"
     "\n\t4. Exit\n");
     do
     {
         printf("Enter your choice: ");
         scanf("%d", &ch);
         switch(ch)
         {
             case 1:
             {
                 insert();
                 err = 0;
             }
             break;
             case 2:
             {
                 printf("Enter Registration Number of the player to be deleted: ");
                 scanf("%d", &x);
                 del(x);
                 err = 0;
             }
             break;
             case 3:
                display(first);
                break;
             case 4:
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
     }while(ch>=0);
     return 0;
}
