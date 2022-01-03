#include<stdio.h>

int g[10][10];
int x[10];
int c=0,n,m,sol=0;

void nextvalue(int k);
void graphcoloring(int k);


int main()
{
    int i, j, t;
    printf("\n enter the number of vertices in a graph: ");
    scanf("%d", &n);
    printf("\n enter graph edges\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    printf("All Posssible Solutions are:");
    for(m=1;m<=n;m++)
    {
        if(c==1)
            break;
        graphcoloring(1);
    }

    printf("\n chromatic number is %d", m - 1);
    printf("\n total number of solutions is %d", sol);

    return 0;
}

void graphcoloring(int k)
{
    int i;
    while(1)
    {
        nextvalue(k);
        if(x[k]==0)
            return;
        else if(k == n)
        {
            c = 1;
            for(i = 1;i<=n;i++)
                printf("%d ",x[i]);
            sol++;
            printf("\n");
        }
        else
            graphcoloring(k+1);
    }
}

void nextvalue(int k)
{
    int j;
    while(1)
    {
        x[k] = (x[k]+1) % (m+1);
        if (x[k] == 0) 
            return;
            
        for (j = 1; j <= n; j++) 
        {
            if (g[k][j] == 1 && x[k] == x[j]) break;
        }
        if (j == (n + 1))
            return;
    }
}