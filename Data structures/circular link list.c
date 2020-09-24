#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;

}*f=NULL,*l=NULL,*temp=NULL;

void ins_first(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node *t1;
    temp->data=data;
    if(temp==NULL)
    {
        printf("overflow");
    }
    else
    {
        if(f==NULL && l==NULL)
        {
            f=temp;
            temp->next=f;
        }
        else
        {
            struct node *t1;
            t1=f;
            while(t1->next!=f)
            {
                t1=t1->next;
            }
            temp->next=f;
            t1->next=temp;
            f=temp;
        }
    }
}

void ins_last(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node *t1;
    temp->data=data;
    temp->next=NULL;
    if(temp==NULL)
    {
        printf("Overflow");
    }
    else
    {
        if(f==NULL && l==NULL)
        {
            f=temp->next;
            f=temp;
            l=temp;
        }
        else
        {
            t1=f;
            while(t1->next!=f)
            {
                t1=t1->next;
            }
            t1->next=temp;
            temp->next=f;
        }
    }
}

void display()
{
    struct node * temp;
    temp=f;
    if(f==NULL)
    {
        printf("Empty!");
    }
    else
    {
        while(temp->next!=f)
        {
            printf("| %d - %d |",temp->data,temp->next);
            temp=temp->next;
        }
        printf("| %d - %d |",temp->data,temp->next);
    }
}

void del_last()
{
    struct node *t1,*t2;
    if(f==NULL)
    {
        printf("Underflow");
    }
    else if(f->next==f)
    {
        f=NULL;
        free(f);
    }
    else
    {
        t1=f;
        while(t1->next!=f)
        {
            t2=t1;
            t1=t1->next;
        }
        t2->next=t1->next;
        free(t1);
    }
}
void del_first()
{
    struct node *t1,*t2;
    if(f==NULL)
    {
        printf("Underflow");
    }
    else if(f->next==f)
    {
        f=NULL;
        free(f);
    }
    else
    {
        t1=f;
        while(t1->next!=f)
        {
            t1=t1->next;
        }
        t1->next=f->next;
        free(f);
        f=temp->next;
    }
}

void in_random(int data,int pos)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    struct node *t1;

    if(f==NULL)
    {
        f=temp;
    }
    else
    {
        if(pos==1)
        {
            t1=f;
            while(t1->next!=f)
            {
                t1=t1->next;
            }
            temp->next=f;
            f=temp;
            t1->next=f;
            printf("Node is Inserted-->%d",temp->data);
        }
        else
        {


            struct node *t2,*t1;
            t1=f;
            for(int i=1;i<=pos && t2->next!=NULL;i++)
            {
                t2=t1;
                t1=t1->next;
            }
            t2->next=temp;
            temp->next=t1;
            printf("Node is Inserted-->%d",temp->data);
        }
    }
}

void del_random(int data)
{
    int p;
    struct node *t1,*t2;
    if(f==NULL && l==NULL)
    {
        printf("\n\t\tUnderflow\n");
    }
    else
    {
        t1=f;
        for(int i=1;t1->data!=data ;i++)
        {
            t2=t1;
            t1=t1->next;
            p=0;
        }
        t2->next=t1->next;
        printf("\nNode is Deleted-->%d\n",t1->data);
        free(t1);
    }
    if(p=0)
    {
        printf("Node %d is not present in list",data);
    }
}

void main()
{
    int ch,a,b,c,d,f;
    while(1)
    {
        printf("\n1]Insert at First \n2]Insert at Last \n3]Display \n4]Delete at First \n5]Delete at Last \n6]Insert at Random \n7]Delete at Random\n8]Exit \nEnter your choice--> ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("Enter values: ");
                scanf("%d",&a);
                ins_first(a);
                break;
            }
        case 2:
            {
                printf("Enter Value: ");
                scanf("%d",&b);
                ins_last(b);
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                del_first();
                break;
            }
        case 5:
            {
                del_last();
                break;
            }
        case 6:
            {
                printf("Enter Position:");
                scanf("%d",&c);
                printf("Enter value:");
                scanf("%d",&d);
                in_random(d,c);
                break;
            }
        case 7:
            {
                printf("Enter value to be Deleted:");
                scanf("%d",&f);
                break;
            }
        case 8:
            {
                printf("\n\t\t\tExit Successfully!\n");
                exit(0);
                break;
            }
        }
    }
}
