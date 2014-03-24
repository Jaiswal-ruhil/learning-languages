/*quadratuc equation

#include<stdio.h>
#include<math.h>
struct complex
{
	float r1;
	float r2;
	int r3;
};

struct complex rootquad(float a,float b,float c)
{
	struct complex r;
	if(a==0.0) (b==0.0)? (r.r1=0,r.r2=0,r.r3=0):(r.r1=-b/c,r.r2=0,r.r3=0);
	else
	{
		r.r3=1;
		if((c=b*b-4*a*c)<0.0) r.r3=-1;
		r.r1=-b/(a=(2.0*a));
		r.r2=sqrt(fabs(c))/a;
	}
	return r;
}
void main()
{
	struct complex x;float a,b,c;
	printf("give your vals ::");
	scanf("%f%f%f",&a,&b,&c);
	x=rootquad(a,b,c);
	printf("\n\n%g   %g   %d",x.r1,x.r2,x.r3);
}
*/
//quadratuc equation

#include<stdio.h>
#include<math.h>

void main()
{
	float a,b,c;
	printf("give your vals ::");
	scanf("%f%f%f",&a,&b,&c);
	if(a==0.0)
		(b==0.0)? printf("\n\nInvalid Input no varable to solve for\n"):printf("\n\nonly possible root is %g\n",-b/c);
	else
	{
		b=-b/(a*=2.0);
		a=sqrt(fabs(c=b*b-2.0*a*c))/a;
	}
	(c<0.0)? printf("\n\n%g + %gi  and  %g - %gi\n",b,a,b,a):printf("\n\n%g  and  %g\n",b+a,b-a);
}
