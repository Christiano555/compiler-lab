#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char result[10],arg1[10],ch,arg2[10];
    FILE *fp;
    fp=fopen("input1.txt","r");
    if(fp==NULL)
    {
        printf("File not found\n");
        exit(1);
    }
    while((fscanf(fp,"%s = %s %c %s",result,arg1,&ch,arg2)==4))
    {
        printf("MOV AX,%s\n",arg1);
        if(ch=='+')
        {
            printf("ADD AX,%s\n",arg2);
        }
        else if(ch=='-')
        {
            printf("SUB AX,%s\n",arg2);
        }
        else if(ch=='*')
        {
            printf("MOV BX,%s\n",arg2);
            printf("MUL BX\n");
        }
        else if(ch=='/')
        {
            printf("MOV BX,%s\n",arg2);
            printf("XOR DX,DX\n");
            printf("DIV BX\n");
        }
        else
            continue;
        printf("MOV %s,AX\n\n",result);
    }
    fclose(fp);
}