#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void circularlinkedlist(struct node *head)
{
    struct node *ptr=head;
    do
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node * insertatfirst(struct node *head,int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    do
    {
        p=p->next;
    }while(p->next!=head);
    ptr->next=p->next;
    p->next=ptr;
    head=ptr;

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=15;
    third->next=fourth;
    fourth->data=21;
    fourth->next=head;
    printf("Cir. linkedlist before insertion:");
    circularlinkedlist(head);

    head=insertatfirst(head,69);

    printf("Cir. linkedlist after insertion:");
    circularlinkedlist(head);
    
    return 0;
}
