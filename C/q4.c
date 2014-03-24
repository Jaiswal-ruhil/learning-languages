/*Program 4
Design, develop, and execute a program in C to simulate the working of a queue of integers using an array. Provide the following operations: a. Insert b. Delete c. Display
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
int f=-1,r=-1,q[MAXSIZE];

void rear_insert(){
  int item;
  if(r==MAXSIZE-1){
    printf(" full\n");
    return;
  }
  printf("enter the item to be pushed\n");
  scanf("%d",&item);
  q[++r]=item;
  if(f=-1)
    f++;
}

void front_delete(){
  int item;
  if(f>r)
    f=r=-1;
  if(f==-1){
    printf("q empty\n");
    return;
  }
  item=q[f++];
  printf("the deleted item is %d",item);
}

void display(){
  int i;
  printf("q contents are\n");
  for (i=f;i<=r;i++)
    printf("%d\n",q[i]);
}

int main(){
  int ch,yes=1;
  while(yes){
    printf("\n 1:rear insert\n 2:front delete\n 3:display\n 4:exit\n");
    printf("Enter the choice\n");
    scanf("%d",&ch);
    switch(ch){
    case 1:
	  rear_insert();
	  break;
    case 2:
	  front_delete();
	  break;
    case 3:
	  display();
	  break;
    default :exit(0);
    }
    printf("if u want to continue press 1 or 0\n");
    scanf("%d",&yes);
  }
}