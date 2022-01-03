#include<stdio.h>

void knapsack(float weight[],float profit[],int n,int capacity)
{
    float bag[20],totalProfit=0.0,remaining_weight = capacity;
    int i=0;

    for(i=0;i<20;i++)
        bag[i]=0.0;

    for(i=0;i<n;i++)
    {
        if(remaining_weight >= weight[i])
        {
            totalProfit += profit[i];
            remaining_weight -= weight[i];
            bag[i] = 1.0;
        }
        else
        {
            if(remaining_weight > 0)
            {
                bag[i] = (float) (remaining_weight/weight[i]);
                totalProfit += (bag[i]*profit[i]);
                remaining_weight = 0;
            }
            else    break;
        }
    }
    printf("Max profit is : %f",totalProfit);
}

int main()
{
    float weight[20],profit[20],capacity;
    int n,i,j;
    float ratio[20],t;
    
    printf("\n enter the capacity of knapsack...");
    scanf("%f",&capacity);
    
    printf("\n Toal no of objects...");
    scanf("%d",&n);

    printf("\n Enter the weights and profits of each object...");
    for (i=0;i<n;i++)
        scanf("%f %f",&weight[i],&profit[i]);
    
    for (i=0;i<n;i++)
        ratio[i]=profit[i]/weight[i];

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i] < ratio[j])
            {
                t = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = t;

                t = weight[j];
                weight[j] = weight[i];
                weight[i] = t;

                t = profit[j];
                profit[j] = profit[i];
                profit[i] = t;
            }

        }
    }

    knapsack(weight,profit,n,capacity);
}