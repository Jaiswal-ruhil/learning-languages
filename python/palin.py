#!/usr/bin/python
dig5pal=[]
dig6pal=[]


def is_pal(n):
    if str(n)==(str(n))[::-1]:
        return 1


for i  in xrange(10000,99999+1):
    if is_pal(i):
        dig5pal+=i

for i  in xrange(100000,999999+1):
    if is_pal(i):
        dig6pal+=i


print dig5pal,"\n\n\n\n\n\n"

print dig6pal,"\n\n\n\n\n\n"





