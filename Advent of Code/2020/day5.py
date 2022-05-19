#\!/usr/bin/python3
import itertools as iter
seats = []
rowH = 0
columnH = 0
highestID = 0
my_row = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127]
my_column = [0,1,2,3,4,5,6,7]
# my_seat = list(iter.product(my_row,my_column))
def product(*args):
    if not args:
        return iter(((),)) # yield tuple()
    return (items + (item,) 
            for items in product(*args[:-1]) for item in args[-1])
with open("day5IN") as file:
    seats = file.readlines()
    seats = [seat.rstrip() for seat in seats]
# === part 1 ===
for seat in seats:
    r_seats = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127]
    c_seats = [0,1,2,3,4,5,6,7]
    rows = seat[0:7]
    columns = seat[7:11]
    for row in rows:
        if row == 'F':
            r_seats = r_seats[0:int(len(r_seats)/2)]
        elif row == 'B':
            r_seats = r_seats[int(len(r_seats)/2):len(r_seats)]
    for column in columns:
        if column == 'L':
            c_seats = c_seats[0:int(len(c_seats)/2)]
        elif column == 'R':
            c_seats = c_seats[int(len(c_seats)/2):len(c_seats)]
    current_ID = r_seats[0]*8+c_seats[0]
    if current_ID > highestID:
        highestID = current_ID
#print(highestID)
# === part 2 ===