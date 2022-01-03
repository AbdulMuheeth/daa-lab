#include<stdio.h>

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}


void floyds(int c[10][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i == j)
                    c[i][j] = 0;
                else
                    c[i][j] = min(c[i][j],c[i][k] + c[k][j]);
}

int main()
{
    int i,j,n,e,w,u,v;
    printf("\n Enter the number of vertices \n");
    scanf("%d",&n);
    printf("\n Enter the number of edges \n");
    scanf("%d",&e);
    int c[10][10];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            c[i][j] = 9999;
    
    printf("Enter the edge,weight of %d edges : ",e);
    for(i=1;i<=e;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        c[u][v] = w;
    }
    printf("\n Matrix of input data:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) printf("%d \t", c[i][j]);
        printf("\n");
    }
    floyds(c, n);
    printf("\n cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) printf("%d \t", c[i][j]);
        printf("\n");
    }
    printf("\n shortest paths are:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            if (i != j)
                printf("\nshortest path from %d to %d is %d", i, j, c[i][j]);
        }


    return 0;
}