#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*f=NULL,*l=NULL,*temp=NULL;

void enqueue(int data)
{
    struct node *t1;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(f==NULL)
    {
        f=temp;
        l=temp;
        printf("Value Inserted-->%d ",temp->data);
    }
    else
    {
        t1=f;
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=temp;
        printf("Value Inserted-->%d ",temp->data);
        temp->next=NULL;
    }
}

void dequeue()
{
    struct node *t1;
    if(f==NULL)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        temp=f;
        printf("Value Deleted-->%d ",temp->data);
        f=f->next;
        free(temp);
    }
}

void display()
{
    struct node *t1;
    if(f==NULL)
    {
        printf("\nEmpty!\n");
    }
    else
    {
        t1=f;
        while(t1!=NULL)
        {
            printf("| %d - %d |",t1->data,t1->next);
            t1=t1->next;
        }
    }
}

void main()
{
    int ch=0,a;
    while(1)
    {
        printf("\n1]ENQUEUE \n2]DEQUEUE \n3]DISPLAY \n4]EXIT \nEnter your choice--> ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("Enter value: ");
                scanf("%d",&a);
                enqueue(a);
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
                printf("\n\t\t\tExit succesfully!\n");
                exit(0);
                break;
            }
        }
    }
}
