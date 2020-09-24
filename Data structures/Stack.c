#include<stdio.h>

int stack[100],choice,n,top,x,i,b;
void push(void);
void pop(void);
void display(void);
int peep();

int main()
{
    //clrscr();
    top=-1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEP\n\t 5.EXIT");
    while(choice!=5)
    {
        printf("\n Enter the Choice:");
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
            		b=peep();
            		printf("%dth elements in stack is %d",b+1,stack[top-b]);
            	}
            case 5:
            {
                printf("\n\t EXIT POINT ");
                exit(0);
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n\n");
        for(i=top; i>=0; i--)
            printf("%d-->",stack[i]);
            
        printf("!");
        
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}

int peep()
{
	int m;
	printf("Enter the position of number: \n");
	scanf("%d",&m);
	
	if((top-m)<0 && m>top)
	   return 0;
	   
	else
	   return m-1;
}