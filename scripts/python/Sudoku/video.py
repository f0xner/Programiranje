#!usr/bin/python3
import math
import cv2
import numpy as np
from pytesseract import Output
import pytesseract
def edit_img(img):
    img = cv2.resize(img,(870,870))
    img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    return cv2.bitwise_not(img)
def get_sudoku(img):
    img = edit_img(img)
    text = pytesseract.image_to_data(img,config='--psm 6 --oem 3 -c tessedit_char_whitelist=0123456789',output_type=Output.DICT)
    w,h = img.shape
    w = w/9
    h = h/9
    sudoku = np.zeros((9,9))
    for i in range(0,len(text['left'])):
        img = cv2.rectangle(img,(int(text['left'][i]),int(text['top'][i])),(int(text['left'][i])+40,int(text['top'][i])+40),(0,0,255),2)
        cv2.putText(img,text = text['text'][i],org=(int(text['left'][i])-5,int(text['top'][i])-5),fontFace= cv2.FONT_HERSHEY_SIMPLEX, fontScale=1, color=(0,255,0),thickness=2, lineType=cv2.LINE_AA)
        if len(text['text'][i]) == 1:
            y = math.floor(int(text['left'][i])/w)
            x = math.floor(int(text['top'][i])/h)
            sudoku[x][y] = int(text['text'][i])
        else:
            x = math.floor(int(text['top'][i])/h)
            y = math.floor(int(text['left'][i])/w)
            for j in range(0,len(text['text'][i])):
                sudoku[x][y+j] = int(text['text'][i][j])
    return sudoku
# img = cv2.imread("Su12.jpg")
# sudoku = get_sudoku(img)
# cv2.imshow("puzzle",img)
# cv2.waitKey(1000)
# cv2.destroyAllWindows()
