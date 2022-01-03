#include<stdio.h>

int s[10],d,n,set[10],count=0;
void display(int);
int subset(int,int);
int flag = 0;

int main()
{
    int i;
    printf("Enter the number of elements in the set");
    scanf("%d",&n);
    printf("Enter the set values\n");
    for (i = 0; i < n; ++i) scanf("%d", &s[i]);
    printf("enter the sum");
    scanf("%d",&d);
    printf("The program output is \n");
    subset(0,0);
    if(flag == 0) printf("there is no solution");

    return 0;
}

void display(int count) {
    int i;
    printf("{");
    for (i = 0; i < count; i++) printf("%d ", set[i]);
    printf("}");
}


int subset(int sum,int pos)
{
    if(sum == d)
    {
        flag = 1;
        display(count);
        return 0;
    }
    else if( sum > d || pos>=n)
        return 0;
    else
    {
        set[count] = s[pos];
        count++;
        subset(sum+s[pos],pos+1);
        count--;
        subset(sum ,pos+1);
    }
}
