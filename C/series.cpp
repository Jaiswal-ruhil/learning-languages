#include <iostream>
using namespace std;

class Series
{
public:
  void method1(){
    int a[]= {0,1,3,4,5,6,7,8,11,13,15,17,19,21,24,25,27,29,30,31};
    int pos=0,temppos=0,count=2,i,max=0;
    int tempdiff=a[1]-a[0];
    for(i=2;i<=19;i++){
      if(tempdiff==a[i]-a[i-1]){
	count+=1;
	putchar ('y');
      }
      else if(count>max){
	pos=temppos;
	max=count;
	count=2;
	temppos=i-1;
	putchar('m');
      }
      else{
	temppos=i-1;
	count=2;
	putchar('e');
      }
      tempdiff=a[i]-a[i-1];
    }
    if(max<count)
      pos=temppos;
    printf("\nmax=%d pos=%d",max, pos);
  }
 
  void method2(){
    int a[]= {0,1,3,4,5,6,7,8,11,13,15,17,19,21,24,25,27,29,30,31};
    int temp=a[1]-a[0],pos=0;
    for(int i=1;i<19;){
      if(a[i]+temp=a[++i]) 
	++ele;
      else{
	if(count>max){
	  pos=temppos;
	  max=count;
	  count=2;
	  temppos=i-1;
	  putchar('m');
	}
	else{
	    temppos=i-1;
	    count=2;
	    putchar('e');
	}
        tempdiff=a[i]-a[i-1];
      }
      if(max<count)
      pos=temppos;
      printf("\nmax=%d pos=%d",max, pos);
    }
};


int main(){
  Series s;
  s.method1();
  s.method2();
}
