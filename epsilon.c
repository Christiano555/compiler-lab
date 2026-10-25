#include <stdio.h>

int n;
int closure[20][20];
int visited[20];

void epsilon(int state)
{
    int i;
    visited[state]=1;
    printf("q%d ",state);
    for(i=0;i<n;i++)
    {
        if(closure[state][i]==1 && visited[i]==0)
            epsilon(i);
    }

}

void main()
{
    int i,j;
    printf("Enter no.of states:-\n");
    scanf("%d",&n);
    printf("Enter the epsilon transition table of the NFA\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&closure[i][j]);
        }
    }

    printf("EPSILON CLOSURES:-\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            visited[j]=0;

        printf("E-closure(q%d)={ ",i);
        epsilon(i);
        printf(" }\n");
    }
}