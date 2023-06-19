#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int ch, elem, count = 0, q[MAX], rear = -1, front = 0;
void insert()
{
    if (count == MAX)
        printf("Queue is full");
    else
    {
        printf("Enter the element to be inserted:\n");
        scanf("%d",&elem);
        rear = (rear + 1) % MAX;
        q[rear] = elem;
        count++;
    }
}
void delete ()
{
    if (count == 0)
        printf("Queue is empty");
    else
    {
            int item = q[front];
            printf("\nDeleted element is %d\n", item);
            front = (front + 1) % MAX;
            count--;
        
    }
}
void display()
{
    int i;
    if (count == 0)
        printf("\nQueue is Empty");
    else
    {
        printf("Queue Contents are:\n");
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d\n", q[i]);
        }
        printf("%d\n",q[i]);
    }
}
void main()
{
    do
    {
        printf("1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    } while (ch != 4);
}