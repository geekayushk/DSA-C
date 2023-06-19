#include<stdio.h>
#include<string.h>
#define MAX 10
char stack[MAX];
int top=-1;
int  isFull(char stack[])
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
int isEmpty(char stack[])
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
char push(char j)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        
        top++;
        stack[top]=j;
    }
}
char pop(char j)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char val=stack[top];
        top--;
        return val;
    }
}

int isOperator(char ch)
{
    if(ch=='*'||ch=='/'||ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}
int precedence(char ch)
{
    if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='+'||ch=='-')
        return 1;
    else
        return 0;
}

void infixtopostfix(char infix[])
{
    char postfix[MAX];
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++;i++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stack[top]))
            {
                push(infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(stack[top]);
                j++;
            }
        }
    }
    while(!isEmpty(stack))
    {
        postfix[j]=pop(stack[top]);
        j++;
    }
    postfix[j]='\0';
    printf("The postfix expression is:%s",postfix);
    
}
int main()
{
    char infix[MAX];
    printf("Enter the string:\n");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
    
}