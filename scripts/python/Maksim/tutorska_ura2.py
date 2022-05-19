import numpy as np
import matplotlib as plt 


def korak(s):
    novo = np.zeros(len(s))
    for i in range(1, len(s)-1):
        novo[i] = s[i-1] + s[i+1]
    return novo


# l je vodoravna dolžina trikotnika
def pascal(N, l):
    if N == 0:
        prva_vrsta = np.zeros(l)
        prva_vrsta[int((l+1)/2)] = 1
        return prva_vrsta
    staro = pascal(int(N-1), l)  
    novo = korak(staro[-1])
    novo = np.reshape(novo, (1, l))
    return np.concatenate((staro, novo))
    
print(pascal(5,10))

