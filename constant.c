#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int n,i,j,value[20],flag[20];
    char a[20][10],b[10];
    printf("Enter no.of expressions:- ");
    scanf("%d",&n);
    printf("Enter the expressions:-\n");

    for(i=0;i<n;i++)
    {
        scanf("%s = %s",a[i],b);
        flag[i]=0;
        if(b[0]>='0' && b[0]<='9')
        {
            value[i]=atoi(b);
            flag[i]=1;
        }
        else
        {
            for(j=0;j<i;j++)
            {
                if(strcmp(a[j],b)==0 && flag[j]==1)
                {
                    value[i]=value[j];
                    flag[i]=1;
                    break;
                }
            }
        }
    }
    printf("After Constant Propogation:-\n");
    for(i=0;i<n;i++)
    {
        if(flag[i]==1)
        {
            printf("%s = %d\n",a[i],value[i]);
        }
        else
        {
            printf("%s = variable\n",a[i]);
        }
    }
}