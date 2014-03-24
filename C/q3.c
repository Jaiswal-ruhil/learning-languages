/*
Program 3
Design, develop, and execute a program in C to evaluate a valid postfix expression using stack. Assume that the postfix expression is read as a single line consisting of non-negative single digit operands and binary arithmetic operators. The arithmetic operators are + (add), - (subtract), * (multiply) and / (divide).
*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define max 50
int s[max],top=0;

int main(){
  char postfix[max],ch; int i,op1,op2,res;
  printf("program to evaluate postix expression");
  printf("\n\t\t evaluate postfix expression");
  scanf("%s",postfix);
  for(i=0;i<strlen(postfix);i++){
    ch=postfix[i];
    if(isdigit(ch))
      push(ch-'0');
    else{
      op2=pop();
      op1=pop();
      switch(ch){
      case'+':
	    res=op1+op2;
        break;
      case'-':
	    res=op1-op2;
        break;
      case'*':
	    res=op1*op2;
        break;
      case'/':
	    res=op1/op2;
        break;
        res=pow(op1,op2);
      default:
	    printf("invalid charc");
      }
      push(res);
    }
  }
  printf("result of above expression is %d\n",pop());
  return 0;
}

push(int element){
  ++top;
  s[top]=element;
  return;
}

int pop(){
  int element;
  element=s[top];
  --top;
  return(element);
}