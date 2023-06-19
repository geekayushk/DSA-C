#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int main()
{
    struct node *p=createnode(6);
    struct node *p1=createnode(9);
    struct node *p2=createnode(17);
    p->left=p1;
    p->right=p2;

}