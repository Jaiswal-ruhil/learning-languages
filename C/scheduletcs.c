//question defination at the end of the code

#include<stdio.h>
#include<stdlib.h>

void getmaxmin(const int array[], int *max);

int main(){
  int n,count,common[1440]={0},**input,max[2]={0,1},min[2]={0,1440};

  scanf("%d",&n);
  input=(int **)malloc((n+1)*sizeof(int*));
  for(count=0;count<=n;count++)
    input[count]=(int *)calloc(1440,sizeof(int));
  
  //enter the time slots
  while(1)
  {
    int i,no,starthh, startmm, endhh, endmm;
    scanf("%d",&no);
    if(no==-1)
      break;
    scanf("%d:%d %d:%d",&starthh,&startmm,&endhh,&endmm);
    count=endhh*60+endmm;
    for(i=starthh*60+startmm;i<count;i++)
      common[i]=input[no][i]=1;
  }
  for(count=1;count<=n;count++)
  {
    int tempmax[2]={0,1};
    getmaxmin(input[count],tempmax);
    if((max[1]-max[0])<(tempmax[1]-tempmax[0]))
    {
        max[0]=tempmax[0];
        max[1]=tempmax[1];
    }
    else if((max[1]-max[0])==(tempmax[1]-tempmax[0]))
    {
      (max[0]<tempmax[0])?0:max[0]=tempmax[0],max[1]=tempmax[1];
    }  
    if((min[1]-min[0])>(tempmax[1]-tempmax[0]))
    {
      min[1]=tempmax[1];
      min[0]=tempmax[0];
    }
    else if((min[1]-min[0])==(tempmax[1]-tempmax[0]))
    {
      (min[0]<tempmax[0])?0:min[0]=tempmax[0],min[1]=tempmax[1];
    }  
  }
  //select the entries accoording to the person
  #define str   "%02d:%02d %02d:%02d\n"
  printf(str,max[0]/60,max[0]%60,max[1]/60,max[1]%60);
  printf(str,min[0]/60,min[0]%60,min[1]/60,min[1]%60);
  max[1]=max[0]=0;
  getmaxmin(common,max);
  printf(str,max[0]/60,max[0]%60,max[1]/60,max[1]%60);
  free(input);
  return 0;
}

void getmaxmin(const int array[],int *max)
{
  int i,temp=0;// keeping in mind the array will end with a zero
  for(i=0;i<=1440;i++)
  {
    if(array[i] && temp)
    {
      if(temp>(max[1]-max[0]))
      {
        max[1]=i;
        max[0]=i-temp;
      }
      temp=0;
    }
    else if(array[i]==0)
      temp++;
  }
}

/*
  Problem: Common Scheduler
  The leades of all countries arround the world need to gather in order to sign the World Peace Summit.
  
  Today is the D-Day. Given 'N' countries and the schedule of their leader for the next 24 hrs, your task is to find a maximum time slot such that all leader are available during the period
  
  Input Format:
  The first line contains N, the number of countries.
  
  The following lines contains:
    1. I- unique id of the leader
    2. [A,B)- the time slot when the leader is bussy i.e. including time A and excluding time B
  End of input is given by "-1"
  
  Note:
    * Each country will have ony one representative
    * Time slot [A,B) will be in the forat HH:MM
    
  Output Format:
    Print #lines each with a time slot [A,B)
      1. Line 1- Among the best free Schedules of every leader print the maximum free time slot in the first line
      2. Line 1- Among the best free Schedules of every leader print the minimum free time slot in the second line
      3. Line 3- the maximum common duration at which all the leaders will be available
  
  Start time and end time of the slot shuld be in HH:MM format
  
  Note:
  In the case if there is a tie b/w two slots, due to length of the slot, preffer the one which appears earlier on the clock.
  
  
  Constraints:
    
    1 <= N <= 5000
    1 <= I <= N
    00:00 <= A <= B <=24:00
    
  Sample Input and Output:
  
  input
  3
  2 00:35 12:35
  1 00:35 09:45
  1 23:02 23:59
  2 18:45 23:59
  3 15:15 20:36
  3 00:15 02:45
  -1
  
  output
  09:45 23:02
  12:35 18:45
  12:35 15:15

*/
