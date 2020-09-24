#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10],i,j,min,t;

    printf("enter array element:\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        min=i;
        for(j=i;j<10;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        t=a[i];
        a[i]=a[min];
        a[min]=t;

    }
    printf("After Selection Sort Apply:\n");
    for(i=0;i<10;i++)
    {
        printf("%3d",a[i]);
    }
}
