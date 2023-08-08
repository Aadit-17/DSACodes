#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
char stack[100];

void push(char);
void pop();
void findtop();

void main()
{
    int i;
    char a[100];
    printf("Enter expression:");
    scanf("%s", &a);
    for (i = 0; a[i] != '\0';i++)
    {
        if (a[i] == '(')
        {
            push(a[i]);
        }
        else if (a[i] == ')')
        {
            pop();
        }
    }
    findtop();
}

void push(char a)
{
    stack[top] = a;
    top++;
}

void pop()
{
    if (top == -1)
    {
        printf("Unbalanced Expression\n");
        exit(0);
    }
    else
    {
        top--;
    }
}

void findtop()
{
    if (top == -1)
        printf("\nBalanced Expression\n");
    else
        printf("\nUnbalanced Expression\n");
}
