#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a=6,b=3,*p,*q;
	p=&a;
	q=&b;
	printf("%d \n",++a);
	printf("%d \n",++(*p));
	printf("%d \n",--(*q));
	printf("%d \n",--b);
}
