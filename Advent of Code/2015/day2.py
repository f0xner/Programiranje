#!/usr/bin/python3
with open("day2IN") as f:
	inp = f.readlines()
	total = 0
	for box in inp:
		dims = box.split("x")
		dims[2] = dims[2].replace("\n","")
		dims2 = []
		for dim in dims:
			dims2.append(int(dim))
		dims2 = sorted(dims2)
		total += 2*dims2[0]+2*dims2[1]
		total += dims2[0]*dims2[1]*dims2[2]
	print(total)
