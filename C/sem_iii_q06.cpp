/* Design,Develop and exrcute a string in C++ based on the following information
* class name :	STRING
*
* implement the followinfg opreation
*   STRING s1="VTU"
*   STRING s2="Belgaum"
*   STRING s3=s1+s2  usecopy constructor
*
* display the concatination of the 2 strings by overloading the operator
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class STRING{
  char *string;
public:
  STRING(int n){
      string=(char *)calloc(n,sizeof(char));
  }

  STRING(char *source){
    int len=strlen(source);
    string=(char *)calloc(len,sizeof(char));
    strcpy(string,source);
  }

  friend STRING operator+(STRING &,STRING &);
  friend void operator<<(ostream &,STRING &);
};

void operator << (ostream &print,STRING &S){
  print<<'\n'<<S.string<<'\n';
}

STRING operator + (STRING &a,STRING &b){
    STRING temp(strlen(a.string)+strlen(b.string));
    strcpy(temp.string,a.string);
    strcat(temp.string,b.string);
    return temp;
}

int main(){
    char str1[20],str2[20];
    cout<<"PLease input the string 1\n\t";
    cin>>str1;
    cout<<"please input the string 2\n\t";
    cin>>str2;
    STRING s1=str1;
    STRING s2=str2;
    STRING s3=s1+s2;
    cout<<s3;
}
