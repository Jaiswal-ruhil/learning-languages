/*Program 8
Design, develop, and execute a program in C++ to create a class called LIST (linked list) with member functions to insert an element at the front of the list as well as to delete an element from the front of the list. Demonstrate all the functions after creating a list object.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class list{
  struct node{
    int info;
    struct node *link;
  }*first;
public:
  list(){
    first=NULL;
  }
  void insertnode(int);
  void delnode();
  void display();
};

void list::insertnode(int ele){
  node *newnode=new node;
  newnode->info=ele;
  newnode->link=first;
  first=newnode;
}

void list::delnode(){
  node *temp=first;
  if(first==NULL)
    cout<<"THE LIST IS EMPTY";
  else{
    cout<<"THE ELEMENT DELETED IS:-"<<first->info;
    first=first->link;
    delete temp;
  }
}

void list::display(){
  node *temp=first;
  if(first==NULL)
    cout<<"THE LIST IS EMPTY";
  else{
    cout<<"THE ELEMENTS IN THE LINKEDLIST ARE:-";
    while(temp!=NULL){
      cout<<temp->info<<" ";
      temp=temp->link;
    }
  }
}

int main(){
  int ele,choice;
  list l;
  system("clear");
  while(1){
    cout<<"\nMENU:-\n";
    cout<<"\t1.INSERTION \n\t2.DELETION\n\t3.DISPLAY\n\t4.EXIT";
    cout<<"\nENTER YOUR CHOICE: ";
    cin>>choice;
    switch(choice){
    case 1:
	  cout<<"ENTER THE ELEMENT: ";
      cin>>ele;
      l.insertnode(ele);
      break;
    case 2:
	  l.delnode();
      break;
    case 3:
	  l.display();
      break;
    case 4:
	  exit(0);
    }
  }
  return 0;
}