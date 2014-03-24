from sys import argv
script,filename= argv

print "to erase we will call the truncate function on filename %r" % filename
print "ctrl-c to break the operation now"

raw_input("? ")

print "opening the file as an object"
file= open(filename, 'w')

print "now clearing the stuff"
file.truncate()

print "input what u want to enter"

line1=raw_input("line 1: ")
line2=raw_input("line 2: ")
line3=raw_input("line 3: ")

print "now we will write the file using the write() func"

file.write("%s%s%s%s%s"%(line1,'\n',line2,'\n',line3))

print "now go and check the file"
file.close()
