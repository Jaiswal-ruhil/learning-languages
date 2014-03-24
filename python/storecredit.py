#!/usr/bin/python
from sys import argv

script, filename = argv

def func(C,N,s):
    no,list=0
    for i in s:
        if(i==' ' or i=='\n' or i=='' and no<C):
            list.append(no)
            no=0
        else:
            no=no*10+int(i)
    list.sort()
    no=0
    for i in list:
        for j in list[no:]:
	    if((C-j)==i):
                return i
        no+=1;
    return 0

inputfile=open(filename)
outputfile=open("Output.txt",'w')
n=int(inputfile.readline())
l=0
while(l<n):
    C=int(inputfile.readline())
    r=func(C,int(inputfile.readline()),inputfile.readline())
    l=l+1
    outputfile.write("Case #%d: %d %d\n" %(l,r,C-r))
outputfile.close()
inputfile.close()
