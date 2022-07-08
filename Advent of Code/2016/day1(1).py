import math

directions = input()
directions = directions.split(", ")
forward = 0 #N 0,1,2,3
grid = [0,0]

for dir in directions:
    if dir.startswith("R"):
        forward+=1
    if dir.startswith("L"):
        forward-=1
    if forward > 3:
        forward = 0
    if forward < 0:
        forward = 3 
    steps = int(dir[1:])
    if forward == 0:
        grid[1]+=steps
    if forward == 1:
        grid[0]+=steps
    if forward == 2:
        grid[1]-=steps
    if forward == 3:
        grid[0]-=steps

print(grid[0] + grid[1])
    
