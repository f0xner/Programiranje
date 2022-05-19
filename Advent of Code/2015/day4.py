#!/usr/bin/python3
import hashlib as hl
import time
key = ""
with open("day4IN") as f:
	key = f.read()
cas1 = time.time()
for i in range(1000000,10000000,1):
	keyz = key + str(i)
	res = hl.md5(keyz.encode())
	res = res.hexdigest()
	if res.startswith("000000"):
		print(i,res)
		cas = cas1 -time.time()
		print("Took ",cas)
		break
