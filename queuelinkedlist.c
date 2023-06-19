#include<stdio.h>
#include<stdlib.h>
struct node * front=NULL;
struct node * rear=NULL;
struct node
{
    int data;
    struct node *next;
};
int isFull()
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
int isEmpty(struct node *front )
{
    if(front==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int data)
{
    if(isFull())
    {
        printf("Stack Overflow");
    }
    else
    {
        struct node *n=(struct node *)malloc(sizeof(struct node));
        n->data=data;
        n->next=NULL;
        if(front==NULL)
        {
            front=rear=n;
        }
        else
        {
            rear->next=n;
            rear=n;
        }
    }
}
struct node *dequeue()
{
    if(isEmpty(front))
    {
        printf("Stack Underflow");
    }
    else
    {
        struct node *ptr=front;
        front=front->next;
        int x=ptr->data;
        printf("The deleted element is:%d\n",x);
        free(ptr);
    }
}
void display()
{
    struct node *ptr=front;
    printf("Queue elements are:\n");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(9);
    enqueue(10);
    dequeue();
    display();
}