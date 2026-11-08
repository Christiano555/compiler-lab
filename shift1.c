/*S → AB
A → aA
A → a
B → bB
B → b*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
    char stack[100],input[100];
    int i=0,top=-1;
    printf("Enter the expression: ");
    scanf("%s",input);
    strcat(input,"$");
    stack[++top]='$';
    printf("\nstack\tinput\taction\n");
    while(input[i]!='$')
    {
        stack[++top]=input[i];
        stack[top+1]='\0';

        printf("%s\t%s\t shift %c\n",stack,input+i+1,input[i]);
        i++;

        while(1)
        {
            if(stack[top]=='a' && input[i]!='a')
            {
                stack[top]='A';
                stack[top+1]='\0';
                printf("%s\t%s\t reduce a->A\n",stack,input+i);
            }
            else if(stack[top]=='b'&& input[i]!='b')
            {
                stack[top]='B';
                stack[top+1]='\0';
                printf("%s\t%s\t reduce b->B\n",stack,input+i);
            }
            else if(top>=1&&stack[top]=='B'&&stack[top-1]=='A')
            {
                top=top-1;
                stack[top]='S';
                stack[top+1]='\0';
                printf("%s\t%s\t reduce AB-> S\n",stack,input+i);
            }
            else if(top>=1&&stack[top]=='A'&&stack[top-1]=='a')
            {
                top=top-1;
                stack[top]='A';
                stack[top+1]='\0';
                printf("%s\t%s\t reduce aA-> A\n",stack,input+i);
            }
            else if(top>=1&&stack[top]=='B'&&stack[top-1]=='b')
            {
                top=top-1;
                stack[top]='B';
                stack[top+1]='\0';
                printf("%s\t%s\t reduce bB-> B\n",stack,input+i);
            }
            else
                break;
        }
    }
    if(top==1 && stack[top]=='S')
        printf("Accepted\n");
    else    
        printf("Rejected");
}