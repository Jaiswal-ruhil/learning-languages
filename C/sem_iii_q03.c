/*
 * Design develop and execut a program in C
 * convert a infix expression to postfix
 * print both postfix and prefix expression
 */

#include<stdio.h>
#include<string.h>

typedef struct node *previous,*current;

typedef struct{
  char val;
  node *leftnode,*rightnode;
}node;

int postfix(node *ptr){
  if(ptr){
    postfix(ptr->leftnode);
    postfix(ptr->rightnode);
    printf("%c",prt->val);
  }
}

int main(){
  char infix[20],postfix[20];
  printf("\nPlease input the infix expression\n\t---->   ");
  scanf("%s",infix);
  infix_postfix(infix,0,0);
  printf("\n");
}
