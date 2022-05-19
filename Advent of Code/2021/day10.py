#\!/usr/bin/python3
import numpy as np
# ): 3 points.
# ]: 57 points.
# }: 1197 points.
# >: 25137 points.


chunks = []
with open("day10IN") as file:
    chunks = file.readlines()
    chunks = [chunk.rstrip() for chunk in chunks]
    chunks = np.array(chunks)
def is_valid(chunk):
    # open_close = np.zeros(4)#0: () 1: [] 2: {} 3: <>
    # open_close[0] += chunk.count("(")
    brackets = []
    for ch in chunk:
        if ch == "(" or ch == "[" or ch == "{" or ch == "<":
            brackets.append(ch)
        else:
            chh = ""
            if ch == ")":
                chh="("
            elif ch == "]":
                chh="["
            elif ch == "}":
                chh="{"
            elif ch == ">":
                chh="<"
            try:
                x = brackets.index(chh)
                brackets = brackets.pop(x)
            except:
                print(ch,"NOT")
                return [False,ch]
for chunk in chunks:
    print(chunk)
    ret = is_valid(chunk)
    break
    if not ret[0]:
        pass