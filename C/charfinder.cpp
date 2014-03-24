#include<iostream>
using namespace std;

void charlist(){
  int n=sizeof(char);
  do
    cout<<"ASCII value of character: "<<(char)n<<"  is  "<<n<<endl;
  while(--n);
}

int main(){
  cout<<"\t\t\t\tList: choose";
  cout<<"1.\tCHARACTER LIST";
  cout<<"any.\tEXIT";
  int option;
  cin>>option;
  switch(option){
  case 1:
    charlist();
    break;
  default:
    break;
  }
  return 0;
}
