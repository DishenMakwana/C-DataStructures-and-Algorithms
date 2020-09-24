#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,low,up,a[20],n;

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int quick(int a[],int low,int up)
{
    i=low-1;
    j=up-1;
    while(i<j)
    {
        if(a[low]>a[i])
        {
            i++;
        }
        if(a[up]>a[j])
        {
            j--;
        }
        swap(&a[i],&a[j]);
    }
    swap(&a[i+1],&a[up]);

    return (i+1);
}

void sort(int a[],int low,int up)
{
    if(low<up)
    {
        int p=quick(a,low,up);
        sort(a,low,p-1);
        sort(a,p+1,up);
    }
}

void main()
{
    int i;
    printf("enter size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter value: ");
        scanf("%d",&a[i]);
    }
    sort(a,1,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
    getch();

}
