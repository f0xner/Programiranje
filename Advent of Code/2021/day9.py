#\!/usr/bin/python3
import numpy as np
points = 0
with open("day9IN") as file:
    inpus = file.readlines()
    inpus = [inpu.rstrip() for inpu in inpus]
    p = [[]]
    for i in range(0,len(inpus)):
        for j in range(0,len(inpus[i])):
            p[i].append(int(inpus[i][j]))
        if i != len(inpus)-1:
            p.append([])
    # print(p)
    xlen = len(p)
    ylen = len(p[0])
    points = np.zeros([xlen,ylen])
    for i,j in enumerate(p):
        points[i][0:len(j)] = j
def find_border_lows():
    lows = 0
    # == left / right ==
    for i in range(1,len(points)):
        num = points[i][0]
        num2 = points[i][-1]
        if num < points[i-1][0] and num < points[i][1] and num < points[i+1][0]:
            lows+=1+num
        if num2 < points[i-1][-1] and num2 < points[i][-2] and num2 < points[i+1][-1]:
            lows+=1+num2
    # == top / bottom ==
    for i in range(1,len(points[0])-1):
        num = points[0][i]
        num2 = points[-1][i]
        if num < points[0][i-1] and num < points[1][i] and num < points[0][i+1]:
            lows+=1+num
        if num2 < points[-1][i-1] and num2 < points[-2][i] and num2 < points[-1][i+1]:
            lows+=1+num2
    return lows
def find_corner_lows():
    lows = 0
    top_left = points[0][0]
    if top_left< points[0][1] and top_left< points[1][0]:
        lows+=1+top_left
    top_right = points[0][-1]
    if top_right< points[0][-2] and top_right< points[1][-1]:
        lows+=1+top_right
    bottom_left = points[-1][0]
    if bottom_left< points[-2][0] and bottom_left< points[-1][1]:
        lows+=1+bottom_left
    bottom_right = points[-1][-1]
    if bottom_right< points[-1][-2] and bottom_right< points[-2][-1]:
        lows+=1+bottom_right
    return lows
def find_inner_lows():
    lows = 0
    for i in range(1,len(points)-1):
        for j in range(1,len(points[i])-1):
            num = points[i][j]
            up =  points[i-1][j]
            down =  points[i+1][j]
            left =  points[i][j-1]
            right =  points[i][j+1]
            if num<up and num<down and num<left and num<right:
                lows +=1+num
    return lows
border_lows = find_border_lows()
corner_lows = find_corner_lows()
inner_lows = find_inner_lows()
risk_levels = border_lows + corner_lows + inner_lows
print(risk_levels)