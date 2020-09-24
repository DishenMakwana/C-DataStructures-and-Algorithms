#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 10
int a[10],b[10];

void merge(int low,int mid,int high)
{
    int l1,l2,i;
    for(l1=low,l2=mid+1,i=low ; l1<=mid && l2<=high;i++)
    {
        if(a[l1]<=a[l2])
        {
            b[i]=a[l1++];
        }
        else
        {
            b[i]=a[l2++];
        }
    }

    while(l1<=mid)
    {
        b[i++]=a[l1++];
    }
    while(l2<=high)
    {
        b[i++]=a[l2++];
    }
    for(i=low;i<=high;i++)
        a[i]=b[i];

}
void divider(int low,int high)
{
    int mid;

    if(low<high)
    {
        mid=(low+high)/2;
        divider(low,mid);
        divider(mid+1,high);
        merge(low,mid,high);
    }
    else
    {
        getch();
    }
}

void main()
{
    int i;
    printf("enter array element");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);

        divider(0,max-1);

     printf("\nlist after sorting\n");
    for(i=0;i<10;i++)
        printf("\n%d",a[i]);

}
