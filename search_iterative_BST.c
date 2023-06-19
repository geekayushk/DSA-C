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
struct node *searchBST(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;
        else if(key<root->data)
            root=root->left;
        else
            root=root->right;
    }
    return NULL;
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

    struct node *x = searchBST(p, 6);
    if (x != NULL)
        printf("Found: %d\n", x->data);
    else
        printf("Not Found");
    return 0;
}