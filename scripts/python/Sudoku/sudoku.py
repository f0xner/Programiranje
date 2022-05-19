#!/usr/bin/python3
import numpy as np
import math
import time as t
import cv2
from video import get_sudoku
import os
digit_pos = {"1":(190,1755),"2":(380,1755),"3":(550,1755),"4":(750,1755),"5":(890,1755),"6":(190,1930),"7":(380,1930),"8":(550,1930),"9":(750,1930)}
def get_image(ime):
    command = f"adb exec-out screencap -p > {ime}.jpg"
    os.system(command)
    im = cv2.imread(f"{ime}.jpg")
    im = im[400:1480][0:1080]
    # cv2.imshow("title",im)
    cv2.imwrite(f"{ime}.jpg",im)
ime = "sudoTest1"
#   get_image(ime)
img = cv2.imread(f"{ime}.jpg")
sudoku = get_sudoku(img)
# print(sudoku)
def get_valids(sudoku, i, j):
    valids = []
    add = True
    ib = math.floor(i/3)*3
    jb = math.floor(j/3)*3
    for num in range(1,10):
        add = True
        for x in range(0,9):
            if sudoku[x][j] == num or sudoku[i][x] == num:
                add = False
                break
        for g in range(ib,ib+3):
            for h in range(jb,jb+3):
                if sudoku[g][h] == num:
                    add = False
                    break
        if add == True:
            valids.append(num)
    return valids
def solve_singels(sudoku):
    prev_sudoku = np.copy(sudoku)
    while True:
        for i in range(0, 9):
            for j in range(0, 9):
                if sudoku[i][j] == 0:
                    valids = get_valids(sudoku, i, j)
                    if len(valids) == 1:
                        sudoku[i][j] = valids[0]
        if np.allclose(prev_sudoku,sudoku):
            return sudoku
        else:
            prev_sudoku = np.copy(sudoku)
def solve():
    if np.all(sudoku != 0) == True:
        print("solved")
        to_app2(sudoku)
        return sudoku
    for i in range(0, 9):
        for j in range(0, 9):
            if sudoku[i][j] == 0:
                valids = get_valids(sudoku, i, j)
                if len(valids) != 0:
                    for valid in valids:
                        sudoku[i][j] = valid
                        del valid
                        solve()
                        sudoku[i][j] = 0
                return
def to_app(digit,pos1,pos2):
    command = "adb shell input tap "+str(digit_pos[digit][0])+" "+ str(digit_pos[digit][1])
    os.system(command)
    command2 = "adb shell input tap "+str(pos1)+" "+ str(pos2)
    os.system(command2)
def to_app2(sudoku):
    print(sudoku)
    for i in range(0,9):
        for j in range(0,9):
            # print(str(int(sudoku[i][j])),str(j*100+85),str(i*100+450))
            to_app(str(int(sudoku[i][j])),str(j*100+85),str(i*100+450))
            t.sleep(0.1)
solve()