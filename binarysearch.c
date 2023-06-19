#include<stdio.h>
void binarysearch(int ar[],int n,int key)
{
    int first=0;
    int last=n-1;
    int middle;
    while(last>=first)
    {
        middle=(first+last)/2;
        if(ar[middle]==key)
        {
            printf("the searched element is found at %d position",middle+1);
            break;
        }
        else if(ar[middle]>key)
            last=middle-1;
        else
            first=middle+1;
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
    binarysearch(ar,n,key);
    return 0;
}