#!/usr/bin/python3
import os
import time as t
def prizgiInSwipe():
    os.system('adb shell input keyevent 26')
    t.sleep(0.01)
    os.system('adb shell input swipe 300 600 300 300')
def koda(stevilka):
    for s in stevilka:
        os.system(f'adb shell input keyevent {int(s)+7}')
        t.sleep(0.1)
def vse():
    prizgiInSwipe()
    koda("246855")
vse()
