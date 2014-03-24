from sys import argv
from os.path import exists

sc,source,dest=argv

print "we r going to copy from file %s to %s" %(source,dest)

indata=open(source).read()

print "the input file is %d bytes long"% len(indata)

print "does the output file exists? %r" % exists(dest)
print "guess we are ready , enter to run ctrl-c to abort"
raw_input()

wfile=open(dest,'w')
wfile.write(indata)
print "all done go check"

wfile.close()
