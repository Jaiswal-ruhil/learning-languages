/*
* Design, develop and execute a program in C++
*
* Class name:	STACK
*
* Data member:	arr	int	to demonstate stack
*
* using overloading of operator + and - demonstrate
*	s1=s1+element  	where s1 is an object of STACK for inserting an element
*	s1=s1-		s1 is the obj of STACK -- implimenting pop function
*	display the elements in the sack after each function by overloading the func <<
*/


#include<iostream>
#include<stdlib.h>
using namespace std;
#define size 5

class STACK{
  int top,stack[size];
public:
  STACK(){
    top=-1;
  }
  STACK operator +(int);
  STACK operator -();
  friend void operator<<(ostream &,STACK &);
};

int main(){
  int a;
  STACK stack;
  while(1){
    cout<<"\nENTER YOUR CHOICE\n";
    cout<<"1. to insret an element\n";
    cout<<"2. to pop an element\n";
    cout<<"any thing else to print and exit\n";
    cin>>a;
    switch(a){
    case 1:
      cout<<"\nplease insert the element :  ";
      cin>>a;
      stack+=a;
      cout<<stack;
      break;
    case 2:
	  stack=-stack;
	  cout<<stack;
	  break;
    default:
	  cout<<stack;
	  return 0;
    }
  }
  return 0;
}

STACK STACK::operator +(int ele){
  if(top<size-1)
    stack[++top]=ele;
  else 
    cout<<"\nstack is full";
  return *this;
}

STACK STACK::operator -(){
  if(top==-1)
    cout<<"\nstack empty\n";
  else
    top-=1;
  return *this;
}

void operator <<(ostream &print,STACK &stack){
  for(int i=0;i<=stack.top;i++)
    print<<stack.stack[i]<<"\t";
  print<<"\n";
}
