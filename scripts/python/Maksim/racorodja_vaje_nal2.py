import numpy as np 
import matplotlib.pyplot as plt
def korak(s,p):
    n = len(s)
    sn = s
    for i in range(0,n):
        c = 16*s[(i+n-2)%n]+8*s[(i+n-1)%n]+4*s[i]+2*s[(i+1)%n]+s[(i+2)%n]
        try:
            sn[i] = p[i]
        except:
            print(i)
    return sn

def pasca():
    pass
s = np.zeros(256)
korakov = 128
s[128] = 1
p1 = [0,0,0,0,0,0,1,1,1,1,0,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,1,0,0,1,1,1]
p = np.zeros(256)
for i in range(0,256):
    if(i >=224):
        p[i] = p1[i-224]
p = p[::-1]
matrika_c_s = np.zeros((128,256))
for i in range(0,korakov):
    matrika_c_s[i] = s
    s = korak(s,p)
plt.matshow(matrika_c_s)