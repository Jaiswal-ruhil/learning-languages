#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define MAX 30

double nonparallel();
double parallel();
int main()
{
	printf("%lf\n",parallel()-nonparallel());
}
double nonparallel()
{
	int i,j,k,a[MAX][MAX],b[MAX][MAX],c[MAX][MAX]={0};
	double clk=clock();
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++){
			a[i][j]=rand(10);
			b[i][j]=rand(10);
		}
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			for(k=0;k<MAX;k++)
				c[i][j]+=a[i][k]*b[k][j];
/*	for(i=0;i<MAX;i++)
		for(j=0,printf("\n");j<MAX;j++)
			printf("\t %d",c[i][j]);
	*/return clock()-clk;
}
double parallel()
{
	int i,j,k,a[MAX][MAX],b[MAX][MAX],c[MAX][MAX]={0};
	double clk=clock();
	omp_set_num_threads(2);
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++){
			a[i][j]=rand(10);
			b[i][j]=rand(10);
		}
	#pragma omp parallel for
	for(i=0;i<MAX;i++)
		for(j=0;j<MAX;j++)
			for(k=0;k<MAX;k++)
				c[i][j]+=a[i][k]*b[k][j];
/*	for(i=0;i<MAX;i++)
		for(j=0,printf("\n");j<MAX;j++)
			printf("\t %d",c[i][j]);
*/	return clock()-clk;
}
