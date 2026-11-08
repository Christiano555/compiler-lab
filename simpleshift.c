#include <stdio.h>
#include <string.h>

int main()
{
    char stack[100], input[100];
    int top = -1, i = 0;

    printf("Enter expression: ");
    scanf("%s", input);
    strcat(input,"$");

    stack[++top] = '$';

    printf("\nSTACK\tINPUT\tACTION\n");

    while(input[i] != '$')
    {
        stack[++top] = input[i];
        stack[top+1] = '\0';

        printf("%s\t%s\tShift %c\n", stack, input+i+1,input[i]);
        i++;

        while(1)
        {
            if(stack[top] == 'i')
            {
                stack[top] = 'E';
                printf("%s\t%s\tReduce E->i\n", stack, input+i);
            }
            else if(top >= 2 && stack[top-2] == '(' &&
                    stack[top-1] == 'E' && stack[top] == ')')
            {
                top -= 2;
                stack[top] = 'E';
                stack[top+1] = '\0';
                printf("%s\t%s\tReduce E->(E)\n", stack, input+i);
            }
            else if(top >= 2 && stack[top-2] == 'E' &&
                    stack[top-1] == '+' && stack[top] == 'E')
            {
                top -= 2;
                stack[top] = 'E';
                stack[top+1] = '\0';
                printf("%s\t%s\tReduce E->E+E\n", stack, input+i);
            }
            else if(top >= 2 && stack[top-2] == 'E' &&
                    stack[top-1] == '*' && stack[top] == 'E')
            {
                top -= 2;
                stack[top] = 'E';
                stack[top+1] = '\0';
                printf("%s\t%s\tReduce E->E*E\n", stack, input+i);
            }
            else
                break;
        }
    }

    if(top == 1 && stack[top] == 'E')
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");

    return 0;
}