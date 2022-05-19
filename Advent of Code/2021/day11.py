#\!/usr/bin/python3
import numpy as np
dumbo_octopuses = []
with open("day11IN") as file:
    dumbo_octopuses = file.readlines()
    dumbo_octopuses =[dumbo_octopuse.rstrip() for dumbo_octopuse in dumbo_octopuses]
dumbo_octopuses = np.array(dumbo_octopuses)
print(dumbo_octopuses)
flashes = 0
dumbo_step = np.zeros((len(dumbo_octopuses),len(dumbo_octopuses[0])))
def inner_flashes():
    global flashes
    for i in range(1,len(dumbo_octopuses)):
        for j in range(1,len(dumbo_octopuses[i])):
            if dumbo_octopuses[i][j] > 9:
                flashes +=1
                dumbo_octopuses[i][j]=0
                dumbo_step[i][j] = 1

                dumbo_octopuses[i-1][j-1]+=1
                dumbo_step[i-1][j-1] = 1

                dumbo_octopuses[i-1][j]+=1
                dumbo_step[i-1][j] = 1

                dumbo_octopuses[i-1][j+1]+=1
                dumbo_step[i-1][j+1] = 1

                dumbo_octopuses[i][j+1]+=1
                dumbo_step[i][j+1] = 1

                dumbo_octopuses[i+1][j+1]+=1
                dumbo_step[i+1][j+1] = 1

                dumbo_octopuses[i+1][j]+=1
                dumbo_step[i+1][j] = 1

                dumbo_octopuses[i+1][j-1]+=1
                dumbo_step[i+1][j-1] = 1

                dumbo_octopuses[i][j-1]+=1
                dumbo_step[i][j-1] = 1
            elif dumbo_octopuses[i][j] <=9 and dumbo_step[i][j]!=1:
                dumbo_octopuses[i][j]+=1

def corner_flashes():
    pass
def border_flashes():
    pass
for i in range(0,1):
    inner_flashes()
print(dumbo_octopuses)