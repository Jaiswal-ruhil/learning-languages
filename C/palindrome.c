#include<stdio.h>
#include<stdlib.h>
#define maxsize 50

int main(){
  int i,n;
  char a[maxsize];
  n=0;
  printf("\nenter the number :  ");
  scanf("%[0,1,2,3,4,5,6,7,8,9]s",a);
  while(a[n++]);
  for(i=0,n-=2;i<n;)
    if(a[i++]!=a[n--]){
      printf("\nthe number %s is not palindrome\n\n",a);
      return;
    }
  printf("\nnumber %s is palindrome\n\n",a);
  return;
}
