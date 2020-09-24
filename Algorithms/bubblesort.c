#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10],i,j,temp;
    printf("enter array element:\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);

    for(i=0;i<10;i++)
    {
        for(j=0;j<10-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    printf("After Bubble Sort Apply:\n");
    for(i=0;i<10;i++)
        printf("%3d",a[i]);
}
