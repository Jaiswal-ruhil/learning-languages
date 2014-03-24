#include<stdio.h>

int main()
{
  
  short int number=1212;
  printf("original=         %d",number);
  printf("\n\n\noriginal+)x1=     %d",(~number+0x1));
  printf("\n\n\n-1(original+0x1=  %d\n",-1*(~number+0x1));
  return 0;
}
