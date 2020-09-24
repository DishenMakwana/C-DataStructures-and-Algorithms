#include<stdio.h>
#include<conio.h>
void main()
{
    int a[4][5];
    for(int i=0;i<4;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&a[i][j]);

    int size=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<5;j++)
        {
            if(a[i][j]!=0)
            {
                size++;
            }
        }

    int b[3][size],k=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<5;j++)
            if(a[i][j]!=0)
            {
                b[0][k]=i;
                b[1][k]=j;
                b[2][k]=a[i][j];
                k++;
            }

    printf("Rows:     ");
    for(int i=0;i<1;i++)
        for(int j=0;j<size;j++)
            printf("%3d",b[i][j]);

    printf("\n");
    printf("Columns:  ");
    for(int i=1;i<2;i++)
        for(int j=0;j<size;j++)
            printf("%3d",b[i][j]);

    printf("\n");
    printf("Values:   ");
    for(int i=2;i<3;i++)
        for(int j=0;j<size;j++)
            printf("%3d",b[i][j]);
getch();
}
