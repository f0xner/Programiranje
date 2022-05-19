#!/usr/bin/python3
inpu = "3113322113"
new = ""
def find_howmany(en,ch):
	howmany = 1
	for i in range(en+1,len(inpu),1):
		if ch == inpu[i]:
			howmany+=1
		else:
			break
	return [howmany,ch]
for i in range(0,50,1):
	new = ""
	skip = ""
	for en,ch in enumerate(inpu):
		if ch != skip:
			howmany,skip = find_howmany(en,ch)
			new += str(howmany) + str(ch)

	inpu = new
print(len(new))