#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*f=NULL,*l=NULL,*temp=NULL;

void enqueue(int data)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(f==NULL)
    {
        f=temp;
        l=temp;
        printf("\nValue Inserted--> %d",temp->data);
    }
    else
    {
        temp->next=f;
        printf("\nValue Inserted--> %d",temp->data);
        f=temp;
    }
}

void dequeue()
{
    struct node *t1;
    if(f==NULL)
    {
        printf("\nUnderflow\n");
    }
    else if(f->next==NULL)
    {
        printf("\nValue Deleted--> %d",f->data);
        free(f);
        f=NULL;
    }
    else
    {
        temp=f;
        while(temp->next!=NULL)
        {
            t1=temp;
            temp=temp->next;
        }
        t1->next=NULL;
        printf("\nValue Deleted--> %d",temp->data);
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
        printf("\n");
        while(t1!=NULL)
        {
            printf("| %d - %d |",t1->data,t1->next);
            t1=t1->next;
        }
        printf("\n");
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

