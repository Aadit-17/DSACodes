#include<stdio.h>
#include<string.h>
#define max 50
char stack[max];
int top=-1;
int Empty()
{
    return top==-1;
}
int Full()
{
    return top==max-1;
}
int peek()
{
    return stack[top];
}
int pop()
{
    if (Empty())
    return -1;
    char ch =stack[top];
    top--;
    return(ch);
}
void Push(int x)
{
    stack[++top] = x;
}
    int Pop()
{
    return stack[top--];
}
void push(char oper)
{
    if(Full())
    printf("Stack is Full\n");
    else
    {
        top++;
        stack[top]=oper;
    }
}
int OperandCK(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int pre(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
    int covert1(char* expression)
{
    int i, j;
    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (OperandCK(expression[i]))
        expression[++j] = expression[i];
        else if (expression[i] == '(')
        push(expression[i]);
        else if (expression[i] == ')')
        {
            while (!Empty() && peek() != '(')
            expression[++j] = pop();
            if (!Empty() && peek() != '(')
            return -1;
            else
            pop();
        }
        else
        {
            while (!Empty() && pre(expression[i]) <= pre(peek()))
            expression[++j] = pop();
            push(expression[i]);
        }
    }
    while (!Empty())
    expression[++j] = pop();
    expression[++j] = '\0';
    printf( "%s", expression);
}
int main()
{
    printf("Enter expression\n");
    char expression[50];
    scanf("%s",expression);
    covert1(expression);
    printf("\n");
}

