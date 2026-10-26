#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[20];
int top=-1;
char *remaininput;

void push(char c)
{
    stack[++top]=c;
    stack[top+1]='\0';
}

void showinput(char *input,int pos)
{
    if(input[pos]=='\0')
        printf("$");
    else
    {
        printf("%s",input+pos);
    }
}

int reduce()
{
    if(top>=0 && stack[top]=='i')
    {
        stack[top]='E';
        stack[top+1]='\0';
        printf("%-10s %-10s reduce i->E\n",stack,remaininput);
        return 1;
    }
    if(top>=2 && stack[top-2]=='(' && stack[top-1]=='E' && stack[top]==')')
    {
        top=top-2;
        stack[top]='E';
        stack[top+1]='\0';
        printf("%-10s %-10s reduce (E)->E\n",stack,remaininput);
        return 1;
    }
    if(top>=2 && stack[top-2]=='E' && stack[top-1]=='+' && stack[top]=='E')
    {
        top=top-2;
        stack[top]='E';
        stack[top+1]='\0';
        printf("%-10s %-10s reduce E+E->E\n",stack,remaininput);
        return 1;
    }
    if(top>=2 && stack[top-2]=='E' && stack[top-1]=='*' && stack[top]=='E')
    {
        top=top-2;
        stack[top]='E';
        stack[top+1]='\0';
        printf("%-10s %-10s reduce E*E->E\n",stack,remaininput);
        return 1;
    }
    return 0;
}

void main()
{
    char input[20];
    int i=0;
    printf("enter the expression :- ");
    scanf("%s",input);

    printf("\n%-10s %-10s %-10s\n","Stack","Input","Action");

    while(input[i]!='\0')
    {
        push(input[i]);
        printf("%-10s ",stack);
        remaininput=input+i+1;
        showinput(input,i+1);
        printf("        shift %c\n",input[i]);
        i++;

        while(reduce())
        {

        }
    }
    if(top==0 && stack[0]=='E')
    {
        printf("%-10s %-10s %-10s\n",stack,"$","Accept");
        printf("Accepted\n");
    }
    else
    {
        printf("%-10s %-10s %-10s\n",stack,"$","Reject");
        printf("Rejected\n");
    }
}