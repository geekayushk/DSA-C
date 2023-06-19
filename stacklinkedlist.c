#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *top)
{
    struct node *ptr=top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int isEmpty(struct node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct node *top)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
struct node * push(struct node *top, int data)
{
    if(isFull(top))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct node *n=(struct node *)malloc(sizeof(struct node));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}
struct node *pop(struct node *top)
{
    if(isEmpty(top))
    {
        printf("Stack Underflow");
    }
    else
    {
        struct node *ptr=top;
        top=top->next;
        int x=ptr->data;
        printf("The popped element is:%d\n",x);
        free(ptr);
        return top;
    }
}
void peek(struct node *top)
{
    if(isEmpty(top))
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("\nThe topmost element is:%d\n",top->data);
    }
}
int main()
{
    struct node *top=NULL;
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    top=push(top,4);
    top=push(top,5);
    top=pop(top);
    display(top);
    peek(top);
    return 0;
}