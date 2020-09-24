#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10],first=0,last,middle,i,n,value,k=0,j,temp=0;

    printf("Enter no of element=");
    scanf("%d",&n);

    printf("Enter array element=\n");
    for(i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("After soring of array\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }

    printf("\nEnter value u want to search=");
    scanf("%d",&value);

    last=n-1;

    while(first<=last)
    {
            middle=(first+last)/2;

            if(value>a[middle])
            {
                first=middle+1;
            }
            if(value<a[middle])
            {
                last=middle-1;
            }
            if(value==a[middle])
            {
                k=1;
                break;
            }
    }
    if(k==1)
    {
        printf("\nValue is present in array at %dth position",middle+1);
    }
    else
        printf("Value is not found");
}
