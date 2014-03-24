#!/usr/bin/python3.3
import time
while True:
    for i in ['/','-','|','\\','|']:
        time.sleep(0.2)
        print("%s" % (("%s  " % i)*10),end=' ')
