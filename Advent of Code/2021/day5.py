#!/usr/bin/python3
import numpy as np

xs_ys = []
with open("day5IN") as file:
    xs_ys = file.readlines()
    xs_ys = [x_y.rstrip() for x_y in xs_ys]
    xs_ys = [x_y.split(" -> ") for x_y in xs_ys]
def find_highest():
    global xs_ys
    xM = 0
    yM = 0
    for x_y in xs_ys:
        x1,y1 = x_y[0].split(",")
        x2,y2 = x_y[1].split(",")
        x1 = int(x1)
        y1 = int(y1)
        x2 = int(x2)
        y2 = int(y2)
        if x1 > xM or x2 > xM:
            xM = max(x1,x2)
        if y1 > yM or y2 > yM:
            yM = max(y1,y2)
    return xM,yM
xM,yM = find_highest()
grid = np.zeros((xM+2,yM+2))
def is_horizontal_vertical(pair):
    x1,y1 = pair[0].split(",")
    x2,y2 = pair[1].split(",")
    x1 = int(x1)
    y1 = int(y1)
    x2 = int(x2)
    y2 = int(y2)
    if y1 == y2:
        if x1 > x2:
            return 0
        else:
            return 1
    elif x1 == x2:
        if y1 > y2:
            return 2
        else:
            return 3
    elif y1<y2:
        if x1<x2:
            return 4
        else:
            return 5
    elif y1>y2:
        if x1<x2:
            return 6
        else:
            return 7
    else:
        return -1
for x_y in xs_ys:
    x1,y1 = x_y[0].split(",")
    x2,y2 = x_y[1].split(",")
    x1 = int(x1)
    y1 = int(y1)
    x2 = int(x2)
    y2 = int(y2)
    i_H_V = is_horizontal_vertical(x_y)
    if i_H_V == 0:#levo
        for i in range(x1,x2-1,-1):
            grid[y1][i]+=1
    elif i_H_V == 1:#desno
        for i in range(x1,x2+1):
            grid[y1][i]+=1
    elif i_H_V == 2:#gor
        for i in range(y1,y2-1,-1):
            grid[i][x1]+=1
    elif i_H_V == 3:#dol
        for i in range(y1,y2+1):
            grid[i][x1]+=1
    elif i_H_V == 4:#desno_dol
        while(x1!=x2+1 and y1!=y2+1):
            grid[y1][x1]+=1
            x1+=1
            y1+=1
    elif i_H_V == 5:#levo_dol
        while(x1!=x2-1 and y1!=y2+1):
            grid[y1][x1]+=1
            x1-=1
            y1+=1
    elif i_H_V == 6:#desno_gor
        while(x1!=x2+1 and y1!=y2-1):
            grid[y1][x1]+=1
            x1+=1
            y1-=1
    elif i_H_V == 7:#levo_gor
        while(x1!=x2-1 and y1!=y2-1):
            grid[y1][x1]+=1
            x1-=1
            y1-=1
print(np.count_nonzero(grid >= 2))