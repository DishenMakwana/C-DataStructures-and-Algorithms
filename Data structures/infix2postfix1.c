#include<stdio.h>
#include<conio.h>

char stack[100],string[100],result[100];
int top=-1,i=0,j=0;

int push(char );
char pop();
int f(int );


void main()
{
    char pp;
    top++;
    stack[top]='#';

    printf("Enter the expression: ");
    gets(string);


    while(string[i]!='\0')
    {
        while(f(string[i]) <= f(stack[top]) )
        {
            pp=pop();
            result[j]=pp;
            j++;
        }
        push(string[i]);

        i++;
    }

    while(top>0)
    {
        result[j]=stack[top];
        j++;
        top--;
    }
        printf("Postfix expression: ");
        printf("%s",result);

    getch();
}

int f(int ch)
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

int push(char x)
{
    top++;
    stack[top]=x;
}

char pop()
{
    char c;
    c=stack[top];
    top--;
    return c;
}
