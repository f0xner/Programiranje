
grid = [["0","0","1","0","0"],
        ["0","2","3","4","0"],
        ["5","6","7","8","9"],
        ["0","A","B","C","0"],
        ["0","0","D","0","0"],]
x = 0
y = 2
combination = ""
with open("day2IN","r") as f:
    moves = f.readlines()
    moves = [move.replace("\n","") for move in moves]
for move in moves:
    for m in move:
        #print(x,y,m)
        if (m == 'D' and y+1 <= 4):
            if grid[y+1][x] != "0":
                y+=1
        if (m == 'U' and y-1 >= 0):
            if grid[y-1][x] != "0":
                y-=1
        if (m == 'L' and x-1 >= 0):
            if grid[y][x-1] != "0":
                x-=1
        if (m == 'R' and x+1 <= 4):
            if grid[y][x+1] != "0":
                x+=1
        #print(x,y,m,"\n")
    #print(grid[x][y])
    combination += str(grid[y][x])
print(combination)