#\!/usr/bin/python3
squares_trees = []
trees = 0
with open("day3IN") as file:
    squares_trees = file.readlines()
    squares_trees = [square_tree.rstrip() for square_tree in squares_trees]
# === part 1 ===
# x = 0
# for square_tree in squares_trees:
#     temp_x = 0
#     # print("x: ",x)
#     k = x//len(square_tree)
#     temp_x = x - k*len(square_tree)
#     # print("temp_x: ",temp_x)
#     if square_tree[temp_x]=="#":
#         trees+=1
#     x += 3

# **************************************++

# === part 2 ===
slopes = ["Right 1, down 1","Right 3, down 1","Right 5, down 1","Right 7, down 1","Right 1, down 2"]
slope_trees = []
for slope in slopes:
    trees = 0
    x_step = int(slope.split(", ")[0].split(" ")[1])
    x = 0
    y = int(slope.split(", ")[1].split(" ")[1])
    for i in range(0,len(squares_trees),y):
        temp_x = 0
        k = x//len(squares_trees[i])
        temp_x = x - k*len(squares_trees[i])
        if squares_trees[i][temp_x]=="#":
            trees+=1
        x += x_step
    slope_trees.append(trees)
print(slope_trees)
multi = slope_trees[0]
for i in range(1,len(slope_trees),1):
    multi *= slope_trees[i]
print(multi)