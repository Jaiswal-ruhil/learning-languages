/*Program 12
Design, develop, and execute a program in C++ to create a class called DATE with methods to accept two valid dates in the form dd/mm/yy and to implement the following operations by overloading the operators + and -. After every operation the results are to be displayed by overloading the operator <<.
i. no_of_days = d1 – d2; where d1 and d2 are DATE objects, d1 >=d2 and no_of_days is an integer.
ii. d2 = d1 + no_of_days; where d1 is a DATE object and no_of_days is an integer.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class DATE{
  int dd,mm,yyyy,m[13];
public:
  DATE(){
    m[1]=31;m[2]=28;m[3]=31;m[4]=30;m[5]=31;m[6]=30;m[7]=31;m[8]=31;m[9]=30;
    m[10]=31;m[11]=30;m[12]=31;
  }
  friend void getdate(DATE &d);
  friend int operator==(DATE &d1,DATE &d2);
  friend int operator-(DATE &d1,DATE &d2);
  friend DATE operator+(DATE &d,int n);
  friend ostream& operator<<(ostream&out,DATE&d);
};

void getdate(DATE &d){
  cin>>d.dd>>d.mm>>d.yyyy;
}
ostream& operator<<(ostream&out,DATE&d){
  out<<d.dd<<"/"<<d.mm<<"/"<<d.yyyy<<endl;
  return out;
}

int operator==(DATE &d1,DATE &d2){
  if(d1.mm==d2.mm&&d1.dd==d2.dd&&d1.yyyy==d2.yyyy)
    return 1;
  return 0;
}

DATE operator+(DATE &d,int ndays){
  d.m[2]=(((d.yyyy%4==0) && (d.yyyy%100!=0)) || (d.yyyy%400==0))?29:28;
  for(int i=1;i<=ndays;i++){
    d.dd++;
    if(d.dd>d.m[d.mm]){
      d.mm++;
      d.dd=1;
    }
    if(d.mm>12){
      d.yyyy++;
      d.mm=1;
    }
  }
  return d;
}

int operator-(DATE &d1,DATE &d2){
  int count=0;
  while(1){
    if(d1==d2)
      return count;
    else{
      count++;
      d2=d2+1;
    }
  }
}

int main(){
  system("clear");
  int no_of_days;
  DATE d1,d2;
  cout<<"\nenter date1>date2 in the format DD MM YYYY: ";
  getdate(d1);
  cout<<"\nenter second date in the format DD MM YYYY: ";
  getdate(d2);
  no_of_days=d1-d2;
  cout<<"\nthe no. of days between the two years are: "<<no_of_days;
  d1=d1+no_of_days;
  cout<<"\nthe date d1 after adding "<<no_of_days<<" days is:"<<d1;
  return 0;
}