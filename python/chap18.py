#used to definr a func
def print_two(*args):
    arg1,arg2=args
    print "arg1: %r, arg2: %r"%(arg1,arg2)

#another way to pass arg

def print_two_again(arg1,arg2):
    print "arg1: %r, arg2 %r"%(arg1,arg2)

#just 1 argument
def print_one(arg1):
    print "arg1: %r"%arg1

#no input
def printnone():
    print "this is how to print"

print_two("ruhil","jaiswal")
print_two_again("ruhil","jaiswal")
print_one("just one")
printnone()
