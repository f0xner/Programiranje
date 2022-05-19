import cv2
import numpy as np

img = cv2.imread("tri.jpg")
imgo = img[180:1050,400:2000]
img = cv2.cvtColor(imgo,cv2.COLOR_BGR2GRAY)
img = cv2.Canny(imgo,50,150,apertureSize=3)
minLineLength =20
maxLineGap = 5
lines = cv2.HoughLinesP(img,1,np.pi/180,15,minLineLength=minLineLength,maxLineGap=maxLineGap)
for x in range(0, len(lines)):
    for x1,y1,x2,y2 in lines[x]:
        cv2.line(imgo,(x1,y1),(x2,y2),(0,255,0),2)
cv2.imshow("img",imgo)
cv2.waitKey(5000)