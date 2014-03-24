/*
 * Add 2 array and store in the 3rd using open message passing technique
 */

#include<stdio.h>
#include<alloc.h>
#include<omp.h>

int main(){
  int *a,*b,*c,i,n;
  omp_set_num_threads(4);
  printf("entr the length of array\n");
  scanf("%d",&n);
  printf("enter the element of array a\n");
  a=(int *)malloc(n,sizeof(int));
  b=(int *)malloc(n,sizeof(int));
  c=(int *)malloc(n,sizeof(int));
  for(i=0;i<n;i++){
    printf("a[%d]=",i);
    scanf("%d",&a[i]);
  }

  printf("enter the element of array b\n");
  for(i=0;i<n;i++){
    printf("b[%d]=",i);
    scanf("%d",&b[i]);
  }

#pragma omp parallel for
  for(i=n;i>-0;--i){
    printf("\nc[%d]=%d,thread_id=%d",i,c[i],omp_get_thread_num());
    c[i]=a[i]+b[i];
  }
  printf("\narray c is\n ");
  for(i=0;i<n;i++)
    printf("\nc[%d]=%d",i,c[i]);
  return 0;
}
