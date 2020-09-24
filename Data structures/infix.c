#include<stdio.h>
#include<conio.h>

char str1[100],result[100],str2[100],y;
int w,top,i,k,top=-1, j=0,i=0;

int f(char );
void push(char );
char pop();
void display();

void main()
{
    top++;
    str2[top]='#';
    char pp;
    printf("Enter the expression:");
    gets(str1);

    while(str1[i]!='\0')
    {
        while( f(str1[i]) <= f(str2[top]) )
        {
            pp=pop();
            result[j]=pp;
            j++;
        }
        push(str1[i]);
        i++;
    }
    while(top>0)
    {
        result[j]=str2[top];
        top--;
        j++;
    }
    printf("\npostfix expression:");
    printf("%s",result);
}

int f(char ch)
{
    switch(ch)
    {
    case '#':
        return 0;

    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;

    default:
        return 4;
    }
}

void push(char y)
{
        str2[++top]=y;
}

char pop()
{
         char c;
         c= str2[top];
         top--;
         return c;
}
