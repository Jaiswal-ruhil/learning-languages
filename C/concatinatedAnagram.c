#include<stdio.h>
int main(){
  int n,len,total;
  scanf("%d",&n);
  do{
    char str[50];
    int arr[26]={0};
    len=total=0;
    scanf("%s",str);
    do
      if(len%2==0)
	printf("dealing with %c of string storing %d in arr \n",str[len/2],arr[str[len/2]-97]+=1);
    while(str[++len]);
    if(len%2==1)
      printf("-1\n");
    else{
      for(len/=2;str[len];len++)
	if((arr[str[len]-97]-=1)<0)
	  total+=1;
      printf("%d\n",total);
    }
  }while(--n);
  return 0;
}
