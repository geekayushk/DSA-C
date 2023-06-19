#include<stdio.h>
#define MAX 10
int Queue[MAX];
int front=-1;
int rear=-1;
int isFull()
{
    if(rear==MAX-1)
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
    if(front==rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue()
{
    int n;
    if(isFull())
    {
        printf("Queue Overflow");
    }
    else
    {
        printf("Enter the element:");
        scanf("%d",&n);
        rear++;
        Queue[rear]=n;
    }
}
void dequeue()
{
    if(isEmpty())
    {
        printf("Queue Underflow");
    }
    else
    {
        front++;
        int x=Queue[front];
        free(Queue[front]);
        printf("The deleted element is %d\n",x);
    }
}
void display()
{
    printf("Queue elements are:\n");
    for(int i=front+1;i<=rear;i++)
    {
        printf("%d ",Queue[i]);
    }
}
void main()
{
    int ch;
    do
    {
        printf("\nEnter:\n1.enqueue \n2.dequeue \n3.display \n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            default:printf("INVALID CHOICE");
        }
    }while(ch!=0);
}