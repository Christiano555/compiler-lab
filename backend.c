#include <stdio.h>
#include <string.h>

void main()
{
    FILE *fp;
    char result[20],arg1[20],arg2[20];
    char op;
    fp=fopen("input.txt","r");

    printf("ASSSEMBLY INSTRUCTION\n\n");
    while(fscanf(fp,"%s = %s %c %s",result,arg1,&op,arg2)==4)
    {
        printf("MOV AX,%s \n",arg1);

        if(op == '+')
            printf("ADD AX,%s \n",arg2);
        else if(op=='-')
            printf("SUB AX,%s \n",arg2);
        else if(op=='*')
            printf("MUL %s \n",arg2);
        else if(op=='/')
            printf("DIV %s \n",arg2);

        printf("MOV %s,AX \n\n",result);
    }
    fclose(fp);
}

