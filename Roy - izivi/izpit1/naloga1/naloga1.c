
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
#include <math.h>

#include "naloga1.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int sestEj(char* niz) {
    int E = 0;
    int stevk = 0;
    char stevilo=0;
    int vsota = 0;  
    for (int i = 0;i<strlen(niz);i++){
        if((niz[i] == '_' && E == 1 )){
            printf("\n_");
            E = 0;
            if(stevk == 3){vsota += stevilo;
            printf("%d v=%d\n",stevilo,vsota);}
            stevilo = 0;
        }
        if(stevk >= 3){
            E=0;
            stevilo = 0;
            stevk = 0;
        }
        if(E && stevk < 3){
            if((niz[i]-'0')>=0 && (niz[i]-'0')<=9){
                printf("%d | ",(niz[i]-'0'));
                stevilo += (int)pow(10,(2-stevk))*((niz[i]-'0') == 0 ? 1: (niz[i]-'0'));
                stevk++;
            }else{
                E = 0;
                stevilo = 0;
                stevk = 0;
            }
            
        }
        if(niz[i] == 'E')E = 1;
    }
    printf("%d",vsota);
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
