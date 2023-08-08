#include <iostream>
using namespace std;

struct stack
{
    int top;
    int stack_arr[10];
}s;

void push()
{
    int pushed_item, n;
    cout<<"Enter no. of elements ";
    cin>>n;
    cout<<"Enter element to be pushed ";
    cin>>pushed_item;
    
    if(s.top == (n-1))
    {
        cout<<"Stack Overflow\n";
    }
    else
    {
        s.top == s.top + 1;
        s.stack_arr[s.top] = pushed_item;
    }
}

void pop()
{
    if(s.top == -1)
    {
        cout<<"Stack Underflow\n";
    }
    else
    {
        cout<<"Popped element is"<<s.stack_arr[s.top];
        s.top = s.top -1;
    }
}

void display()
{
    int i;
    if (s.top == -1)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        cout<<"Stack elements\n";
        for(i=s.top; i>=0; i--)
        {
            cout<<s.stack_arr[i];
        }    
    }
}


int main()
{
    s.top = -1;
    int choice;
    while(1)
    {
        cout<<"1.Push\n";
        cout<<"2.Pop\n";
        cout<<"3.Display\n";
        cout<<"4.Quit\n";
        cout<<"Enter your choice\n";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                cout<<"Enter valid option\n";
        }
    }
}

