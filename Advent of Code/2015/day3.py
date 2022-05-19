#!/usr/bin/python3
with open("day3IN") as f:
	dire = f.read()
	visi = 1
	visitedS = [[0,0]]
	visitedRS = [[0,0]]
	xS = 0
	yS = 0
	xRS = 0
	yRS = 0
	for i in range(0,len(dire),2):
		dir = dire[i]
		if(dir == "v"):
			yS-=1
		elif(dir == ">"):
			xS+=1
		elif(dir == "<"):
			xS-=1
		elif(dir == "^"):
			yS+=1
		
		if [xS,yS] not in visitedS:
			visi+=1
			visitedS.append([xS,yS])
	for i in range(1,len(dire),2):
		dir = dire[i]
		if(dir == "v"):
			yRS-=1
		elif(dir == ">"):
			xRS+=1
		elif(dir == "<"):
			xRS-=1
		elif(dir == "^"):
			yRS+=1
		
		if [xRS,yRS] not in visitedRS and [xRS,yRS] not in visitedS:
			visi+=1
			visitedRS.append([xRS,yRS])		
	print(visi)