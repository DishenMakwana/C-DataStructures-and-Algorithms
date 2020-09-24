
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int front=-1,rear=-1,a[10];

void enqueue()
{
    int x;
    if(rear==size-1)
    {
        printf(" \nQueue is overflow");
    }
    else
    {
        printf("Enter element to be inserted:");
        scanf("%d",&x);
        a[rear]=x;
        rear++;
    }
}
void dequeue()
{
    if(front==-1 || front==rear)
    {
        printf("\nQueue is underflow");
    }
    else
    {
        printf("\nDelete element from Queue is =%d",a[front]);
        a[front]='\0';
        front++;
    }
}

void display()
{
    int i;
    if(front>=rear)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        printf("\n");
        for(i=front;i<rear;i++)
        {
            printf("%d\n",a[i]);
        }
    }
}

int main()
{
    int choice,ans;
    front++;
    rear++;

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



