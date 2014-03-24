#include<stdio.h>

int main(){
  int m,n,run,i,j,u,v,arr[5][5];
  scanf("%d %d",&m,&n);
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      scanf("%d",&arr[i][j]);
  run=m*n-n;
  for(j=0;j<n;j++)
    printf("%d ",arr[0][j]);
  do{
    
    while(i++<m)arr[i][j];
    while()
  }while(--run);
}