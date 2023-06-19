#include<stdio.h>
#define MAX 10
char stack[MAX];
int top=-1;
void push(char j)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top]=j;
    }
}
void pop(char j)
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        top--;
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
int parenthesismatch(char str[])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            push(str[i]);
        }
        else if (str[i]==')'||str[i]=='}'||str[i]==']')
        {
            if(isEmpty())
            {
                return 0;
            }
            pop(str[i]);

        }
        
    }
    if(isEmpty())
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    char str[MAX];
    printf("Enter the string:\n");
    gets(str);
    if(parenthesismatch(str))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
    
}