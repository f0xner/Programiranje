#!/usr/bin/python3
import numpy as np
lights = np.zeros((1000,1000),dtype=int)
commands = []
with open("day6IN") as f:
	commands = f.readlines()

for command in commands:
	#command = "toggle 0,0 through 999,999"
	coma = command.split(" ")
	if len(coma) == 5:
		coma[0]+= coma[1]
		del coma[1]
	coma[-1] = coma[-1].replace("\n","")
	del coma[2]
	xf,yf = coma[1].split(",")
	xf = int(xf)
	yf = int(yf)
	xt,yt = coma[2].split(",")
	xt = int(xt)+1
	yt = int(yt)+1

	if coma[0] == "turnon":
		for i in range(xf,xt,1):
			for j in range(yf,yt,1):
				lights[i][j] += 1
	elif coma[0] == "turnoff":
		for i in range(xf,xt,1):
			for j in range(yf,yt,1):
				#lights[i][j] = lights[i][j] < 0 ? 0 :lights[i][j]-1
				if lights[i][j] > 0:
					lights[i][j] -= 1

	elif coma[0] == "toggle":
		for i in range(xf,xt,1):
			for j in range(yf,yt,1):
				lights[i][j] += 2
				# if lights[i][j] == 1:
				# 	lights[i][j] = 0
				# else:
				# 	lights[i][j] = 1
on = 0
for row in lights:
	for light in row:
		on+=light
print(on)