#include<stdio.h>
int max,min;
int a[100];


void maxmin(int l,int e)
{
    if(l==e)
    {
        max=a[l];min=a[e];
    }
    else if(l==e-1)
    {
        if(a[l]>a[e])
        {
            max = a[l];
            min = a[e];
        }
        else
        {
            max = a[e];
            min = a[l];
        }
    }
    else
    {
        int mid = (l+e)/2;
        maxmin(l,mid);
        // int max1 = max,min1 = min;
        maxmin(mid+1,e);
        // if(max1>max) max = max1;
        // if(min1<min) min = min1;
    }
}



int main()
{
    int n;
    printf("Enter the length of array : ");
    scanf("%d",&n);
    printf("Enter the elements of an array : ");
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    max = -1;
    min = 9999;
    maxmin(1,n);
    printf("Maximum from the array is : %d",max);
    printf("Minimum from the array is : %d",min);

    return 0;
}