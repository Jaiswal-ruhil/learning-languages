/*Program 5
Design, develop, and execute a program in C++ based on the following requirements:
An EMPLOYEE class is to contain the following data members and member functions:
Data members: Employee_Number (an integer), Employee_Name (a string of characters), Basic_Salary (an integer) , All_Allowances (an integer), IT (an integer), Net_Salary (an integer).
Member functions: to read the data of an employee, to calculate Net_Salary and to print the values of all the data members. (All_Allowances = 123% of Basic; Income Tax (IT) = 30% of the gross salary (= basic_Salary - All_Allowance); Net_Salary =Basic_Salary + All_Allowances – IT)
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class employee{
  int emp_num,basic_sal,all_allow,it,net_sal;
  char emp_name[20];
public:
  void getd();
  void dispd();
  void calculate();
};

void employee::getd(){
  cin>>emp_name>>emp_num>>basic_sal;
}

void employee::dispd(){
  cout<<emp_num<<"\t"<<emp_name<<"\t"<<basic_sal<<"\t"<<all_allow<<"\t\t"<<it<<"\t"<<net_sal<<endl;
}

void employee::calculate(){
  all_allow=(123*basic_sal)/100;
  it=(30*(basic_sal+all_allow))/100;
  net_sal=basic_sal+all_allow-it;
}

int main(){
  system("clear");
  int n;
  cout<<"\nenter number of employee\n";
  cin>>n;
  employee ob[n];
  cout<<"\nenter name,number and basic salary of "<<n<<" employees\n";
  for(int i=1;i<=n;i++)
    ob[i].getd();
  cout<<"\nemployee details are\nemp_num\tname\tbasic\tallowance\tit\tnetsal\n";
  for(int i=1;i<=n;i++){
    ob[i].calculate();
    ob[i].dispd();
  }
  return 0;
}