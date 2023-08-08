#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *create_node(int);
void insert(int);
struct node *delete (struct node *, int);
int search(int);
void inorder(struct node *);
void postorder();
void preorder();
struct node *smallest_node(struct node *);
struct node *largest_node(struct node *);
struct node *kthSmallest(struct node* root, int k);
void printKthSmallest(struct node* root, int k);
struct node *kthLargest(struct node* root, int k);
void printKthLargest(struct node* root, int k);
int get_data();
int main()
{
    int Opt;
    int data;
    int k;
    struct node* result = NULL;
    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Largest Node");
        printf("\n5. Smallest Node");
        printf("\n6. Find kth minimum node");
        printf("\n7. Find kth maximum node");
        printf("\n8. Exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &Opt);
        printf("\n");
        switch(Opt)
        {
            case 1:
            data = get_data();
            insert(data);
            break;
            case 2:
            data = get_data();
            root = delete(root, data);
            break;
            case 3:
            data = get_data();
            if (search(data) == 1)
            {
                printf("\nData was found!\n");
            }
            else
            {
                printf("\nData does not found!\n");
            }
            break;
            case 4:
            result = largest_node(root);
            if (result != NULL)
            {
                printf("\nLargest Data: %d\n", result->data);
            }
            break;
            case 5:
            result = smallest_node(root);
            if (result != NULL)
            {
                printf("\nSmallest Data: %d\n", result->data);
            }
            break;
            case 6:
            printKthSmallest(root,k);
            break;
            case 7:
            printKthLargest(root,k);
            break;
            case 8:
            printf("\n\nProgram was terminated\n");
            break;
            default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void insert(int data)
{
    struct node *new_node = create_node(data);
    if (new_node != NULL)
    {
        if (root == NULL)
        {
            root = new_node;
            printf("\nNode Inserted.\n", data);
            return;
        }
        struct node *temp = root;
        struct node *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (data > prev->data)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }
        printf("\nNode Inserted.\n", data);
    }
}
struct node *delete (struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}
int search(int key)
{
    struct node *temp = root;
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            return 1;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}
struct node *smallest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
struct node *largest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}
int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}
int count = 0;
struct node *kthSmallest(struct node* root, int k)
{
    if (root == NULL)
        return NULL;
    struct node* left = kthSmallest(root->left, k);
    if (left != NULL)
        return left;
    count++;
    if (count == k)
        return root;
    return kthSmallest(root->right, k);
}
void printKthSmallest(struct node* root, int k)
{
    printf("Enter the value of k: ");
    scanf("%d",&k);
    struct node* res = kthSmallest(root, k);
    if (res == NULL)
        printf("There are less than k nodes in the BST.");
    else
        printf("%d Smallest Element is %d.",k, res->data);
}
struct node *kthLargest(struct node* root, int k)
{
    if (root == NULL)
        return NULL;
    struct node* right = kthLargest(root->right, k);
    if (right != NULL)
        return right;
    count++;
    if (count == k)
        return root;
    return kthLargest(root->left, k);
}
void printKthLargest(struct node* root, int k)
{
    printf("Enter the value of k: ");
    scanf("%d",&k);
    struct node* res = kthLargest(root, k);
    if (res == NULL)
        printf("There are less than k nodes in the BST.");
    else
        printf("%d Largest Element is %d.",k, res->data);
}
