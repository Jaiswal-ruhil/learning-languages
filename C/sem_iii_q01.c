/*
Using circular representation for a polynomial, design, develop,and execute a program in C to accept
two polynomials, add them, and then print the resulting polynomial.
*/


#include<stdio.h>
#include<malloc.h>

struct base{
  float cof;
  int exp;
  struct base *next;
};

typedef struct base element;
void display(element *head);
element* getpoly(element *head){
  element *temp,*previous;
  temp=(element *)malloc(sizeof(element));
  head=previous=temp;
  printf("coff:");
  scanf("%f",&temp->cof);
  while(temp->cof){
    previous->next=temp;
    previous=temp;
    temp->next=head;
    printf("exponent:");
    scanf("%d",&temp->exp);
    temp=(element *)malloc(sizeof(element));
    printf("coff:");
    scanf("%f",&temp->cof);
  }
 return head;
}

element* addpoly(element *first,element *second,element *sum){
  element *tempForFirst,*tempForSecond,*temp,*previous;
  int i=0;
  sum=previous=temp=(element *)malloc(sizeof(element));
  temp->cof=0;
  do{
    previous->next=temp;
    previous=temp;
printf("okok\n\n");
    temp->next=sum;
    if(tempForFirst->exp > tempForSecond->exp){
      printf("1 %d  ",i++);
      temp->exp=tempForFirst->exp;
      temp->cof=tempForFirst->cof;
      tempForFirst=tempForFirst->next;
    }
    else if(tempForFirst->exp < tempForSecond->exp){
      printf("2 %d  ",i++);
      temp->exp=tempForSecond->exp;
      temp->cof=tempForSecond->cof;
      tempForSecond=tempForSecond->next;
    }
    else{
      printf("3 %d  ",i++);
      temp->exp=tempForFirst->exp;
      temp->cof=tempForSecond->cof + tempForFirst->cof;
      tempForFirst=tempForFirst->next;
      tempForSecond=tempForSecond->next;
    }
    temp=(element *)malloc(sizeof(element));
    if(sum->cof==0)
      sum=previous=temp; 
  }while(tempForFirst->next!=first || tempForSecond->next!=second);
printf("okokok\n\n");printf(":P\n\n");
  while(tempForFirst->next!=first){
    previous->next=temp;
    previous=temp;
    temp->next=sum;
    temp->exp=tempForFirst->exp;
    temp->cof=tempForFirst->cof;
    tempForFirst=tempForFirst->next;
    temp=(element *)malloc(sizeof(element));
    previous->next=temp;
    temp->next=sum;
    temp->exp=tempForFirst->exp;
    temp->cof=tempForFirst->cof;
  }
  while(tempForSecond->next!=second){
    previous->next=temp;
    previous=temp;
    temp->next=sum;
    temp->exp=tempForSecond->exp;
    temp->cof=tempForSecond->cof;
    tempForSecond=tempForSecond->next;
    temp=(element *)malloc(sizeof(element));
    previous->next=temp;
    temp->next=sum;
    temp->exp=tempForSecond->exp;
    temp->cof=tempForSecond->cof;
  }
  if(sum->cof)
    return NULL;
  return sum;
}

void display(element *head){
  element *temp=head;
  if(head==NULL){
    printf("the polynomial is empty");
    return;
  }
  while(temp->next!=head){
    printf("%gx^%d + ",temp->cof,temp->exp);
    temp=temp->next;
  }
  printf("%gx^%d",temp->cof,temp->exp);
}

int main(){
  element *startA,*startB,*startC;
  printf("Input the first Ploynomial:\t(cof=0 to terminate & follow desending order)\n");
  startA=getpoly(startA);
  printf("Input the second Ploynomial:\t(cof=0 to terminate & follow desending order)\n");
  startB=getpoly(startB);
  startC=addpoly(startA,startB,startC);
  printf("the 1st polynomial is   :   ");
  display(startA);
  printf("the 2nd polynomial is   :   ");
  display(startB);
  printf("sum of thepolynomial is :   ");
  display(startC);
  printf("\n");
  return 0;
}
