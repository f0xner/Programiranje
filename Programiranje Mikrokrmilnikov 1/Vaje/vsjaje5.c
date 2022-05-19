#include <stdio.h>
#include <stdbool.h>

int main(void){
    //Bitne operacijes
    /* Šestnajstiške vrednosti

    0000 = 0
    0001 = 1
    0010 = 2
    0011 = 3
    0100 = 4
    0101 = 5
    0110 = 6
    0111 = 7
    1000 = 8
    1001 = 9
    1010 = 10 = A
    1011 = 11 = B
    1100 = 12 = C
    1101 = 13 = D
    1110 = 14 = E
    1111 = 15 = F

    */
    //POMIKANJE BITOV
        // x << 3 pomik v levo za tri mesta
        // 0001 << 3 = 1000
        // x << = 3 je ekvivalent izrazu x = x << 3

        // x >> 2 pomik v desno za 2 mesta
        // 1000 >> 2 = 0010
    
    //ENŠKI KOMPLEMENT
        //x = ~x; negiranje bitov, to NI enako x != x;
        // 1110 = ~0001;

    //POSTAVLJANJE BITOV
        //Pri postavljanju bitov se uporabja "MASKA"

        //b7 MSB .... b0 LSB
        //Brisanje bita = nastaljanje bita na 0 RD-XIX-1
        //SET
            // x|1 = 1
            // x|0 = x
        //CLEAR
            // x&1 = x
            // x&0 = 0
        //SPREMEMBA BITA
            // x = x^m, kjer je m maska, kjer se pove katere bite hoces spremenit

    //BRANJE BITA
        //b1 = x&m; b1 je vrednost bita, ki ga hocemo prebrat. m je bit ki ga hocemo prebrat.
    
    //BITNO POLJE  JE ČE OPRAIRAŠ Z VEČ BITI NAENKRAT


    unsigned char x = 0x1;

    
    return 0;
}