//not working
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#define size 50
char s[size];
int top=-1;

void push(char x)
{
    s[++top]=x;
}

char pop()
{
   return (s[top--]);
}

int f(char ch)
{
    switch(ch)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    }
}

void main()
{
    char infx[100],pofx[100],ch,ele,top=-1;
    int i=0,k=0;
    printf("Enter String:-> ");
    gets(infx);
    push('#');

    while( (ch=infx[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            pofx[k++]=ch;
        }
        else if(ch==')')
        {
            while(s[top]!='(')
            {
                pofx[k++]=pop();
            }
            ele=pop();
        }
        else
        {
            while( f(s[top]) >= f(ch) )
            {
                pofx[k++]=pop();
            }
            push(ch);
        }
    }
    while(s[top]!='#')
    {
        pofx[k++]=pop();
    }
    pofx[k]='\0';
    printf("Postfix expression:-> %s",pofx);
    getch();
}
