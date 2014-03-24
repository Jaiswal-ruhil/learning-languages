#include<iostream>
#include<fstream>
using namespace std;

class module
{
	int n;char *file;
public:
	module(char c[])
	{
		file=autoname(c);
		ifstream out(file);
	}
	char* autoname(char *);
};

char* module::autoname(char c[]) //gives default extention as .txt
{
	int i=0;
	while(c[i++])
		if(*(c+i)=='.')
			return c;
	c[i-1]='.',c[i]='t',c[i+1]='x',c[i+2]='t',c[i+3]='\0';
	return c;
}
void module::print()
{
	
}

int main()
{
	char c[20];
	cout<<"input the name of the file";
	cin>>c;
	module m=module(c);
	m.print();
	return 0;
}
