#!/usr/bin/python3

bi_numbers = []
most_commons = []
with open("day3IN") as file:
    bi_numbers = file.readlines()
    bi_numbers = [bi_number.rstrip() for bi_number in bi_numbers]
for i in range(0,len(bi_numbers[0])):
    most_commons.append([0,0])
for i in range(0,len(bi_numbers[0])):
    for j in range(0,len(bi_numbers)):
        if bi_numbers[j][i] == "0":
            most_commons[i][0]+=1
        if bi_numbers[j][i] == "1":
            most_commons[i][1]+=1
#print(most_commons)
gama_rate = ""
epsilon_rate = ""
for most_common in most_commons:
    if most_common[0] > most_common[1]:
        gama_rate+="0"
        epsilon_rate+="1"
    else:
        epsilon_rate+="0"
        gama_rate+="1"
# === part 1 ===

# gama_rate = int(gama_rate,2)
# epsilon_rate = int(epsilon_rate,2)
# power_consumption = gama_rate*epsilon_rate
# print(power_consumption)

# === part 2 ===
oxygen_generator = bi_numbers
oxygen_gen = bi_numbers
oxy_rating = 0
C02_scrubber = bi_numbers
sW = ""
for i in range(0,len(gama_rate)):
    sW += gama_rate[i]
    for j in range(0,len(oxygen_generator)-1):
        if len(oxygen_gen) == 1:
            oxy_rating = int(oxygen_generator[0],2)
            print("oxy rating:",oxy_rating)
            break
        if not oxygen_generator[j].startswith(sW):
            oxygen_gen.remove(oxygen_generator[i])
    print(oxygen_gen,sW)
    













'''
for i in range(0,len(gama_rate)):
    startswith += gama_rate[i]
    oxygen_generator_r_2 = []
    for oxygen_generator in oxygen_generator_r_1:
        if oxygen_generator.startswith(startswith):
            oxygen_generator_r_2.append(oxygen_generator)
    oxygen_generator_r_1 = oxygen_generator_r_2
    if len(oxygen_generator_r_1) == 2:
        startswith += "1"
        oxygen_generator_r_2 = []
        for oxy_gen in oxygen_generator_r_1:
            if oxy_gen.startswith(startswith):
                oxygen_generator_r_2.append(oxy_gen)
    oxygen_generator_r_1 = oxygen_generator_r_2
    if len(oxygen_generator_r_1) == 1:
        break
startswith = ""
for i in range(0,len(epsilon_rate)):
    startswith += epsilon_rate[i]
    C02_scrubber_r_2 = []
    for C02_scrubber in C02_scrubber_r_1:
        if C02_scrubber.startswith(startswith):
            C02_scrubber_r_2.append(C02_scrubber)
    C02_scrubber_r_1 = C02_scrubber_r_2
    if len(C02_scrubber_r_1) == 2:
        startswith += "0"
        C02_scrubber_r_2 = []
        for co2_gen in C02_scrubber_r_1:
            if co2_gen.startswith(startswith):
                C02_scrubber_r_2.append(co2_gen)
    C02_scrubber_r_1 = C02_scrubber_r_2
    if len(C02_scrubber_r_1) == 1:
        break
print("oxy int: ",int(oxygen_generator_r_1[0],2))
print("co2 int: ",int(C02_scrubber_r_1[0],2))
print(int(C02_scrubber_r_1[0],2)*int(oxygen_generator_r_1[0],2))
'''