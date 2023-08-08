#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct node *getNode(int val)
{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));

    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertNode(struct node *root, int val)
{
     if(root == NULL)
         return getNode(val);

     if(root->key < val)
         root->right = insertNode(root->right,val);

     if(root->key > val)
         root->left = insertNode(root->left,val);

     return root;
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    printf("%d ",root->key);
}
int main()
{
   struct node *root = NULL;


   int data;
    char ch;
        do
        {
            printf("\nSelect one of the operations::");
            printf("\n1. To insert a new node in the Binary Tree");
            printf("\n2. To display the nodes of the Binary Tree(via Postorder Traversal).\n");

            int choice;
            scanf("%d",&choice);
            switch (choice)
            {
            case 1 :
                printf("\nEnter the value to be inserted\n");
                scanf("%d",&data);
                root = insertNode(root,data);
                break;
            case 2 :
                printf("\nPostorder Traversal of the Binary Tree::\n");
                postorder(root);
                break;
            default :
                printf("Wrong Entry\n");
                break;
            }

            printf("\nDo you want to continue (Type y or n)\n");
            scanf(" %c",&ch);
        } while (ch == 'Y'|| ch == 'y');

   return 0;
}
