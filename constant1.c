#include <stdio.h>
#include<string.h>

void main()
{
    int i,j,n,pos,k,len;
    char a[20],exp[20][20],temp[20];
    printf("Enter no.of expressions: ");
    scanf("%d",&n);
    printf("Enter the expressions:-\n");
    for(i=0;i<n;i++)
    {
        scanf(" %c = %s",&a[i],exp[i]);
        strcpy(temp,"");
        for(k=0;exp[i][k]!='\0';k++)
        {
            pos=-1; 
            for(j=0;j<i;j++)
            {
                if(a[j]==exp[i][k])
                {
                    pos=j;
                    break;
                }
            }
            if(pos!=-1)
            {
                strcat(temp,exp[j]);
            }
            else
            {
                len=strlen(temp);
                temp[len]=exp[i][k];
                temp[len+1]='\0';
            }
        }
        strcpy(exp[i],temp);
    }
    printf("After constant ropogation\n");
    for(i=0;i<n;i++)
    {
        printf("%c = %s\n",a[i],exp[i]);
    }
}