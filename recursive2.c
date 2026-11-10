// S->aSb/E//
#include<stdio.h>
#include<stdlib.h>
char input[100];
int i=0;
void s();

void s()
{
    if(input[i]=='a')
    {
        i++;
        s();
        if(input[i]=='b')
        {
            i++;
        }
        else
        {
            printf("Invalid expression\n");
            exit(1);
        }
    }
}

void main()
{
    printf("Enter the expression:- ");
    scanf("%s",input);
    s();

    if(input[i]=='\0')
    {
        printf("String accepted\n");
    }
    else
    {
        printf("String rejected\n");
    }
}