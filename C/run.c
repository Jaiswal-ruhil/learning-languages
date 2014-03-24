/*File-Copy one file contents to another

#include<stdio.h>
#include<stdlib.h>
//#include<process.h>

void main(int argc, char *argv[])
{
	FILE *fs,*ft;
	char ch;
	if(argc!=3)
	{
       		puts("Invalid number of arguments.");
      	 	exit(0);
     	}
     	fs = fopen(argv[1],"r");
	if(fs==NULL)
    	{
       		puts("Source file cannot be opened.");
  		exit(0);
     	}
    	ft = fopen(argv[2],"w");
   	if (ft==NULL)
     	{
       		puts("Target file cannot be opened.");
       		fclose(fs);
       		exit(0);
     	}
     	while(1)
       		((ch=fgetc(fs))==EOF)? break:fputc(ch,ft);
     	fclose(fs);
     	fclose(ft);
}

*/

//File Example

#include<stdio.h>
int main()
{
	FILE *fp;
     	char ch;
     	fp=fopen("file.txt","w");
	printf("\nEnter data to be stored in to the file:");
  	while((ch=getchar())!=EOF)
   		putc(ch,fp);
     	fclose(fp);
     	return 0;
}

/*
File-How the data stored on the disk is read

   #include <stdio.h> 
   #include <stdlib.h> 
   void main() 
   { 
     FILE *fptr; 
     char filename[15]; 
     char ch; 
     printf("Enter the filename to be opened\n"); 
     gets(filename); 
     fptr = fopen (filename, "r"); //open for reading 
     if (fptr == NULL) 
     { 
       printf("Cannot open file\n"); 
       exit(0); 
     } 
     ch = fgetc(fptr); 
     while (ch != EOF) 
     { 
       printf ("%c", ch); 
       ch = fgetc(fptr); 
     } 
     fclose(fptr); 
   } 



File-File operations
*/
