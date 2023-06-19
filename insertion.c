#include<stdio.h>
void insertion(int ar[],int n, int capacity)
{
    int pos,elem;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos<=0||pos>capacity)
        printf("INVALID POSITION");
    printf("Enter the element:");
    scanf("%d",&elem);
    pos=pos-1;
    for(int i=n-1;i>=pos;i--)
        ar[i+1]=ar[i];
    ar[pos]=elem;
    
}
void display(int ar[],int n)
{
    printf("Array after insertion:");
    for(int i=0;i<n+1;i++)
        printf("%d ",ar[i]);
}
int main()
{
    int capacity,i,n;
    printf("Enter the capacity:");
    scanf("%d",&capacity);
    int ar[capacity];
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    printf("Enter the elements into the array:");
    for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
    insertion(ar,n,capacity);
    display(ar,n);
    return 0;
}