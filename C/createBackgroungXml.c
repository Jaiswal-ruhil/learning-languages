//input the number of flies then directory,name
#include<stdio.h>

int main()
{
  char name[20];
  int number,i;
  scanf("%d",&number);
  scanf("%s",name);
  printf("\
<background>\n\
  <starttime>\n\
    <year>2013</year>\n\
    <month>12</month>\n\
    <day>1</day>\n\
    <hour>00</hour>\n\
    <minute>00</minute>\n\
    <second>00</second>\n\
  </starttime>\n\
<!-- This animation starts at mid night. -->\n");

  for(i=1;i<number;i++)
    printf("\
  <static>\n\
    <duration>1795.0</duration>\n\
    <file>/usr/share/backgrounds/The joker/%s%d.jpg</file>\n\
  </static>\n\
  <transition>\n\
    <duration>5.0</duration>\n\
    <from>/usr/share/backgrounds/The joker/%s%d.jpg</from>\n\
    <to>/usr/share/backgrounds/The joker/%s%d.jpg</to>\n\
  </transition>\n",name,i,name,i,name,i+1);

  printf("\
  <static>\n\
    <duration>1795.0</duration>\n\
    <file>/usr/share/backgrounds/The joker/%s%d.jpg</file>\n\
  </static>\n\
  <transition>\n\
    <duration>5.0</duration>\n\
    <from>/usr/share/backgrounds/The joker/%s%d.jpg</from>\n\
    <to>/usr/share/backgrounds/The joker/%s%d.jpg</to>\n\
  </transition>\n\
</background>",name,i,name,i,name,1);
  return 0;  
}
