#include<stdio.h>

int main() {
   char original[20];
   double a[6],temp,j,flag;
   int i,k;
   gets(original);
   temp=0.0;
   k=0;
   flag=j=1.0;
   for(i=0;k<6;i++)
   {
   	if(original[i]=='-')
   		flag=-1.0;
   	else if(original[i]==' ' || original[i]=='\0')
   	{
   	    a[k]=temp*flag;
		printf("%d val of i %d val k  %g\n",i,k,a[k]);
   		temp=0.0;
		flag=1.0;
		j=1.0;
		k++;
   	}
   	else
   	{
   		temp=(temp*j);
   		temp+=(double)(original[i]-48);
		j*=10; 
   	}
   }
   if((((a[4]==a[2]) && (a[2]==a[0])) || (((a[3]-a[1])/(a[2]-a[0]))==((a[5]-a[3])/(a[4]-a[2]))))
   	printf("Yes");
   else
   	printf("No");	
   return 0;
}
