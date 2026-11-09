#include <stdio.h>
int e[20][20],visited[20],n,first;

void findclosure(int state)
{
    int i;
    visited[state]=1;
    if(first==1)
    {
        first=0;
    }
    else 
    {
        printf(",");
    }
    printf(" q%d ",state);
    for(i=0;i<n;i++)
    {
        if(e[state][i]==1 && visited[i]==0)
            findclosure(i);
    }
}

void main()
{
    int i,j;
    printf("Enter no.of states:- ");
    scanf("%d",&n);
    printf("Enter the epsilon transition table:-\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&e[i][j]);
        }
    }
    printf("Epsilon closures:-\n");
    for(i=0;i<n;i++)
    {
        printf("E-closure(q%d)={ ",i);
        for(j=0;j<n;j++)
        {
            visited[j]=0;
        }
        first=1;
        findclosure(i);
        printf(" }\n");
    }
}