#include <stdio.h>
//01100010 = 0x62
void vnmv_bomb_ignit(unsigned char *, unsigned char *);

int main(void){
    unsigned char BOMB_REGISTER = 0x0;
    unsigned char BOMB_IGNITION = 0x0;

    BOMB_REGISTER = 0x63;
    vnmv_bomb_ignit(&BOMB_REGISTER, &BOMB_IGNITION);
    if((BOMB_IGNITION & 0xFF)==0xFF)printf("Boom.");
    else printf("...");

    BOMB_REGISTER = 0x62;
    vnmv_bomb_ignit(&BOMB_REGISTER, &BOMB_IGNITION);
    if((BOMB_IGNITION & 0xFF)==0xFF)printf("Boom.");
    else printf("...");

    BOMB_REGISTER = 0x2A;
    vnmv_bomb_ignit(&BOMB_REGISTER, &BOMB_IGNITION);
    if((BOMB_IGNITION & 0xFF)==0xFF)printf("Boom.");
    else printf("...");
    return 0;
}
void vnmv_bomb_ignit(unsigned char *BOMBr,unsigned char *BOMBi){
    if((*BOMBr&0x62)==0x62) *BOMBi = 0xFF;
    else *BOMBi = 0x00;
}