#!/usr/bin/python3
import numpy as np
bingo_boards = []
numbers = []
np_winner = np.array([-1,-1,-1,-1,-1])
def setup():
    global bingo_boards
    global numbers
    bingos = []
    with open("day4IN") as file:
        bingos = file.readlines()
        bingos = [bingo.rstrip() for bingo in bingos]
    numbers = bingos[0].split(",")
    numbers = np.asarray(numbers,dtype=np.int32)
    bingos = bingos[1:]
    i = -1
    for b in bingos:
        if b != '':
            bingo_boards[i].append(b)
        else:
            bingo_boards.append([])
            i+=1
    for i in range(0,len(bingo_boards)):
        for j in range(0,len(bingo_boards[i])):
            bingo_boards[i][j] = bingo_boards[i][j].strip().replace("  "," ").split(" ")
    bingo_boards = np.asarray(bingo_boards,dtype=np.int32)
def check_winner(bingo_board):
    for i in range(0,5):
        if (bingo_board[i] == np_winner).all():
           return True
        j = 0
        while bingo_board[j][i] == -1:
            j+=1
            if j<5:
                continue
            else:
                break
        if j == 5:
            return True
def calc_winner(bingo_board,num):
    sum = 0
    for row in bingo_board:
        sum += np.sum(row,where=row>0)
    print(bingo_board)
    print(sum,num)
    print(sum*num)
    return True
def calc_winner_pt2(num,index):
    global bingo_boards
    if len(bingo_boards) == 1 and check_winner(bingo_boards[0]):
        return calc_winner(bingo_boards[0],num)
    try:
        if len(bingo_boards) > 1:
            temp = bingo_boards[:index]
            bingo_boards = bingo_boards[index+1:]
            bingo_boards = np.concatenate((temp,bingo_boards))
            return False
    except:
        pass
def main():
    global bingo_boards
    global numbers
    for num in numbers:
        for i in range(0,len(bingo_boards)):
            if num in bingo_boards[i]:
                res = np.where(bingo_boards[i] == num)
                bingo_boards[i][res[0][0]][res[1][0]] = -1
        for i in range(0,len(bingo_boards)):
            try:
                if check_winner(bingo_boards[i]):
                    if calc_winner_pt2(num,i):
                        break
            except:
                pass
        else:
            continue
        break
setup()
main()