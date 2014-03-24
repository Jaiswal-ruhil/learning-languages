#include<iostream>
#include<string.h>
using namespace std;

class anagram
{
public:	int* check(char *s1,char *s2)//takes 2 strings to b compared. in lower case and same no. of characters(a-z)
	{
		int arr[26]={0};// stores all the counts of elements occuring i.e. frequency of ocurance

		int *p=arr-'a';/* the pointer holds the address of u say x
				now x-'a' is x-65 thus u[0] has a refference of a (as i can call p+'a' or p+'b') */

		int temp=0;// will explain with the working
		int len=strlen(s1);

		do{
			--len;
			temp+=++*(p+s1[--len]);/* 	breaking it up:  let the s1=avir  & s2=vira
								say address of arr was 7500 now p=7500-(97*4) = 7112 since int type pointer
								p+s1[i] equates to p+r = 7112+(114*4) = 7568 which is arr[17] position of r
								now *(p+s1[i]) is the value being incremented ie ++arr[17]
								muliplication of the value allows one to having atleast 65 unmatching char
								before the logic fails remember it takes from back*/
			cout<<temp<<"    ";
			temp+=--*(p+s2[len]);/*this is the counter to match if s1 has a then temp if 65 if s2
							   has a then temp = temp- 65*/
		cout<<temp<<endl;
		}while(len);

		return arr;
	}

	int compressed(char *s1,char *s2){
                int arr[26]={0},*p=arr-'a',temp=0,len=strlen(s1);
                do
               		temp+=((++*(p+s1[len])) * s1[len])+((--*(p+s2[len])) * s2[len]);
                while(len);
                return temp;
        }

	int anagram2(char *s1,char *s2){
                int temp=0,len=strlen(s1);
                do
                    temp+=s1[--len]-s2[len];
                while(len);
                return temp;
        }

	int anagram3(char *s1,char *s2){
                int len=strlen(s1),temp=s1[--len]^s2[len];
                do
                	temp^=s1[--len]^s2[len];
                while(len);
		return temp;
        }


};

main()
{
	anagram a;
//	int *x=a.check("ruhil","liruh");
//	(1)?cout<<"\nis not a anagram\n"<<x:cout<<"\nis an anagram\n"<<x;
	(a.anagram3("aloha","aloia"))?cout<<"not a anagram\n":cout<<"anagram\n";
	return 0;
}
