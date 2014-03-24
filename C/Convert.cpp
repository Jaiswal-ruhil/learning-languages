#include<iostream>
using namespace std;

class CONVERT{
public:
  int deciTobase(int number,const int tobase);
  int baseTodeci(int number,const int formbase);
};

int CONVERT::deciTobase(int number,const int tobase){
  int newNumber=number%tobase;
  for(int factor=1 ; number/=tobase ; newNumber+=number%tobase*(factor*=10));
  return newNumber;
}

int CONVERT::baseTodeci(int number,const int frombase){
  int newNumber=number%10;
  for(int factor=1 ; number/=10 ; newNumber+=(number%10)*(factor*=frombase));
  return newNumber;
}
