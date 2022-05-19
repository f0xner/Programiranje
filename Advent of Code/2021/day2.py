#!/usr/bin/python3


# forward X increases the horizontal position by X units.
# down X increases the depth by X units.
# up X decreases the depth by X units
commands_steps = []

with open("day2IN") as file:
    commands_steps = file.readlines()
    commands_steps = [command_step.rstrip() for command_step in commands_steps]

horizontal_position = 0
depth = 0
aim = 0

# === part 1 ===
# for command_step in commands_steps:
#     command = command_step.split(" ")[0]
#     step = int(command_step.split(" ")[1])
#     if command == "forward":
#         horizontal_position += step
#     elif command == "down":
#         depth += step
#     elif command == "up":
#         depth -= step
#         if depth<0:
#             depth = 0

# === part 2 ===
# down X increases your aim by X units.
# up X decreases your aim by X units.
# forward X does two things:
    # It increases your horizontal position by X units.
    # It increases your depth by your aim multiplied by X.

for command_step in commands_steps:
    command = command_step.split(" ")[0]
    step = int(command_step.split(" ")[1])
    if command == "forward":
        horizontal_position += step
        depth += aim*step
        if depth<0:
            depth = 0
    elif command == "down":
        aim += step
    elif command == "up":
        aim -= step
        

print(horizontal_position*depth)
