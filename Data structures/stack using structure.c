#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int x,i,n;

struct stack
{
   int a[10];
   int top;
}s;

void push()
{
    if(s.top>=n-1)
    {
       printf("\nstack overflow\n");
    }
    else
    {
        printf("\nenter element :\n");
        scanf("%d",&x);
        s.top++;
        s.a[s.top]=x;
    }
}

void pop()
{
    if(s.top<=-1)
    {
        printf("\nUnderflow\n");
    }
    else
    {
         printf("\ndelete element is :%d",s.a[s.top]);
         s.top--;
    }

}

void peep()
{
    int m,y;
    printf("\nenter position to peep\n");
    scanf("%d",&m);

    if((s.top-m+1)<0)
    {
        printf("\nInvalid position\n");
    }
    else
    {
        printf("Peeped element is:-> %d",s.a[s.top - m+1]);
    }
}

void display()
{
    int i;
    if(s.top>=0)
    {
        printf("\n");
        for(i=s.top;i>=0;i--)
            printf("%d-->",s.a[i]);

        printf("!");
    }
    else
    {
        printf("\nstack is empty\n");
    }
}

int main()
{
    int choice,ans;
    s.top=-1;


    printf("\nenter stack size: \n");
    scanf("%d",&n);

    while(choice!=5)
    {

             printf("\n1]push\n2]pop\n3]display\n4]peep\n5]exit---> enter your choice: ");
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
                display();
                break;
            }
        case 4:
            {
                peep();
                break;
            }
        default:
        {
            printf("enter value between 1 to 5::::::");
            scanf("%d",&choice);
        }
        }

    }


}
