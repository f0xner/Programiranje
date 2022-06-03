#!/usr/bin/python3

with open("tocke.csv", "r") as f:
    data = f.readlines()
    data = [d.replace(' ',';') for d in data]
with open("tocke.csv", "w") as f:
   f.writelines(data)