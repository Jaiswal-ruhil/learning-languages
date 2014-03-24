#!/usr/bin/python
from sys import argv

s, ifile = argv

def dancer(s):
    N,list=0,[]
    for i in s:
        if(i==' ' or i=='\n'):
            list.append(N)
	    N=0
	else:
	    N=N*10+int(i)
    N,S,P=list.pop(0),list.pop(0),list.pop(0)
    if P==0:
        return N
    N=0
    for i in list:
        i-=P
	if (i>=0):
	    i-=P-1
	    if (i>=0):
	        i-=P-1
                if(i>=0):
                    N+=1
                elif (S>0 and (i+2)>=0):
                    N+=1
                    S-=1
    return N


istream=open(ifile)
ostream=open("Output",'w')
T=int(istream.readline())
for i in range (0,T):
    ostream.write("Case #%d: %d\n" % (i+1,dancer(istream.readline())))
istream.close()
ostream.close()
