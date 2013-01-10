#!/usr/bin/python3

import subprocess

p1 = subprocess.Popen(["atop"],stdin=subprocess.PIPE, stdout=subprocess.PIPE)
p2 = subprocess.Popen(["cat","-nE"], stdin=p1.stdout)

#p1 = subprocess.Popen(["cat"],stdin=subprocess.PIPE, stdout=subprocess.PIPE)
while True:
   cm=input("press any key\n:")
   #print(cm.encode("utf-8"))
   rt=p1.stdin.write(cm.encode("ascii"))
#   print(p1.stdout.readlines())
#   print(rt)
   if cm == 'Q':
      break
p2.terminate()
p1.terminate()

