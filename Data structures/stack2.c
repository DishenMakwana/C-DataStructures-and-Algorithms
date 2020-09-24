#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[10],top=-1;
int choice,n,x,i,b,y;

void push()
{
    int x;
    if(top>=n-1)
     {
        printf("Stack overflow \n");
     }
    else
     {
        printf("Enter element in stack\n");
        scanf("%d",&x);
        top++;
        a[top]=x;
    }
}

int pop()
{
    if(top<=-1)
        printf("Stack underflow\n");
    else
    {
        printf("Delete Element:->%d",a[top]);
        top--;
    }
}

void peep()
{
    int m;
    printf("Enter the position:");
    scanf("%d",&m);
    if((top-m+1)<0)
    {
        printf("\nInvalid position\n");
    }
    else
    {
        printf("Peeped element is:-> %d",a[top-m+1]);
    }
}

void display()
{
    int i;
    if(top>=0)
    {
        printf("Element in Stack is\n");
        for(i=top;i>=0;i--)
            printf("%d--> ",a[i]);
        printf("!");
    }
    else
        printf("Stack is empty\n");


}

/*void change(int *c,int *d)
{
    int i;
    for(top=n-1;top>=0;top--)
    {
        if(a[i]==*c)
        {
            a[i]=*d;
        }
    }
}*/

void main()
{
    int d,c;
    printf("Enter size of Stack: ");
    scanf("%d",&n);
    if(choice==0  || choice==n)
    {
        while(1)
        {
        printf("\n1]push \n2]pop \n3]peep \n4]display \n5]Change \n6]exit\n");
        printf("Enter your choice:-> ");
        scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    {
                        push();
                        break;
                    }
                case 2:
                    {
                        pop();
                        break;
                    }
                case 3:
                    {
                        peep();
                        break;
                    }
                case 4:
                    {
                        display();
                        break;
                    }
                /*case 5:
                    {
                        printf("Enter value to be change: ");
                        scanf("%d",&c);
                        printf("Enter number to be change: ");
                        scanf("%d",&d);
                        change(&c,&d);

                        printf("Stack after change:\n");
                        for(int i=top;i>=0;i++)
                        {
                            if(a[i]!=0)
                                printf("%d--> ",a[i]);
                        }printf("!");
                    }*/
                case 6:
                    {
                       exit(0);
                       break;
                    }
                }
        }
    }
getch();
}
