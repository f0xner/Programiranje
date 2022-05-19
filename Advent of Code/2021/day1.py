#!/usr/bin/python3
# === part 1 ===
depths = []
increases = 0
with open("day1IN") as file:
    depths = file.readlines()
    depths = [depth.rstrip() for depth in depths]
for i in range(0,len(depths)-1,1):
    if int(depths[i]) < int(depths[i+1]):
        increases+=1
print("Part 1: ",increases)

# === part 2 ===
# depths = []
# with open("day1IN") as file:
#     depths = file.readlines()
#     depths = [depth.rstrip() for depth in depths]
sums = []
increases = 0

for i in range(0,len(depths)-2,1):
    sums.append(int(depths[i]) + int(depths[i+1]) + int(depths[i+2]))
for i in range(0,len(sums)-1,1):
    if sums[i] < sums[i+1]:
        increases+=1
print("Part2: ", increases)