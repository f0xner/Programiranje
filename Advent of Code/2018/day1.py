import numpy as np
with open("day1IN", "r") as f:
    data = f.readlines()
    data = [dt.replace("\n","") for dt in data]
    data = [int(dt) for dt in data]
#print(data)
arr = np.array(data)
#print(np.sum(arr))
summ = 0
frequencies = []
for dt in data:
    summ+=dt
    if summ in frequencies:
        print(summ)
        break
    if summ not in frequencies:
        frequencies.append(summ)
    
print(frequencies)