#!/usr/bin/python3
commands =[]
wires = []
with open("day7IN") as f:
	commands = f.readlines()
for command in commands:
	command = command.split(" ")
	command[-1] = command[-1].replace("\n","")
	del command[-2]
	if len(command) == 2:
		print(command)
		value = command[0]
		if command[-1] not in wires:
			wires.append([value,command[-1]])
		else:
			for wire in wires:
				if command[-1] in wire:
					wire = [value,command[1]]
	elif command[0] == "NOT":
		print(command)
		value = 0
		try:
			value = ~int(command[1])
		except:
			for wire in wires:
				if command[1] in wire:
					value = ~int(wire[0])
		for en,wire in enumerate(wires):
			if command[-1] == wire[1]:
				wires[en] = [value,command[-1]]
		if command[-1] not in wires:
			wires.append([value,command[-1]])
	elif command[1] == "AND":
		print(command)
		wire1 = command[0]
		wire2 = command[2]
		value1 = 0
		value2 = 0
		try:
			value1 = int(wire1)
			value2 = int(wire2)
		except:
			for wire in wires:
				if wire1 == wire[1]:
					value1 = int(wire[0])
				if wire2 == wire[1]:
					value2 = int(wire[0])
		value = value1 & value2
		for en, wire in enumerate(wires):
				if command[-1] == wire[1]:
					wires[en] = [value,command[-1]]
		if command[-1] not in wires:
			wires.append([value,command[-1]])
	elif command[1] == "LSHIFT":
		print(command)
		wire1 = command[0]
		shift_value = int(command[2])
		try:
			value1 = int(wire1)
		except:
			for en, wire in enumerate(wires):
				if wire1 == wire[1]:
					value1 = wire[0]
		value = value1
		for i in range(0,shift_value,1):
			value = int(value)<<1
		for en, wire in enumerate(wires):
				if command[-1] == wire[1]:
					wires[en] = [value,command[-1]]
		if command[-1] not in wires:
			wires.append([value,command[-1]])
	elif command[1] == "RSHIFT":
		print(command)
		wire1 = command[0]
		shift_value = int(command[2])
		try:
			value1 = int(wire1)
		except:
			for en, wire in enumerate(wires):
				if wire1 == wire[1]:
					value1 = wire[0]
		value = value1
		for i in range(0,shift_value,1):
			value = int(value)>>1
		for en, wire in enumerate(wires):
				if command[-1] == wire[1]:
					wires[en] = [value,command[-1]]
		if command[-1] not in wires:
			wires.append([value,command[-1]])
	elif command[1] == "OR":
		print(command)
		wire1 = command[0]
		wire2 = command[2]
		value1 = 0
		value2 = 0
		try:
			value1 = int(wire1)
			value2 = int(wire2)
		except:
			for en, wire in enumerate(wires):
				if wire1 == wire[1]:
					value1 = int(wire[0])
				if wire2 == wire[1]:
					value2 = int(wire[0])
		value = value1 | value2
		for en, wire in enumerate(wires):
				if command[-1] == wire[1]:
					wires[en] = [value,command[-1]]
		if command[-1] not in wires:
			wires.append([value,command[-1]])

			
for wire in wires:
	if wire[1] == "a":
		print(wire[0])