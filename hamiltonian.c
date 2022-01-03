#include<stdio.h>

int g[10][10],x[10],c=0,n;

void nextvalue(int k)
{
    int i;
	while(1)
	{
		
		x[k] = (x[k]+1)%(n+1); // considering the next to be adjacent index of the previous index (for start it is 1)

		if(x[k] == 0)
			return;
		
		if(g[x[k-1]][x[k]] !=0 )
		{
			for(i=1;i<k;i++)
			{
				if(x[i] == x[k])
					break;
			}
			
			if(i==k)
			{
				if( (k<n) || (k==n && g[x[k]][x[1]] != 0))
					return;
			}
		}
	}
	
}

void displaycycle()
{
	for(int i=1;i<=n;i++)
		printf("%d ",x[i]);
	printf("%d",x[1]);
	printf("\n");
}

void hamiltoniancycle(int k)
{
	while(1)
	{
		nextvalue(k);
		
		if(x[k]==0)
			return;
			
		if(k==n)
		{
			c++;
			displaycycle();
		}
		else
		{
			hamiltoniancycle(k+1);	
		}
	}
	
}


int main()
{
	printf("Enter the no.of vertices: ");
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//printf("Enter the edge of g[%d][%d]: ",i,j);
			scanf("%d",&g[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++)
		x[i]=0;
	
	x[1]=1;
	printf(" Possible hamiltonian cycles are: \n");
	
	hamiltoniancycle(2);
	
	printf("Total number of solutions are: %d",c);
	if(c == 0)
	    printf("\n solutions not possible");
	
	return 0;
}
