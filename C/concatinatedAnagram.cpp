#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  do{
    char str[50];
    int arr[26]={0};
    int len=0,total=0;
    cin>>str;
    do
      if(len%2==0)
	    arr[str[len/2]-97]+=1;
    while(str[++len]);
    if(len%2==1)
      cout<<"-1\n";
    else{
      for(len/=2;str[len];len++)
	if((arr[str[len]-97]-=1)<0)
	  total+=1;
    cout<<total<<endl;
    }
  }while(--n);
  return 0;
}
