#\!/usr/bin/python3
import numpy as np

def fuel_cost(unique, count, target):
    fuel = 0
    diff = abs(unique-target)
    for i in range(0,diff):
        fuel+=(i+1)
    return fuel*count
crabs = []
with open("day7IN") as file:
    crabs = file.readlines()
    crabs = [crab.rstrip() for crab in crabs]
    crabs = crabs[0].split(",")
for i in range(0,len(crabs)):
    crabs[i] = int(crabs[i])
crabs = np.array(crabs)
crabs = np.sort(crabs)
lowest = crabs[0]
highest = crabs[-1]
avg = np.average(crabs)
# print(crabs,avg)
uniques, counts = np.unique(crabs,return_counts=True)
fuel_costs_unigues = []
# target = lowest_target(uniques,counts)
target = lowest
fuels = []
for target in range(lowest,highest):
    fuel_costs_unigues = []
    for unique, count in zip(uniques,counts):
        fuel_costs_unigues.append(fuel_cost(unique,count,target))
    fuel = np.array(fuel_costs_unigues)
    fuel_Cost = np.sum(fuel)
    fuels.append(fuel_Cost)
fuels = np.array(fuels)
fuels = np.sort(fuels)
print(fuels[0])