#include<stdio.h>
int main(){
  int n,no,numtoprint,max,arr[201]={0};
  scanf("%d",&n);
  scanf("%d",&no);
  max=arr[no+100]=1;
  numtoprint=no;
  while(--n){
    scanf("%d",&no);
    if(max<(arr[no+100]+=1)){
      max=arr[no+100];
      numtoprint=no;
    }
  }
  printf("%d",numtoprint);
  return 0;
}
