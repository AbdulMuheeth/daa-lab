#include<stdio.h>
int x[30],count=0;

int abs(int x)
{
    if(x < 0)
        return -1*x;
    return x;
}

int place(int pos)
{
    int i=0;
    for(i=1;i<pos;i++)
    {
        if( (x[i] == x[pos]) || ( abs(x[i]-x[pos]) == abs(i-pos) ))
            return 0;
    }
    return 1;
}

int printboard(int n)
{
    count++;

    printf("solution-%d\n",count);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i] == j)
                printf("Q%d\t",i);
            else
                printf("* \t");
        }
        printf("\n");
    }
}

int queen(int n)
{
    int k=1;
    while(k!=0)
    {
        x[k] = x[k]+1;
        while((x[k] <= n) && !place(k)) x[k]++;
        if(x[k]<=n)
        {
            if(k==n)
                printboard(n);
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
            k--;
    }
}

int main()
{
    int i, n;
    printf("enter the number of queens..:");
    scanf("%d", &n);
    queen(n);
    printf("\npossible solutions..: %d", count);

    return 0;
}