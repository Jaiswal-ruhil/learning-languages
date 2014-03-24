/*
 * find the gcd and lcm for two numbers
 */

#include<stdio.h>
#include<math.h>

float Gcd(float a,float b){
  if(!a)
    return b;
  return Gcd(fmodf(b,a),a);
}

int main(){
  float a,b,g;
  printf("\n\n\tInput the nos. please\t:\t");
  scanf("%f",&a);
  printf("\t\t\t\t:\t");
  scanf("%f",&b);
  g=Gcd(a,b);
  printf("\t\tGcd=%g\n\t\tLcm=%g\n\n",g,a*b/g);
  return 0;
}
