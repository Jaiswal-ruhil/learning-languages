/*Program 7
Design, develop, and execute a program in C++ to create a class called STACK using an array of integers and to implement the following operations by overloading the operators + and - :
i. s1=s1 + element; where s1 is an object of the class STACK and element is an integer to be pushed on to top of the stack.
ii. s1=s1- ; where s1 is an object of the class STACK and – operator pops off the top element.
Handle the STACK Empty and STACK Full conditions. Also display the contents of the stack after each operation, by overloading the operator <<.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
const int size=3;
class stack{
  int top,s[size];
public:
  stack(){
    top=-1;
  }
  stack operator+(int);
  stack operator-();
  friend void operator<<(ostream&,stack &);
};

stack stack::operator+(int item){
  if(top==size-1){
    cout<<"stack overflow"<<endl;
    return *this;
  }
  s[++top]=item;
  return *this;
}

stack stack::operator-(){
  if(top==-1){
    cout<<"stack underflow"<<endl;
    return *this;
  }
  cout<<"deleted item="<<s[top--]<<endl;
  return *this;
}

void operator<<(ostream&out,stack&obj){
  if(obj.top==-1){
    cout<<"stack is empty"<<endl;
    return;
  }
  cout<<"Elements of stack are"<<endl;
  for(int i=obj.top;i>=0;i--)
    cout<<obj.s[i]<<endl;
}

int main(){
  stack s1;
  while(1){
    cout<<"Enter 1 to push"<<endl;
    cout<<"Enter 2 to pop"<<endl;
    cout<<"Enter 3 to exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
    case 1:
      cout<<"Enter the elements to insert"<<endl;
      int item;
      cin>>item;
      s1=s1+item;
      cout<<s1;
      break;
    case 2:
      s1=-s1;
      cout<<s1;
      break;
    default:
	  return 0;
    }
  }
  return 0;
}