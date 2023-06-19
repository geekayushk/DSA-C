#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linkedlist(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node * deleteatfirst(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
void deletionatindex(struct node * head,int index)
{
    struct node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    struct node *q=p->next;
    p->next=q->next;
    free(q);
}
void deletionatend(struct node * head)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
}
void deletionofgivenvalue(struct node * head,int value)
{
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
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
    fourth->next=NULL;
    printf("Before deletion:");
    linkedlist(head);

    //head=deleteatfirst(head);

    //deletionatindex(head,2);

   //deletionatend(head);

   deletionofgivenvalue(head,15);

    printf("After deletion:");
    linkedlist(head);
    return 0;
}
