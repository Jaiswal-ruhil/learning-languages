/*
Program 1
Using circular representation for a polynomial, design, develop, and execute a program in C to accept two polynomials, add them, and then print the resulting polynomial.
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

struct node{
  int coef,exp;
  struct node *link;
};

typedef struct node *NODE;

NODE attach (int coef,int exp,NODE head){
  NODE temp,temp2;
  temp=malloc(sizeof(temp));
  temp->coef=coef;
  temp->exp=exp;
  temp2=head->link;
  while(temp2->link!=head)
    temp2=temp2->link;
  temp2->link=temp;
  temp->link=head;
  return head;
}

NODE readpoly(NODE head){
  int i,n,coef,exp;
  printf("\n Enter the number of terms in polynomial:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("\nCoefficient:");
    scanf("%d",&coef);
    printf("Exponent:");
    scanf("%d",&exp);
    head=attach(coef,exp,head);
  }
  return head;
}

NODE polyadd(NODE headA,NODE headB,NODE headC){
  NODE a,b;
  int coef,z;
  a=headA->link;
  b=headB->link;
  while(a!=headA&& b!=headB){
    if((a->exp) > (b->exp))
      z=1;
    else if((a->exp)==(b->exp))
      z=0;
    else
      z=3;
    switch(z){
    case 0:
      coef=a->coef+b->coef;
      if(coef!=0)
        headC=attach(coef,a->exp,headC);
      a=a->link;
      b=b->link;
      break;
    case 1:
      headC=attach(a->coef,a->exp,headC);
      a=a->link;
      break;
    case 3:
      headC=attach(b->coef,b->exp,headC);
      b=b->link;
      break;
    }
  }
  while(a!=headA){
    headC=attach(a->coef,a->exp,headC);
    a=a->link;
  }
  while(b!=headB){
    headC=attach(b->coef,b->exp,headC);
    b=b->link;
  }
  return headC;
}

void display(NODE head){
  NODE temp2;
  temp2=head->link;
  while(temp2->link!=head->link){
    printf("%d X^%d ",temp2->coef,temp2->exp);
    temp2=temp2->link;
  }
  printf("\n");
}

int main(){
  NODE headA,headB,headC;
  headA=malloc(sizeof(headA));
  headB=malloc(sizeof(headB));
  headC=malloc(sizeof(headC));
  headA->link=headA;
  headB->link=headB;
  headC->link=headC;
  printf("Enter the first polynomial \n");
  headA=readpoly(headA);
  printf("\nEnter the second polynomial \n");
  headB=readpoly(headB);
  headC=polyadd(headA,headB,headC);
  printf("Polynomial 1:");
  display(headA);
  printf("Polynomial 2:");
  display(headB);
  printf("Polynomial 3:");
  display(headC);
  return 0;
}