#include <stdio.h>
#include <stdlib.h>

char input[100];
int i=0;

void E();
void A();
void B();

void E()
{
    if(input[i]=='a')
    {
        i++;
        A();
    }
    else if(input[i]=='b')
    {
        i++;
        B();
    }
    else
    {
        printf("Invalid expression\n");
        exit(1);
    }
}

void A()
{
    if(input[i]=='c')
    {
        i++;
        A();
    }
    else if(input[i]=='d')
    {
        i++;
    }
    else
    {
        printf("Invalid Expression\n");
        exit(1);
    }
}

void B()
{
    if(input[i]=='e')
    {
        i++;
        B();
    }
    else if (input[i]=='f')
    {
        i++;
    }
    else
    {
        printf("Invalid expression\n");
        exit(1);
    }
}

void main()
{
    printf("Enter the expression : ");
    scanf("%s",input);
    E();

    if(input[i]=='\0')
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }
}