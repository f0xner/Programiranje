#!/usr/bin/python3
import numpy as np
class Route:
	def __init__(self, cfrom, cto, km):
		self.cfrom = cfrom
		self.cto = cto
		self.km = km

citys = []
routes = []
shortes = np.Infinity

with open("day9IN") as f:
	routes = f.readlines()
	for en,route in enumerate(routes):
		routes[en] = route.split(" ")
		routes[en][-1] = routes[en][-1].replace("\n","")
		del routes[en][1]
		del routes[en][2]
		routes[en] = Route(routes[en][0],routes[en][1],routes[en][2])

for i in range(0,len(routes),1):
	if routes[i].cfrom not in citys:
		citys.append(routes[i].cfrom)
	if routes[i].cto not in citys:
		citys.append(routes[i].cto)
	
def getDistance(start,to):
	for route in routes:
		if route.cfrom == start and route.cto == to:
			return route.km

def city():
	pass


for i in range(0,len(citys),1):
	if distance < shortes:
		shortes = distance
print(shortes)