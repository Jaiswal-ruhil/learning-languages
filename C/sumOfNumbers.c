#include<stdio.h>
#include<string.h>
int main()
{
char arr[40];
int i,temp,j,total;
gets(arr);
for(i=temp=total=0,j=1;arr[i];i++)
{
	if(arr[i]=='-')
		break;
	else if(arr[i]==' ')
	{
		total+=temp;
		temp=0;
		j=1;
	}
	else
	{
		temp=temp*j+arr[i]-48;
		j*=10;
	}
}
printf("%d",total);
return 0;
}
