#!/usr/bin/python3
with open("day8IN") as f:
	strings = f.readlines()


def count_total_chr():
	total = 0
	for string in strings:
		total += len(string)-1
	return total
def count_act():
	global strings
	act = 0
	for string in strings:
		for i in range(1,len(string)-1,1):
			str = string[i] + string[i+1]
			if str == "\"":
				act+=1
			else:
				act+=1
		for i in range(1,len(string)-3,4):
			str = string[i] + string[i+1] + string[i+2]
			if str == "\\x":
				act+=1
			try:
				x = int(string[i+3])
			except:
				act+=1
	return act
answer = count_total_chr()-count_act()
print(f"Answer: {answer}")