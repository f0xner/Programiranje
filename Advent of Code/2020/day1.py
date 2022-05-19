#!/usr/bin/python3
data = []
with open("day1IN") as f:
    data = f.read().split("\n")
del data[-1]
for i in range(0,len(data),1):
    data[i] = int(data[i])
data.sort()

#615156678
