#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char c)
{
if(c == '+' || c == '-')
return 1;
return 2;
}

int main()
{
char infix[50], postfix[50];
char stack[50], s[50][10];
char c, a[10], b[10], result[10];
int top = -1, top2 = -1;
int i, j = 0, temp = 1;

```
printf("Enter expression: ");
scanf("%s", infix);

/* Infix to Postfix */

for(i = 0; infix[i] != '\0'; i++)
{
    c = infix[i];

    if(isalnum(c))
        postfix[j++] = c;

    else if(c == '(')
        stack[++top] = c;

    else if(c == ')')
    {
        while(top != -1 && stack[top] != '(')
            postfix[j++] = stack[top--];

        if(top == -1)
        {
            printf("Invalid expression\n");
            return 0;
        }

        top--;
    }
    else if(c == '+' || c == '-' || c == '*' || c == '/')
    {
        while(top != -1 && stack[top] != '(' &&
              precedence(stack[top]) >= precedence(c))
            postfix[j++] = stack[top--];

        stack[++top] = c;
    }
    else
    {
        printf("Invalid expression\n");
        return 0;
    }
}

while(top != -1)
{
    if(stack[top] == '(')
    {
        printf("Invalid expression\n");
        return 0;
    }

    postfix[j++] = stack[top--];
}

postfix[j] = '\0';

/* Intermediate Code */

printf("\nIntermediate Code:\n");

for(i = 0; postfix[i] != '\0'; i++)
{
    c = postfix[i];

    if(isalnum(c))
    {
        s[++top2][0] = c;
        s[top2][1] = '\0';
    }
    else
    {
        if(top2 < 1)
        {
            printf("Invalid expression\n");
            return 0;
        }

        strcpy(b, s[top2--]);
        strcpy(a, s[top2--]);

        sprintf(result, "t%d", temp++);

        printf("%s = %s %c %s\n", result, a, c, b);

        strcpy(s[++top2], result);
    }
}

if(top2 != 0)
{
    printf("Invalid expression\n");
    return 0;
}

printf("Result = %s\n", s[top2]);

return 0;

}
