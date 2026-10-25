#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char input[30];
int pos=0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void error()
{
    printf("Invalid Expression\n");
    exit(1);
}

void match(char expect)
{
    if(input[pos]==expect)
        pos++;
    else
        error();
}

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if(input[pos]=='+')
    {
        match('+');
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if(input[pos]=='*')
    {
        match('*');
        F();
        Tprime();
    }
}

void F()
{
    if(isalpha(input[pos]))
        pos++;
    else if(input[pos]=='(')
    {
        match('(');
        E();
        match(')');
    }
    else
        error();
}

void main()
{
    printf("Enter the input expression:- ");
    scanf("%s",input);
    E();

    if(input[pos]=='\0')
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");
}