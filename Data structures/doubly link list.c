#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* lptr;
    struct node* rptr;
}*f=NULL,*l=NULL,*temp=NULL;

void ins_first(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->lptr=NULL;
    temp->rptr=NULL;

    if(f==NULL)
    {
        f=temp;
        l=temp;
    }
    else
    {
        f->lptr=temp;
        temp->rptr=f;
        temp->lptr=NULL;
        f=temp;
    }
}

void ins_last(int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->lptr=NULL;
    temp->rptr=NULL;

    if(f==NULL)
    {
        f=temp;
        l=temp;
    }
    else
    {
        struct node*t1;
        t1=f;
        while(t1->rptr!=NULL)
        {
            t1=t1->rptr;
        }
        t1->rptr=temp;
        temp->lptr=t1;
        l=temp;
        l->rptr=NULL;
    }
}

void del_first()
{
    if(f==NULL)
    {
        printf("\nUnderflow\n");
    }
    else
    {
        struct node* temp;
        temp=f;
        printf("\nNode is Deleted--> %d\n",f->data);
        f=f->rptr;
        free(temp);
    }
}

void del_last()
{
    if(f==NULL)
    {
        printf("\nUnderflow\n");
    }
    else
    {

        struct node* t1,*t2;
        t1=f;
        if(t1->rptr==NULL)
        {
            printf("Node is Delete-->%d",t1->data);
            free(t1);
            f=NULL;
        }
        else
        {
            while(t1->rptr!=NULL)
            {
                t2=t1;
                t1=t1->rptr;
            }
            printf("Node is Delete-->%d",t1->data);
            t2->rptr=NULL;
            free(t1);
        }
    }
}

void ins_random(int data,int pos)
{
    struct node *t2,*t1;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->lptr=NULL;
    temp->rptr=NULL;

    if(f==NULL)
    {
        f=temp;
        l=temp;
    }
    else if(pos==1)
    {
        temp->rptr=f;
        f->lptr=temp;
        f=temp;
    }
    else
    {
        t1=f;
        for(int i=1;i<pos && t2->rptr!=NULL;i++)
        {
            t2=t1;
            t1=t1->rptr;
        }
        t2->rptr=temp;
        temp->lptr=t2;
        temp->rptr=t1;
        t1->lptr=temp;
        printf("Node is Inserted-->%d",temp->data);
    }
}

void del_random(int data)
{
    int p;
    struct node *t1,*t2,*t3;
    if(f==NULL)
    {
        printf("\n\t\tUnderflow\n");
    }
    else if(f->data==data)
    {
        t1=f;
        f=f->rptr;
        free(t1);
    }
    else
    {
        t1=f;
        for(int i=1;t1->data!=data ;i++)
        {
            t2=t1;
            t1=t1->rptr;
            p=0;
        }
        t2->rptr=t1->rptr;

        printf("\nNode is Deleted-->%d\n",t1->data);
        free(t1);
    }
    if(p=0)
    {
        printf("Node %d is not present in list",data);
    }
}

void display()
{
    if(f==NULL)
    {
        printf("\nEmpty!\n");
    }
    else
    {
        temp=f;
        while(temp!=NULL)
        {
            printf("| %d - %d |",temp->data,temp->rptr);
            temp=temp->rptr;
        }
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
                ins_last(a);
                break;
            }
        case 2:
            {
                printf("Enter value to be inserted :");
                scanf("%d",&b);
                ins_first(b);
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
                ins_random(n,d);
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
}
