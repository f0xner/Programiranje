
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga1.c
./a.out

Samodejno testiranje:

export name=naloga1
make test

Testni primeri:

test01: primer iz besedila
test02..test08: ro"cno izdelani kratki testi
test09..test11: samodejno izdelani, tip Exxx_Exxx_Exxx_...
test12..test14: samodejno izdelani, vsakemu E-ju sledi "stevilo iz [100, 999]
test15..test17: samodejno izdelani, splo"sni

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================
int Pow(int n){
    if (n == 0)return 1;
    int vr = 1;
    for (int i = 0;i<n;i++){
        vr *= 10;
    }
    return vr;
}
int sestEj(char* niz) {
    int vsota = 0;
    for (int i = 0;i<strlen(niz);i++){
        if(niz[i] == 'E' && niz[i+4] == '_'){
            int stevka = 0;
            for(int j = i+1,k=0;j<i+4;j++,k++){
                if((niz[j]-'0')>=0 && (niz[j]-'0')<=9){
                    stevka +=(int)(niz[j]-'0')*Pow(2-k);
                }else{
                    stevka = 0;
                    break;
                }
            }
            if(stevka>=100 && stevka <=999)vsota+=stevka;       
        }
    }
    return vsota;   // popravite
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main(int argc, char *argv[]) {
    // Tole dopolnite, "ce "zelite funkcijo testirati s svojimi lastnimi nizi.
    if (argc == 2){
        sestEj(argv[1]);
    }
    return 0;
}

#endif
