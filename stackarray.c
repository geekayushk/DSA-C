#include<stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push()
{
    int n;
    if(isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("\nEnter the elements into the stack:");
        scanf("%d",&n);
        top++;
        stack[top]=n;
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int x=stack[top];
        top--;
        printf("\nThe deleted element is:%d\n",x);
    }
}
void display()
{
    printf("Stack elements are:\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
int  isFull()
{
    if(top==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void peek()
{
    if(isEmpty())
        printf("Stack is Empty");
    else
        printf("The topmost element is %d\n",stack[top]);
}
int main()
{
    int ch;
    do
    {
        printf("Enter:\n 1.push\n 2.pop\n 3.display\n 4.peek\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:peek();break;
            default: printf("INVALID CHOICE");
        }
    }while(ch!=0);
}
