#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create()
{
    int item;
    struct node *n=(struct node *)malloc(sizeof(struct node));
    printf("Enter the item to be inserted:");
    scanf("%d",&item);
    n->data=item;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void insert(struct node *root,struct node *newnode)
{
    if(newnode->data<root->data)
    {
        if(root->left==NULL)
            root->left=newnode;
        else
            insert(root->left,newnode);
    }
    if(newnode->data>root->data)
    {
        if(root->right==NULL)
            root->right=newnode;
        else
            insert(root->right,newnode);
    }
}
void search(struct node *root)
{
    int key;
    struct node *cur=root;
    if(root==NULL)
    {
        printf("BST is empty");
        return;
    }
    printf("Enter the element to be searched:\n");
    scanf("%d",&key);
    while(cur!=NULL)
    {
        if(cur->data==key)
        {
            printf("Key element is present in BST\n");
            return;
        }
        if(key<cur->data)
        {
            cur=cur->left;
        }
        else
            cur=cur->right;
    }
    printf("Key element is not found in BST\n");

}
struct node *findlastright(struct node *root)
{
    if(root->right==NULL)
    {
        return root;
    }
    else
        return findlastright(root->right);
}
struct node *helper(struct node *root)
{
    if(root->left==NULL)
        return root->right;
    if(root->right==NULL)
        return root->left;
    struct node *rightchild=root->right;
    struct node *lastright=findlastright(root->left);
    lastright->right=rightchild;
    return root->left;
}
struct node *deletion(struct node *root,int lock)
{
    if(root==NULL)
        return NULL;
    if(root->data==lock)
        return helper(root);
    struct node *dummy=root;
    while(root!=NULL)
    {
        if(root->data>lock)
        {
            if(root->left!=NULL && root->left->data==lock)
            {
                root->left=helper(root->left);
                break;
            }
            else
            {
                root=root->left;
            }
        }
        else
        {
            if(root->right!=NULL && root->right->data==lock)
            {
                root->right=helper(root->right);
                break;
            }
            else
            {
                root=root->right;
            }
        }
    }
return dummy;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void main()
{
    int ch,n,i,lock;
    struct node *root=NULL;
    do
    {
        printf("\n____MENU____\n");
        printf("1.Create\n 2.Search\n 3.Delete\n 4.Traversal\n 5.exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the no. of elements:\n");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++)
                    {
                        struct node *newnode=create();
                        if(root==NULL)
                            root=newnode;
                        else
                            insert(root,newnode);
                    }
                    break;
            
            case 2:search(root);
                    break;
            case 3:
                    printf("Enter the elemment to be deleted:");
                    scanf("%d",&lock);
                    deletion(root,lock);
            
            case 4:if(root==NULL)
                        printf("Tree is not created\n");
                    else
                    {
                        printf("\nInorder Traversal");
                        inorder(root);
                    }
                    break;
            
            case 5:exit(0);
                    break;
        }
    } while (ch!=5);
    
}