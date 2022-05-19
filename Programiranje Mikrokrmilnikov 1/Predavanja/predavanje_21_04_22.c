
#include <stdio.h>
#include <ctype.h>

//(2^2022 + 1) % 9 = ?


typedef unsigned char BYTE;

#define ST 8 //izpis po stolpcih, ta številka najbi bila mnogokratnik št. 2
int main(void){
    //unsigned short y = 0xF6AC;
    //splošna maska: 1 << n (n = katri bi želiš testirat/negirat/postavit/brisat)
    //unsigned short MASKA = 0x0010;

    //Tilda ~ naredi dvojiški komplment, a ne prišteje 1, torej samo zamenja 1 in 0, torej eniški komplement
    //Tilda ~ NI enako kot logična negacija !
    //Bitna in operacija (ang. AND)= |
    //Bitna ali operacija (ang. OR)= &
    //Bitna izključno ali operacija (ang. XOR)= ^
    //Bitno premikanje v levo << n, v desno >>, za n mest (0 <= n < bitna dolžina)
    /*
        "set" operacija
            x | 0 = x
            x | 1 = 1
        "clear" operacija
            x & 0 = 0
            x & 1 = x
        negacija določenega bita
            x ^ 0 = 0
            x ^ 1 = ~x

        y = y | MASKA;
        printf("%X",y);
    */
    //Pri pomikanju bitov v desno, je v desetiški obliki to deljenje z osnovo, n premiki v desno = deljenje n*2
    
    //Izpis pomnilnika (Memory dump) byte po bytu se izpiše
    unsigned int naslov;
    char t[] = "To so podatki."; //tega se ne da spreminjat
    char *ptr = "To je konstanten niz.";//Tega se da spreminjat
    short x = -128;
    BYTE *k;
    printf("Naslov x-a je na %X\n",&x);
    printf("Naslov konst niza je na %X\n", ptr);
    printf("Vpisi naslov: ");
    scanf("%x",&naslov);
    k = (BYTE *)naslov;
    for (int i = 0;i<10;i++){
        printf("%X  ",k);
        for (int j = 0;j<ST;j++){
            printf("%02X  ",k[j]);//0 je zato da nam zafila vodila mesta če so 0, 2 je zato da izpisujemo na 2 mesti
        }
        for (int j = 0;j<ST;j++){
            if(isprint(k[j])){
                printf("%c",k[j]);
            }else{
                printf(".");
            }
        }

        printf("\n");
        k += ST;
    }
    printf("nevem");
    return 0;
}