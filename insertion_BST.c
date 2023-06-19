#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
struct node *insert(struct node *root, int key)
{
    struct node *prev=NULL;
    while (root != NULL)
    {
        prev=root;
        if (root->data == key)
        {
            printf("Cannot insert %d,already present in BST",key);
            return 0;
        }
        else if(key<root->data)
            root=root->left;
        else
            root=root->right;
    }
    struct node *new=createnode(key);
    if(key<prev->data)
        prev->left=new;
    else
        prev->right=new;
}
int main()
{
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    insert(p,15);
    printf("%d",p->right->right->data);
    return 0;
}