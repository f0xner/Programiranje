#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt
vrstice = np.loadtxt("mat.dat")
xOs = np.arange(0,len(vrstice))
tx = np.linspace(0,128,128)
ty = np.linspace(0,255,128)
def prviGraf():
    global vrstice,xOs
    sestevek0 = np.zeros(len(vrstice))
    sestevek1 = np.zeros(len(vrstice))
    for i in range(0,len(vrstice)):
     for j in range(1,len(vrstice[i])):
        if vrstice[i][j] == 0:
            sestevek0[i] +=1
        else:
            sestevek1[i] +=1
    # print(sestevek0)
    # print(sestevek1)
    plt.plot(xOs,sestevek0,color="blue")
    plt.plot(xOs,sestevek1,color="green")
    plt.plot(tx,ty,color="black")
    plt.xlabel("Koraki")
    plt.ylabel("Menjavanje 0 in 1")
    plt.show() 
def drugiGraf():
    global vrstice,xOs
    najdaljsi0 = np.zeros(len(vrstice))
    najdaljsi1 = np.zeros(len(vrstice))
    for i in range(0,len(vrstice)):
        prev = vrstice[i][0]
        najNiz = 0
        trenutniNiz = 0
        for j in range(1,len(vrstice[i])):
            if prev == vrstice[i][j]:
                trenutniNiz+=1
            else:
                if(trenutniNiz>najNiz):
                    najNiz = (trenutniNiz+1)
                trenutniNiz = 0
                prev = vrstice[i][j]
        if prev == 0:
            najdaljsi0[i] = najNiz
        else:
            najdaljsi1[i] = najNiz
    # print(najdaljsi0)
    # print(najdaljsi1)
    plt.scatter(xOs,najdaljsi0,color="blue")
    plt.scatter(xOs,najdaljsi1,color="green")
    plt.xlabel("Koraki")
    plt.ylabel("Najdaljsi niz")
    plt.show()

prviGraf()
drugiGraf()