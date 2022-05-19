#!/usr/bin/python3

bingos = []
with open("day4IN") as file:
    bingos = file.readlines()
    bingos = [bingo.rstrip() for bingo in bingos]


def there_is_winner(board):
    d2_board = []
    for i in range(0, 5):
        d2_board.append([])
        nums = str(board[i]).split(" ")
        for j in range(0, 5):
            if nums[j] != '' and nums[j] != '0-1':
                d2_board[i].append(int(nums[j]))
            if nums[j] == '0-1':
                d2_board[i].append(-1)
        for i in range(0, 5):
            r_sum = 0
            c_sum = 0
            for j in range(0, 5):
                try:
                    r_sum += d2_board[i][j]
                    c_sum += d2_board[j][i]
                except:
                    pass
            if c_sum == -5 or r_sum == -5:
                return True
    # print("d2: ",d2_board)
    return False
def unmarked_Sum(board):
    sum = 0
    for row in board:
        nums = row.split(" ")
        for num in nums:
            if num != -1 and num != '' and num != '0-1':
                sum += int(num)
    return sum
bingo_numbers = bingos[0].split(",")
del bingos[0:2]
bingo_boards = [[]]
unmarked_sum = 0
last_drawn = 0
j = 0
brk = False
bingo_winners = []
for i in range(0, len(bingos)):
    if bingos[i] != "":
        bingo_boards[j].append(bingos[i])
    else:
        j += 1
        bingo_boards.append([])
for bingo_number in bingo_numbers:
    if int(bingo_number) < 10:
        bingo_number = "0"+str(bingo_number)
    for i in range(0,3):
        for j in range(0, 5):
            nums = str(bingo_boards[i][j]).split(" ")
            if bingo_number in nums:
                bingo_boards[i][j] = bingo_boards[i][j].replace(bingo_number, "0-1")
        if there_is_winner(bingo_boards[i]):
            print("w",bingo_boards[i])
            if i not in bingo_winners:
                bingo_winners.append(i)
            if len(bingo_winners) == 2:
                print("winner")
                brk = True
                last_drawn = int(bingo_number)
                unmarked_sum = unmarked_Sum(bingo_boards[i])
                break
        if brk:
            break
    if brk:
        break

# === part 1 / part 2 ===
print(unmarked_sum, last_drawn)
print(unmarked_sum*last_drawn)