#!/usr/bin/python3
words = []
nice = 0
# vowles = ["a","e","i","o","u"]
# naughty = ["ab","cd","pq","xy"]
with open("day5IN") as f:
	words = f.readlines()
# for word in words:
# 	vowless = 0
# 	double = False
# 	contains_naughty = False
# 	for i in range(0,len(word)-1,1):
# 		if word[i] in vowles:
# 			vowless+=1
# 		if word[i] == word[i+1]:
# 			double = True
# 		naugthyy = word[i] + word[i+1]
# 		if naugthyy in naughty:
# 			contains_naughty = True
# 	if word[len(word)-1] in vowles:
# 		vowless+=1
# 	if vowless >= 3 and double == True and contains_naughty == False:
# 		nice+=1
for word in words:
	lbt = False
	pairs = []
	pair_appears = False
	for i in range(0,len(word)-2,1):
		if word[i] == word[i+2]:
			lbt = True
	for i in range(0,len(word)-1,1):
		pair = str(word[i]+word[i+1])
		if pair in pairs:
			pair_appears = True
		else:
			pairs.append(pair)
	for i in range(0,len(word)-3,1):
		if word[i] == word[i+1] == word[i+2]:
			pair_appears = False
	if lbt == True and pair_appears == True:
		print(word,end="")
		nice += 1
print("\n",nice)
