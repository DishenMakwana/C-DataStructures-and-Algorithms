#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int front=-1,rear=-1,a[size];

void enqueue()
{
    int x;
    if(front-1==rear && front>0 || (front==0 && rear==size-1))
    {
        printf("Queue is overflow!");
    }
    else
    {
        if(front==-1)
            front=0;

        printf("Enter element to be inserted:");
        scanf("%d",&x);
        rear=(rear+1)%size;
        a[rear]=x;
    }
}

void dequeue()
{
    if(front==-1)
    {
        printf("\nQueue is underflow");
    }
    else
    {
        printf("\nDelete element from Queue is =%d",a[front]);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
    }
}

void display()
{
    int i;
    if(rear==-1 && front==-1 )
    {
        printf("\nEmpty Queue");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%size)
        {
            printf("%3d",a[i]);
        }
        printf("%3d",a[i]);
    }
}

int main()
{
    int choice,ans;

    while(choice!=4)
    {

             printf("\n1]enqueue \n2]dequeue \n3]display\n4]exit---> enter your choice: ");
             scanf("%d",&choice);

      switch(choice)
        {
        case 1:
            {
                enqueue();
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                return 0;
            }
        }
    }

}

