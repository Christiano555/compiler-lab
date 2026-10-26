#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int n,i,j,k,e[20][20],trans[20][20],changed;
    int closure[20][20]={0};
    int result[20][20]={0};

    printf("Enter no.of states:- ");
    scanf("%d",&n);
    printf("Enter the epsilon transition table :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&e[i][j]);
        }
    }
    printf("Enter the NFA transition table:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&trans[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        closure[i][i]=1;
        changed=1;
        while(changed==1)
        {
            changed=0;
            for(j=0;j<n;j++)
            {
                if(closure[i][j]==1)
                {
                    for(k=0;k<n;k++)
                    {
                        if(e[j][k]==1 && closure[i][k]==0)
                        {
                            closure[i][k]=1;
                            changed=1;
                        }
                    }
                }
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(closure[i][j]==1)
            {
                for(k=0;k<n;k++)
                {
                    if(trans[j][k]==1)
                    {
                        result[i][k]=1;
                    }
                }
            }
        }
    }
    printf("NFA without E-transition:\n");
    for(i=0;i<n;i++)
    {
        printf("q%d -> ",i);
        for(j=0;j<n;j++)
        {
            if(result[i][j]==1)
                printf("q%d ",j);
        }
        printf("\n");
    }
}