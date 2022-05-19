#\!/usr/bin/python3
fishes = []
days = 80
with open("day6IN") as file:
    fishes = file.readline()
    fishes = fishes.split(",")
for i in range(0,len(fishes)):
    fishes[i] = int(fishes[i])
for i in range(0,days):
    for j in range(0,len(fishes)):
        if fishes[j] == 0:
            fishes.append(8)
            fishes[j] = 6
        else:
            fishes[j] = fishes[j]-1
print(len(fishes))