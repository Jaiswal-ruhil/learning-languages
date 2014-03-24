/*
 * Design develop and execute a program in c++
 *
 * Create class:     OCTAL
 *     which has the characterstics of an octal number
 * Implement the following operations:
 * OCTAL h = x; x is an integer 
 * int y = h + k; k is an integer
 * 
 * Display the octal result by overloading the operator <<.
 * Also display values of h and y
 * 
*/

#include<iostream>
#include<math.h>
using namespace std;

class OCTAL{
public:
  int octal;
  OCTAL(int number){
    octal=number%8;
    for(int factor=1 ; number/=8 ; octal+=number%8*(factor*=10));
  }
};

int operator +(OCTAL &ob,int number){
  int temp_number=ob.octal,newNumber=temp_number%10;
  for(int factor=1 ; temp_number/=10 ; newNumber+=(temp_number%10)*(factor*=8));
  return newNumber+number;
}

ostream& operator <<(ostream &print,OCTAL &ob){
  print<<ob.octal;
  return print;
}

int main(void){
  int x;
  cout<<"\n\tPlease input the number :  ";
  cin>>x;
  OCTAL h=x;
  cout<<"\tInput the decimal number to add :  ";
  cin>>x;
  int y=h+x;
  cout<<"\tThe vlaue of h is "<<h<<" and y is "<<y;
  OCTAL n=y;
  cout<<"\n\tThe octal value of the sum is :  "<<n<<"\n\n";
}
