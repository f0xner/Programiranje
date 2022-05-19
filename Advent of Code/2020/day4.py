#\!/usr/bin/python3

# === part 1 ===
passport_count = 0
valids = 0
passports = []
passport_blocks = []
passport_blocks.append([])
with open("day4IN") as file:
    passports = file.readlines()
    passports = [passport.rstrip() for passport in passports]
for i in range(0,len(passports)):
    if passports[i] != '':
        passport_blocks[passport_count].append(passports[i])
    else:
        passport_blocks.append([])
        passport_count+=1
for passport_block in passport_blocks:
    keys = ["byr","iyr","eyr","hgt","hcl","ecl","pid","cid"]
    for line in passport_block:
        key_values = line.split(" ")
        for key_value in key_values:
            key = key_value.split(":")[0]
            if key in keys:
                keys.remove(key)
    if len(keys) == 0 or (len(keys) == 1 and keys[0] == "cid"):
        valids += 1
print(valids)
# === part 2 ===
valids = 0
def check_color_validity(value):
    if value.startswith("#"):
        if len(value) == 7:
            value = value.replace("#","0x")
            value = int(value,16)
            if value >= 0 and value<=16777215:
                return True
    else:
        return False
def check_height_validity(value):
    if value.endswith("cm"):
        if len(value) == 5:
            value = int(value[0:3])
            if value >= 150 and value <= 193:
                return True
    elif value.endswith("in"):
        if len(value) == 4:
            value = int(value[0:2])
            if value >= 59 and value <= 76:
                return True
    return False
for passport_block in passport_blocks:
    keys = ["byr","iyr","eyr","hgt","hcl","ecl","pid","cid"]
    for line in passport_block:
        key_values = line.split(" ")
        for key_value in key_values:
            key = key_value.split(":")[0]
            value = key_value.split(":")[1]
            if key in keys:
                if key == "byr":
                    value = int(value)
                    if value<1920 or value>2002:
                        break
                elif key == "iyr":
                    value = int(value)
                    if value<2010 or value>2020:
                        break
                elif key == "eyr":
                    value = int(value)
                    if value<2020 or value>2030:
                        break
                elif key == "hgt":
                    if not check_height_validity(value):
                        break
                elif key == "hcl":
                    if not check_color_validity(value):
                        break
                elif key == "ecl":
                    eye_colors = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]
                    if value not in eye_colors:
                        break
                elif key == "pid":
                    value = len(value)
                    if value!=9:
                        break
                keys.remove(key)
    if len(keys) == 0 or (len(keys) == 1 and keys[0] == "cid"):
        valids += 1
print(valids)