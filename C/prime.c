/*find the prime nos using open message passing*/

#include<stdio.h>
#include<omp.h>
#include<math.h>

int main(){
  int a[101],n,l,k,i;
  omp_set_num_threads(4);
  printf("enter value of n\n");
  scanf("%d",&n);
  for(i=2;i<=n;i++)
    a[i]=1;
  l=sqrt(n);
#pragma omp parallel private(k)
{
  for(k=2;k<=l;k++){
    if(a[k]!=0){
#pragma omp parallel for
      for(i=k*k;i<=n;i=i+k)
        a[i]=0;
      }
    }
  }
  printf("prime no are\n");
  for(i=2;i<=n;i++)
    if(a[i]==1)
      printf("%d\t",i);
  return 0;
}

