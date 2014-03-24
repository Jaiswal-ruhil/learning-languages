#include<iostream>
using namespace std;


class pattern
{
	public:
	void pat(int n,int j=0)
	{
		int k=j;
		for(int i=0;i<n;i++)
			(j)?(j--,cout<<' '):cout<<'*';
		if(--n>k)cout<<endl,pat(n,++k);
		else ++k;
		cout<<endl;
		for(int i=0;i<=n;i++)
			(k>1)?(--k,cout<<' '):cout<<'*';
	}
};

int main()
{
	pattern p;
	p.pat(9,0);
	cout<<endl;
}

/*
void agv(char s1[],char s2[])
{
	
}*/
