#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*top=NULL,*temp=NULL;

void push(int data)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
}

void peek()
{
    if(top!=NULL)
    {
        printf("\nNODE IS: %d\n",top->data);
    }
    else
    {
        printf("\nEmpty!\n");
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        temp=top;
        top=top->next;
        temp->next=NULL;
        printf("\nElement delete is--> %d\n",temp->data);
        free(temp);
    }
}

void display()
{
    if(top==NULL)
    {
        printf("\nEmpty!\n");
    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("| %d - %d |",temp->data,temp->next);
            temp=temp->next;
        }
    }
}

void main()
{
    int ch=0,a;
    while(1)
    {
        printf("\n1]push \n2]pop \n3]peek \n4]Display \n5]Exit \nEnter your choice--> ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("Enter value: ");
                scanf("%d",&a);
                push(a);
                break;
            }
        case 2:
            {
                pop();
                break;
            }
        case 3:
            {
                peek();
                break;
            }
        case 4:
            {
                display();
                break;
            }
        case 5:
            {
                printf("\n\t\t\tExit succesfully!\n");
                exit(0);
                break;
            }
        }
    }
}
