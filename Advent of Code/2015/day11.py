#!/usr/bin/python3
#[97,122]
inpu = "cqjxjnds"
pswd = inpu
nogow = ['i','o','l']
def pswd_meets_requirements(pswd):
	fr_cond = False
	sc_cond = False
	tnop = 0
	for i in range(0,len(pswd)-2,3):
		fr = ord(pswd[i])
		sc = ord(pswd[i+1])
		rd = ord(pswd[i+2])
		if chr(fr+1) == chr(sc) and chr(sc+1)==chr(rd):
			fr_cond = True
	for i in range(0,len(pswd),1):
		if pswd[i] in nogow:
			return False
	for i in range(0,len(pswd),2):
		if pswd[i] == pswd[i+1]:
			tnop +=1
			if tnop >1:
				return True == fr_cond
	return False
def change_last(pswd):
	chrs = list(pswd)
	next_change = False
	new_chr = 97
	for i in range(len(chrs)-1,-1,-1):
		new_chr = (ord(chrs[i]))
		if next_change == True or i == (len(chrs)-1):
			new_chr = (ord(chrs[i])+1)
			next_change = False
		if new_chr == 123:
			new_chr = 97
			next_change = True
		chrs[i] = chr(new_chr)
	pswd = ""
	for ch in chrs:
		pswd+=ch
	return pswd
while True:
	pswd = change_last(pswd)
	if pswd_meets_requirements(pswd) == True:
		print("New pswd: ",pswd)
		break
