//  Construct a recursive descent parser for an expression
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char input[100];
int i=0;

void E()
{
    T();
    E1();
}



void E1()
{
    if(input[i]=='+')
    {
        i++;
        T();
        E1();
    }
}

void T()
{
    F();
    T1();
}

void T1()
{
    if(input[i]=='*')
    {
        i++;
        F();
        T1();
    }
}

void F()
{
    if(isalnum(input[i]))
        i++;
    else if(input[i]=='(')
    {
        i++;
        E();
        if(input[i]==')')
            i++;
        else
        {
            printf("Invalid expression\n");
            exit(0);
        }
    }
    else
    {
        printf("Invalid expression\n");
        exit(0);
    }
}

void main()
{
    printf("Enter the expression");
    scanf("%s",input);
    E();
    if(strlen(input)==i)
        printf("Valid expression \n");
    else
        printf("Invalid expression \n" );
}
