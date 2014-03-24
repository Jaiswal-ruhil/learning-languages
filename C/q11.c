/*Program 11
Design, develop, and execute a program in C to implement a doubly linked list where each node consists of integers. The program should support the following operations:
i. Create a doubly linked list by adding each node at the front.
ii. Insert a new node to the left of the node whose key value is read as an input.
iii. Delete the node of a given data if it is found, otherwise display appropriate message.
iv. Display the contents of the list.*/

#include<stdio.h>
#include<malloc.h>

struct node{
  int info;
  struct node *llink,*rlink;
}*first=0,*temp;

void insert_front(){
  temp=(struct node*)malloc(sizeof(struct node));
  temp->rlink=temp->llink=0;
  printf("Enter the item\n");
  scanf("%d",&temp->info);
  if(first==0)
    first=temp;
  else{
    temp->rlink=first;
    first->llink=temp;
    first=temp;
  }
}

void display(){
  temp=first;
  while(temp){
    printf("%d\n",temp->info);
    temp=temp->rlink;
  }
}

void insert_left(){
  int key;
  struct node *cur=first;
  printf("Enter the key\n");
  scanf("%d",&key);
  if(key==first->info)
    insert_front();
  else{
    while(cur->rlink!=0&&key!=cur->info)
      cur=cur->rlink;
    if(key==cur->info){
      temp=(struct node*)malloc(sizeof(struct node));
      temp->rlink=temp->llink=0;
      printf("Enter the item\n");
      scanf("%d",&temp->info);
      temp->llink=cur->llink;
      temp->rlink=cur;
      cur->llink->rlink=temp;
      cur->llink=temp;
    }
	else
      printf("key is not found\n");
  }
}

void del(){
  int item;
  temp=first;
  printf("Enter the item\n");
  scanf("%d",&item);
  if(first->info==item)
    first=first->rlink;
  else{
    while(temp->rlink!=0&&item!=temp->info)
      temp=temp->rlink;
    if(temp->info==item&&temp->rlink==0)
      temp->llink->rlink=0;
    else{
      if(temp->info==item){
        temp->llink->rlink=temp->rlink;
        temp->rlink->llink=temp->llink;
      }
      else{
        printf("Item does no found\n");
        return;
      }
    }
  }
  free(temp);
}

int main(){
  int ch;
  while(1){
    printf(" 1:insert front\n 2:display\n 3:insert left\n 4:delete\n 5:exit\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch){
    case 1:
	  insert_front();break;
    case 2:
	  if(first==0)
        printf("List is empty\n");
      else
        display();
      break;
    case 3:
	  if(first==0)
        printf("List is empty\n");
      else
        insert_left();
      break;
    case 4:
	  if(first==0)
        printf("List is empty\n");
      else
        del();
      break;
    default :
	  return(0);
    }
  }
}