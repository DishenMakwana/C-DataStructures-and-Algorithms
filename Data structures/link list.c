#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;

}*f=NULL,*l=NULL,*temp=NULL;

void in_last(int data)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(f==NULL && l==NULL)
    {
        f=temp;
        l=temp;
    }
    else
    {
        l->next=temp;
        l=temp;
    }
    printf("\nNode is Inserted--> %d\n",temp->data);
}
void in_first(int data)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(f==NULL && l==NULL)
    {
        f=temp;
        l=temp;
    }
    else
    {
        temp->next=f;
        f=temp;
    }
    printf("\nNode is Inserted--> %d\n",temp->data);
}
void display()
{
    if(f==NULL && l==NULL)
    {
        printf("\nEmpty!\n");
    }
    else
    {

        temp=f;
        printf("\n");
        while(temp!=NULL)
        {
            printf("| %d --> %d |",temp->data,temp->next);
            temp=temp->next;
        }
        printf("\n");
    }
}

void del_first()
{
     if(f==NULL)
    {
        printf("\n\t\tUnderflow\n");
    }
    else
    {
        struct node* temp;
        temp=f;
        printf("\nNode is Deleted--> %d\n",f->data);
        f=f->next;
        free(temp);
    }
}

void del_last()
{
    if(f==NULL)
    {
        printf("\n\t\tUnderflow\n");
    }
    else
    {
        struct node *temp,*t1;
        temp=f;
        if(temp->next==NULL)
        {
            printf("Node is Delete-->%d",temp->data);
            free(temp);
            f=NULL;
        }
        else
        {
            while(temp->next!=NULL)
            {
                t1=temp;
                temp=temp->next;
            }
            printf("Node is Delete-->%d",temp->data);
            t1->next=NULL;
            t1=l;
            free(temp);
        }
    }
}

void in_random(int data,int pos)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(f==NULL && l==NULL)
    {
        f=temp;
        l=temp;
    }
    else if(pos==1)
    {
        temp->next=f;
        f=temp;
    }
    else
    {
        struct node *t2,*t1;
        t1=f;
        for(int i=1;i<pos && t2->next!=NULL;i++)
        {
            t2=t1;
            t1=t1->next;
        }
        t2->next=temp;
        temp->next=t1;
        printf("Node is Inserted-->%d",temp->data);
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
    int ch=0,a,b,d,p,n,t;

    while(1)
    {
        printf("\n1]Insert at Last \n2]Insert at First \n3]Delete at Last \n4]Delete at First \n5]Display \n6]Insert at Random Position [othen then 1st] \n7]Delete Any Value [othen then 1st] \n8]Exit \nEnter your choice--> ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                printf("Enter value to be inserted :");
                scanf("%d",&a);
                in_last(a);
                break;
            }
        case 2:
            {
                printf("Enter value to be inserted :");
                scanf("%d",&b);
                in_first(b);
                break;
            }
        case 3:
            {
                del_last();
                break;
            }
        case 4:
            {
                del_first();
                break;
            }
        case 5:
            {
                display();
                break;
            }
        case 6:
            {
                printf("Enter value:");
                scanf("%d",&n);
                printf("Enter position where Insert:");
                scanf("%d",&d);
                in_random(n,d);
                break;
            }
        case 7:
            {
                printf("Enter value to be Delete:");
                scanf("%d",&t);
                del_random(t);
                break;
            }
        case 8:
            {
                printf("Exit Successfully!");
                exit (0);
                break;
            }
        }
    }
    getch();
}
