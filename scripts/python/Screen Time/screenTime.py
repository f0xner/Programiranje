#!/usr/bin/python3
import cv2
import pytesseract
import numpy as np
from pytesseract import Output
import glob as gb
import json
import os

def get_gray_inverse(image):
    image = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    return cv2.bitwise_not(image)
def edit_image(filename):
    img = cv2.imread(filename)
    if img.shape != (992,660,3):
        img = img[474:(474+1706),:850]
        img1 = img[10:90,190:]
        img2 = img[794:,190:]
        img = np.concatenate((img1,img2),axis=0)
        img = get_gray_inverse(img)
        cv2.imwrite(filename,img)
def get_text(filename):
    img = cv2.imread(filename)
    text = pytesseract.image_to_string(img,output_type=Output.DICT)
    text = text_to_list(text)
    return text
def text_to_list(text):
    data = []
    for dt in text['text'].split("\n"):
        if dt != '' and dt != "\x0c":
            data.append(dt)
    for i in range(0,len(data)):
        if "Thr" in data[i]:
            data[i] = data[i].replace("Thr", "1 hr")
        if "1hr" in data[i]:
            data[i] = data[i].replace("1hr", "1 hr")
    return data
def crop_images(dirs):
    for dir in dirs:
        imgs = gb.glob(f"{dir}*.jpg")
        imgs.sort()
        for img in imgs:
            edit_image(img) 
def to_hours(hours_minutes):
    hours_minutes = hours_minutes.replace(",","")
    dets = hours_minutes.split(" ")
    if len(dets) == 4:
        if dets[0] == "Less":
            return 0.02
        hours = int(dets[0])
        minutes = int(dets[2])
        return round(hours+minutes/60,2)
    else:
        try:
            return round(int(float(str(dets[0])))/60,2)
        except:
            return f"{dets[0]} minutes"
def to_json(dt):
    try:
        dt = {
            "total hours": to_hours(dt[0]),
            "apps":{
                "app1":{
                    "app" : dt[1],
                    "hours" : to_hours(dt[2]),
                },
                "app2":{
                    "app" : dt[3],
                    "hours" : to_hours(dt[4]),
                },
                "app3":{
                    "app" : dt[5],
                    "hours" : to_hours(dt[6]),
                },
                "app4":{
                    "app" : dt[7],
                    "hours" : to_hours(dt[8]),
                },
                "app5":{
                    "app" : dt[9],
                    "hours" : to_hours(dt[10]),
                },
            }
        }
    except: 
        dt = {
            "total hours": "TO BE ADDED",
            "apps":{
                "app1":{
                    "app" : "TO BE ADDED",
                    "hours" : "TO BE ADDED",
                },
                "app2":{
                    "app" : "TO BE ADDED",
                    "hours" : "TO BE ADDED",
                },
                "app3":{
                    "app" : "TO BE ADDED",
                    "hours" : "TO BE ADDED",
                },
                "app4":{
                    "app" : "TO BE ADDED",
                    "hours" : "TO BE ADDED",
                },
                "app5":{
                    "app" : "TO BE ADDED",
                    "hours" : "TO BE ADDED",
                },
            }
        }
    return json.dumps(dt)
def to_file(dirname,data):
    dirname = f"{dirname[:-1]}.json"
    day = 0
    with open(dirname,'w') as file:
        file.write("{")
        for i in range(0,len(data)):
            file.write(f"\"day{day}\":")
            file.write(to_json(data[i]))
            if i != len(data)-1:
                file.write(",")
            day+=1
        file.write("}")
def get_from_file_data(dirname):
    dirname = f"{dirname[:-1]}.json"
    data = []
    with open(dirname) as file:
        data = json.load(file)
    return data
def get_images_data(dirs):
    all_data = []
    for dir in dirs:
        image_data=[]
        if not os.path.isfile(f"{dir[:-1]}.json"):
            imgs = gb.glob(f"{dir}*.jpg")
            imgs.sort()
            for img in imgs:
                data = get_text(img)
                image_data.append(data)
            to_file(dir,image_data)
            # print(f"Done: {dir[:-1]}.json")
        else:
            all_data.append(get_from_file_data(dir))
            # print(f"{dir[:-1]}.json allready exists")     
    return all_data
def get_data_from_csv():
    pass
dirs = gb.glob("*/")
dirs.sort()
# get_images_data(dirs)
