#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[5],top=-1,x,i,n;

void push()
{
    if(top>=n-1)
    {
       printf("\nstack overflow\n");
    }
    else
    {
        printf("\nenter element :\n");
        scanf("%d",&x);
        top++;
        a[top]=x;
    }
}

void pop( )
{

    if(top<=-1)
    {
        printf("\nunderflow\n");
    }
    else
    {
         printf("\ndelete element is :%d",a[top]);
         top--;
    }

}

int peep()
{
    int m,y;
    printf("\nenter position to peep\n");
    scanf("%d",&m);

    if((top-m)<0  || m>top)
    {
        return 0;
    }
    else{

            return m-1;
        }
}

void display()
{
    int i;
    if(top>=0)
    {
        for(i=top;i>=0;i--)
            printf("%d-->",a[i]);

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
                if(ans>0)
                {

                ans=peep();
                printf("\npeeped element is %d\n",a[top-ans]);
                break;
                }
                else
                {
                    printf("\nstack is empty\n");
                }
        case 5:
            {
                return 0;
            }
            }
        default:
            {
                printf("enter proper choice::::: ");
                scanf("%d",&choice);

            }
        }

    }


}
