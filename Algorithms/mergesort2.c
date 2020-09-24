#include<stdio.h>
#include<conio.h>
#define max 10

void divider(int [],int ,int );
void merge(int [],int ,int ,int );

void main()
{
    int a[max],i,j,n;
    printf("Enter array element:");
    for(i=0;i<max;i++)
        scanf("%d",&a[i]);

        divider(a,0,max-1);

        printf("\n\n");
    for(i=0;i<max;i++)
        printf("%3d",a[i]);
}

void divider(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        divider(a,low,mid);
        divider(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int i,m,k,j,temp[max];
    i=low;
    j=low;
    m=mid+1;
    while(j<=mid && m<=high)
    {
        if(a[j]<=a[m])
            temp[i]=a[j++];

        else
            temp[i]=a[m++];

        i++;
    }
        if(j>mid)
            for(k=m;k<=high;k++)
                temp[i++]=a[k];

        else
            for(k=j;k<=mid;k++)
                temp[i++]=a[k];

    for(k=low;k<=high;k++)
        a[k]=temp[k];

    for(i=0;i<max;i++)
        printf("%3d",a[i]);

    printf("\n");
}
