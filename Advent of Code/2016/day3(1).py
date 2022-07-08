import re

with open("day3IN", "r") as f:
    data = f.readlines()
    data = [line.replace("\n","").strip() for line in data]
    data = [re.sub(' +', ' ', dt) for dt in data]
triangles = [dt.split(" ") for dt in data]

possible = 0
for triangle in triangles:
    if int(triangle[0]) + int(triangle[1]) > int(triangle[2]) or int(triangle[2]) + int(triangle[0]) > int(triangle[1]) or int(triangle[2]) + int(triangle[1]) > int(triangle[0]):
        possible += 1
print(possible)