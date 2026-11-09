#include <stdio.h>
#include <stdlib.h>

void main()
{
    int closure[20][20]={0},e[20][20],trans[20][20],result[20][20];
    int i,k,j,l,n,change;

    printf("Enter the no.of states");
    scanf("%d",&n);
    printf("Enter the epsilon table:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&e[i][j]);
        }
    }
    printf("Enter the transition table:-\n");
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
        change=1;
        while(change==1)
        {
            change=0;
            for(j=0;j<n;j++)
            {
                if(closure[i][j]==1)
                {
                    for(k=0;k<n;k++)
                    {
                        if(e[j][k]==1 && closure[i][k]==0)
                        {
                            closure[i][k]=1;
                            change=1;
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
                        for(l=0;l<n;l++)
                        {
                            if(closure[k][l]==1)
                            {
                                result[i][l]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("NFA without E-transition:-\n");
    for(i=0;i<n;i++)
    {
        printf("q%d = { ",i);
        for(j=0;j<n;j++)
        {
            if(result[i][j]==1)
            {
                printf(" q%d",j);
                if(j<n-1)
                {
                    printf(", ");
                }
            }
           
        }
        printf(" }\n");
    }

}