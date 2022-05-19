#!/usr/bin/python3
dirs = []
x = 0
y = 0
#directions = ["N","S","E","W"]
# 0 = N, 1 = E, 2 = S, 3 = W
dire = 0
with open("day1IN") as f:
	dirs = f.readline().split(", ")
def new_dir(direction,di):
	re = direction
	if di == "L":
		re -= 1
		if re == -1:
			re = 3
	elif di == "R":
		re += 1
		if re == 4:
			re = 0
	return re
print(dirs)
for dir in dirs:
	dire = new_dir(dire,dir[0])
	if dire == 0:
		for i in range(0,int(dir[1]),1):
			y+=1
	elif dire == 1:
		for i in range(0,int(dir[1]),1):
			x+=1
	elif dire == 2:
		for i in range(0,int(dir[1]),1):
			y-=1
	elif dire == 3:
		for i in range(0,int(dir[1]),1):
			x-=1
	print(x,y)