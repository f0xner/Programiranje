#!/usr/bin/python3
fishes = []
import numpy as np
days = 256
with open("day6IN") as file:
    fishes = file.readline()
    fishes = fishes.split(",")
    fishes = np.asarray(fishes,dtype=np.uint8)
for i in range(0,len(fishes)):
    fishes[i] = int(fishes[i])
add = 0
for x in range(0,days):
    add = 0
    i = 0
    fishes = np.sort(fishes)
    while(fishes[i]<1):
        fishes[i] = 6
        add+=1
        i+=1
    while(i<fishes.size):
        fishes[i]-=1
        i+=1
    for j in range(0,add):
        fishes = np.insert(fishes,fishes.size,8)
print(fishes.size)