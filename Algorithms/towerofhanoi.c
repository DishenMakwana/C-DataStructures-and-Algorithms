#include<stdio.h>
#include<conio.h>
int count=0;

void towerofhanoi(int n,char source[],char aux[],char destination[])
{
    if(n>0)
    {
    towerofhanoi( n-1, source, destination, aux);
    printf("\n Move disk %d from %s to %s",n,source,destination);
    towerofhanoi( n-1, aux, source, destination);
    count++;
    }
}

void main()
{
    int n;
    printf("Enter values:");
    scanf("%d",&n);
    towerofhanoi(n,"source","auxilary","destination");
    printf("\n Total no of moves: %d",count);
    getch();
}
