/*
 * Design develop & execute a program in C++
 *
 * Class name: DATE
 *        with metod to accept 2 valid dates in the form dd/mm/yyyy
 * implement the following function (by overloading the operators + and -)
 *
 *   i) no_of_days=d1-d2; where d1 and d2 are objects of class DATE and d1>=d2 and no_of_days is int
 *  ii) d2= d1+no_of_days; d2,d1 are obj of DATE and no_of_days is int
 *
 * and print the result after every operation by overloading the operator <<
 */
#include<iostream>
using namespace std;
#include<stdlib.h>

class DATE{
  int day,month,year;
public:
  void getdate(){
      char c[11];
      cin>>c;
      c[2]=c[5]='\0';
      day=atoi(c);
      month=atoi((c+3));
      year=atoi((c+6)); 
    }

  void display(){
    cout<<day<<'/'<<month<<'/'<<year<<endl;
  }
  friend int operator-(DATE &,DATE &);
  friend DATE operator+(DATE &,int);
  friend ostream& operator<<(ostream &,DATE &);
};

int operator -(DATE &d1,DATE &d2){
  int days=d1.day,m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  if(d1.year==d2.year && d1.month==d2.month)
    return days-=d2.day;
  m[2]=((d2.year%4==0 && d2.year%100) || d2.year%400==0) ? 29 : 28;
  days+=m[d2.month]-d2.day;
  for(int i=d2.month+1;i<=12;i++)
    days+=m[i];
  for(int i=d2.year+1;i<d1.year;i++)
    days+=((i%4==0 && i%100) || d2.year%400==0)? 365 : 366;
  m[2]=((d1.year%4==0 && d1.year%100) || d1.year%400==0) ? 29 : 28;
  for(int i=1;i<d1.month;i++)
    days+=m[i];
  return days;
}

ostream& operator<<(ostream &print,DATE &d){
  print<<d.day<<'/'<<d.month<<'/'<<d.year;
  return print;
}

DATE operator+(DATE &d1,int no_of_days){
  int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  DATE temp=d1;
  m[2]=((temp.year%4==0 && temp.year%100) || temp.year%400==0) ? 29 : 28;
  if(no_of_days > (m[temp.month]-temp.day)){
    temp.day=1;
    no_of_days -= m[temp.month]-temp.day;
    if((temp.month++)==13){
      temp.month=1;
      temp.year++;
    }
  }
  else{
    temp.day+=no_of_days;
    return temp;
  }
  for(int i=temp.month+1;no_of_days>m[i] && i<=12;i++){
    no_of_days-=m[i];
    temp.month=i;
  }
  while(no_of_days>364){
    if((temp.year%4==0 && temp.year%100) || temp.year%400==0){
      if(no_of_days>365)
	no_of_days-=366;
      else 
        break;
    }
    else
      no_of_days-=365;
    temp.year++;
  }
  if(no_of_days){
    temp.year++;
    m[2]=((temp.year%4==0 && temp.year%100) || temp.year%400==0) ? 29 : 28;
    for(int i=1;no_of_days>m[i];i++){
      no_of_days-=m[i];
      temp.month++;
    }
    if(no_of_days){
      if(temp.month==12){
        temp.month=1;
        temp.year++;
      }
      else 
        temp.month++;
      temp.day=no_of_days;
    }
  }
  return temp;
}

int main(){
  DATE d1,d2;
  cout<<"\n\tPlease input valid dates in the format dd/mm/yyyy";
  cout<<"\n\tDate 1:  ";d1.getdate();
  cout<<"\n\tDate 2:  ";d2.getdate();
  int no_of_days=d1-d2;
  cout<<"\nDate d1 is:\t\t\t"<<d1<<"\nDate d2 is:\t\t\t"<<d2<<"\ndifference b/w the dates is:\t"<<no_of_days;
  d2=d1+no_of_days;
  cout<<"\nDate d1 + difference is:\t"<<d2<<"\n\n";
  return 0;
}
