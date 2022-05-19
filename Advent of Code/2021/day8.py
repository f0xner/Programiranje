#\!/usr/bin/python3
from os import setgid
import numpy as np
digits = []
with open("day8IN") as file:
    digits = file.readlines()
digits = [digit.rstrip() for digit in digits]
digits = [digit.split(" | ") for digit in digits]
# print(digits)
# === part 1 ===
# sum = 0
# for digit_group in digits:
#     digits = digit_group[1].split(" ")
#     for digit in digits:
#         if len(digit) == 2 or len(digit) == 4 or len(digit) == 3 or len(digit) == 7:
#             sum+=1
# print(sum)
# === part 2 ===
sum = 0
# print(digits)
# =============== 0 ======= 1 ====== 2 ====== 3 ====== 4 ====== 5 ====== 6
segment_layout ={"aaa":"","bbb":"","ccc":"","ddd":"","eee":"","fff":"","ggg":"",}
segment_layout2 = ["","","","","","",""]
def find_7_1_segments(digit):
    one = ""
    seven = ""
    ds = digit[0].split(" ")
    for d in ds:
        if len(d) == 2:
            one = d
        elif len(d) == 3:
            seven = d
    df = seven.replace(one[0],"").replace(one[1],"")
    segment_layout2[0] = df
    segment_layout2[2] = one
    segment_layout2[5] = one
    return one,seven
def find_4_segment(digit,one):
    four = ""
    ds = digit[0].split(" ")
    for d in ds:
        if len(d) == 4:
            four = d
            break
    df = four.replace(one[0],"").replace(one[1],"")
    segment_layout2[1] = df
    segment_layout2[3] = df
    return four
def find_8_segment(digit,one,four):
    eight = ""
    ds = digit[0].split(" ")
    for d in ds:
        if len(d) == 7:
            eight = d
            break
    e = eight
    eight = eight.replace(segment_layout2[0],"")
    for f in four:
        eight = eight.replace(f,"")
    segment_layout2[4] = eight
    segment_layout2[6] = eight
    return e
def find_2_3_5(digit):
    otf = []
    ds = digit[0].split(" ")
    for d in ds:
        if len(d) == 5:
            otf.append(d)
    return otf
def find_0_6_9(digit):
    zsn = []
    ds = digit[0].split(" ")
    for d in ds:
        if len(d) == 6:
            zsn.append(d)
    return zsn
def one_left(otf,zsn):
    zsno = zsn
    for i in range(0,len(otf)):
        zsn = zsn.replace(otf[i],"")
    if len(zsn) == 1:
        for i in range(0,7):
            if zsn in segment_layout2[i]:
                segment_layout2[i] = zsn
                break
        for i in range(0,7):
            if zsn in segment_layout2[i]:
                if len(segment_layout2[i]) == 2:
                    segment_layout2[i] = segment_layout2[i].replace(zsn,"")
                    break
def segment_to_digit(segment):
    segments = []
    for s in segment:
        segments.append(segment_layout2.index(s))
    segments = np.array(segments)
    segments = np.sort(segments)
    segments = np.array2string(segments)
    if segments == "[0 1 2 4 5 6]":
        return 0
    elif segments == "[2 5]":
        return 1
    elif segments == "[0 2 3 4 6]":
        return 2
    elif segments == "[0 2 3 5 6]":
        return 3
    elif segments == "[1 2 3 5]":
        return 4
    elif segments == "[0 1 3 5 6]":
        return 5
    elif segments == "[0 1 3 4 5 6]":
        return 6
    elif segments == "[0 2 5]":
        return 7
    elif segments == "[0 1 2 3 4 5 6]":
        return 8
    elif segments == "[0 1 2 3 5 6]":
        return 9
output_values = 0
for digit in digits:
    one,seven = find_7_1_segments(digit)
    four = find_4_segment(digit,one)
    eight = find_8_segment(digit,one,four)
    otf = find_2_3_5(digit)
    zsn = find_0_6_9(digit)
    for i in range(0,3):
        for j in range(0,3):
            one_left(otf[i],zsn[j])
    ds = digit[1].split()
    nums = ""
    for d in ds:
        nums += str(segment_to_digit(d))
    # print(digit[1],int(nums))
    output_values += int(nums)
print(output_values)