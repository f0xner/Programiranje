import json
import matplotlib.pyplot as plt
import numpy as np
from numpy.core.numeric import indices
from screenTime import get_images_data as gid
import glob as gb
def total_hours(data):
    hours = []
    days = []
    day = 1
    for i in range(0,len(data)):
        j = 0
        b = True
        while b:
            try:
                hours.append(data[i][f"day{j}"]["total hours"])
                days.append(day)
                day+=1
                j+=1
            except:
                b=False
    # for i in range(len(data))
    # print(dt[f"day{i}"]["total hours"])
    return hours,days
def total_hours_show(total,days):
    plt.plot(days,total_hours)
    mva = np.convolve(total_hours,np.ones(14),'valid')/14
    plt.plot(mva)
    plt.xlabel("Days")
    plt.ylabel("Hours")
    plt.show()
def total_vs_real():
    print(f"In {len(total_hours)} days, total hours: {round(np.sum(total_hours),3)}, in %: {round(np.sum(total_hours)/(len(total_hours)*24),3)}")
def aah(data):
    aah_data = {}
    indice = {}
    index = 0
    for i in range(0,len(data)):
        for day in range(0,len(data[i])):
            obj = data[i][f"day{day}"]["apps"]
            for k in range(1,6):
                objj = obj[f"app{k}"]
                try:
                    aah_data[objj["app"]] += round(float(objj["hours"]),2)
                except:
                    aah_data[objj["app"]] = round(float(objj["hours"]),2)
                    indice[index] = objj["app"]
                    index+=1
    return aah_data,indice
def pie_aah_show(data,indice,treshold):
    labels = []
    hours = []
    for i in range(0,len(indice)):
        if(data[indice[i]])>=treshold:
            labels.append(indice[i])
    labels.append("Other")
    for label in labels:
        hours.append(data[label])
    # print(labels,hours)
    # for label,hour in zip(labels,hours):
    #     print(label,hour)
    _, ax1 = plt.subplots()
    ax1.pie(hours, labels=labels, autopct='%1.1f%%', shadow=True, startangle=90)
    ax1.axis('equal')  # Equal aspect ratio ensures that pie is drawn as a circle.
    plt.show()
def edit_aah(data,indice,treshold):
    data["Other"] = 0
    to_del = []
    sum = 0
    for i in range(0,len(indice)):
        if data[indice[i]] < treshold:
            # data["Other"] += data[indice[i]]
            to_del.append((data[indice[i]],indice[i]))
            sum += data[indice[i]]
    data["Other"] = sum
    return data,indice
dirs = gb.glob("*/")
dirs.sort()
all_data = gid(dirs)
all_apps_hours,indice = aah(all_data[:-1])
all_apps_hours,indice = edit_aah(all_apps_hours,indice,20)
# print(all_apps_hours)
#total_hours,days = total_hours(all_data)
#total_hours_show(total_hours,days)
pie_aah_show(all_apps_hours,indice,20)