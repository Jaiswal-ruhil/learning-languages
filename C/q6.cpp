/*Program 6
Design, develop, and execute a program in C++ to create a class called STRING and implement the following operations. Display the results after every operation by overloading the operator <<.
i. STRING s1 = “VTU”
ii. STRING s2 = “BELGAUM”
iii. STIRNG s3 = s1 + s2; (Use copy constructor)
*/

#include<iostream>
#include<string.h>
using namespace std;

class strin{
private:
  char s[40];
public:
  strin(){}
  strin(char *p){
    strcpy(s,p);
  }
  friend strin add(strin&x,strin&y){
    strin temp;
    strcpy (temp.s,x.s);
    strcat(temp.s,y.s);
    return temp;
  }
  strin (const strin&z){
    strcpy(s,z.s);
  }
  friend void operator<<(ostream&,strin&);
};

void operator<<(ostream &out, strin &z){
  out<<z.s<<"\n";
}

int main(){
  strin s1="vtu";
  strin s2="belgaum";
  strin s3=add(s1,s2);
  cout<<s3;
  return 0;
}