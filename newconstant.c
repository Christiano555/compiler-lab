#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{
    int n,i,j,k,pos;
    char a[20],exp[20][30],temp[30];
    printf("Enter no.of expressions: ");
    scanf("%d",&n);

    printf("Enter the expressions:\n");
    for(i=0;i<n;i++)
    {
        scanf(" %c = %s",&a[i],exp[i]);
        strcpy(temp,"");
        for(k=0;exp[i][k]!='\0';k++)
        {
            pos=-1;
            if(isalpha(exp[i][k]))
            {
                for(j=0;j<i;j++)
                {
                    if(a[j]==exp[i][k])
                    {
                        pos=j;
                        break;
                    }
                }
            }
            if(pos!=-1)
            {
                strcat(temp,exp[j]);
            }
            else
            {
                int len=strlen(temp);
                temp[len]=exp[i][k];
                temp[len+1]='\0';
            }
        }
        strcpy(exp[i],temp);
    }

    printf("After Constant propogation:-\n");
    for(i=0;i<n;i++)
    {
        printf("%c = %s\n",a[i],exp[i]);
    }
}