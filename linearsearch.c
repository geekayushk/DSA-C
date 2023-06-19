#include<stdio.h>
void linearsearch(int ar[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(ar[i]==key)
            printf("the searched element is found at %d index",i);
    }
}
int main()
{
    int ar[10],n,key,i;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter the elements into the array:");
    for(int i=0;i<n;i++)
        scanf("%d",&ar[i]);
    printf("Enter the no. to be searched for:");
    scanf("%d",&key);
    linearsearch(ar,n,key);
    return 0;
}