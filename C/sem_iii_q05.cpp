/*
* Design,Develop and execute a program in C++ based on the following info:
*
* class:            EMPLOYEE
* Data members:
*	employee_number		int		store the serial number alloted to the employee
*	employee_name		string		store the employee name
*	basic_salary		float		store the salary given to the employee
*	all_allowance		float		store the extra allowances offered to the employe (123% of basic_salary)
*	income_tax		float		the tax the employee has to pay (30% of (basic_salary + all_allowance))
*	net_salary		float		the total salary employee gets (basic_salary + all_allowance - income_tax)
*
* Member functions
*	read()		to get the data from the user
*	calculate()	to calculate all_allowance , income_tax and net_salary
*	display()	to print the stored data
*/


#include<iostream>
#include<stdlib.h>
using namespace std;

class EMPLOYEE{
    int employee_number;
    float basic_salary,all_allowance,income_tax,net_salary;
    char employee_name[20];
    public:
	EMPLOYEE();
    	void read(int);
    	void calculate();
    	void display();
};

void EMPLOYEE::read(int emp_no){
    employee_number=emp_no;
    cin>>employee_name>>basic_salary;
    calculate();
}

void EMPLOYEE::calculate(){
    all_allowance=1.23*basic_salary;
    income_tax=basic_salary*.0669;
    net_salary=basic_salary*1.93;
}

void EMPLOYEE::display(){
    cout<<"\n\t"<<employee_number;
    cout<<"\t"<<employee_name;
    cout<<"\t\t"<<basic_salary;
    cout<<"\t\t"<<all_allowance;
    cout<<"\t\t"<<income_tax;
    cout<<"\t\t"<<net_salary;
}


int main()
{
    int a,i=-1,n=20;
    EMPLOYEE *detail=(EMPLOYEE *)calloc(10,sizeof(EMPLOYEE));
    cout<<"* Input the Employee number , Employee Name and Salary for new entry\n";
    cout<<"* Input 0 to print and exit\n";
    while(1){
	  cout<<"\t ----->  ";
	  cin>>a;
	  if(a){
	    if(++i>=n)
	      detail=(EMPLOYEE *)realloc(detail,(n+=20)*sizeof(EMPLOYEE));
	    detail[i].read(a);
	  }
	  else{
	    cout<<"\tEMP_no.\tEMP_name\tBasic_salary\tAllowances\tIncomr_tax\tNet_salary\n";
	    do
	      detail[i].display();
	    while((--i)>=0);
	    cout<<'\n';
	    exit(0);
	  }
    }
}
