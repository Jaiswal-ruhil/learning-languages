#include<stdio.h>
#include<stdlib.h>
#define inf ~0

void kruskals(unsigned long int **arr,unsigned long int n)
{
	unsigned long int *p,min,mincost,i,j,u,v,x,y,count;
	p=(unsigned long int *)calloc(n+1,sizeof(unsigned long int));
	mincost=0;
	count=--n;
	while(count)
	{
		min=inf;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(arr[i][j]<min)
				{
					min=arr[i][j];
					u=x=i;
					v=y=j;
				}
		while(p[u]) u=p[u];
		while(p[v]) v=p[v];
		if(u!=v)
		{
			mincost+=min;
			p[v]=u;
			--count;
		}
		arr[i][j]=arr[j][i]=inf;
	}
	printf("\n\n The minnimum cost is : %lu",mincost);
	free(arr);
	free(p);
}


int main()
{
	unsigned long int **arr,*block,i,j,n,try;
	printf("\n\nPlease enter the no of nodes :  ");
	scanf("%lu",&n);
	if(!(block=(unsigned long int *)calloc(n+1,sizeof(unsigned long int))))
	{
		printf("\nfailed to create block");
		exit(0);
	}
	if(!(arr=(unsigned long int **)calloc(n+1,sizeof(block))))
	{
		printf("failed to crate arr");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
        for(j=0;j<i;j++)
		{
			//printf("(%d -> %d) :  ",i,j);
			//scanf("%lu",&arr[i][j]);
			//arr[j][i]= ((arr[i][j]) ? arr[i][j]: (arr[i][j]=inf));
            arr[j][i]= arr[i][j]=random();
        }
        printf("\n\ntest till here\n\n");
        arr[i][j]=inf;//err line ??
        printf("\n\ntest till here2\n\n");
    }
    kruskals(arr,n);
    free(arr);
    free(block);
    return 0;
}
