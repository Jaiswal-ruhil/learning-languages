#!/usr/bin/python

from sys import argv
script, filename = argv
file = open(filename)
print "here's your file %r: " % filename
print file.read()

print "Tupe the file name again"
filename2= raw_input("> ")
file2=open(filename2)
print file2.read()
