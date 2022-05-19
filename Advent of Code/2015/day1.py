#!/usr/bin/python3
with open("day1IN") as f:
	inp = f.read()
	sum = 0
	i = 0
	for c in inp:
		i+=1
		if(c == "("):
			sum+=1
		elif(c == ")"):
			sum-=1
		if(sum == -1):
			print(i)
			break
	print(sum)
