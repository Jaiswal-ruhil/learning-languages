/*Program 10
Design, develop, and execute a program in C to create a max heap of integers by accepting one element at a time and by inserting it immediately in to the heap. Use the array representation for the heap. Display the array at the end of insertion phase.
*/

#include<stdio.h>
#define MAX 5
int count=0,a[MAX];

void insert2heap(int key){
  int c,p;
  if(count==MAX){
    printf("heap is full\n");
    return;
  }
  c=count;
  p=(c-1)/2;
  while(c!=0&&key>a[p]){
    a[c]=a[p];
    c=p;
    p=(c-1)/2;
  }
  a[c]=key;
  count++;
}

void display(){
  int i;
  printf("elements in the heap are\n");
  for(i=0;i<count;i++)
    printf("a[%d]=%d\n",i,a[i]);
}

int main(){
  int key;
  count=0;
  while(1){
    printf("enter the key to insert");
    printf("\n enter -999 to exit\n");
    scanf("%d",&key);
    if(key==-999)
      return;
    else
      insert2heap(key);
    display();
  }
}