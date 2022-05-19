#include <stdio.h>
#define INIT_VECTOR 0x0
//bitna polja 
    //B07 B06 senzor 1
    //B05 B04 senzor 2
    //B03 B02 senzor 3
//Stanja nagiba
    //0x0 ni nagiba
    //0x1 znaten nagib
    //0x2 resen nagib
    //0x3 kritičen nagib
//               SENSOR_1   SENSOR_2   SENSOR_3     
//                      \        \        \       
//                       |        |        |       
//                     |------||------||------| 
//                     B07 B06 B05 B04 B03 B02 B01 B00
// TILT_SENSOR_REG:    | x | x | x | x | x | x | x | x |
//                                             |-------|
//                                                 |
//                                                  \ VERT_CORR
void boneig_7E7_please_fly(unsigned char *);
int main(void){
	unsigned char TILT_SENSOR_REG = INIT_VECTOR;

	TILT_SENSOR_REG = 0xE2;
	boneig_7E7_please_fly(&TILT_SENSOR_REG);
	printf("%X\n", TILT_SENSOR_REG);
	
	TILT_SENSOR_REG = 0xC2;
	boneig_7E7_please_fly(&TILT_SENSOR_REG);
	printf("%X\n", TILT_SENSOR_REG);
	
	TILT_SENSOR_REG = 0xA4;		
	boneig_7E7_please_fly(&TILT_SENSOR_REG);
	printf("%X\n", TILT_SENSOR_REG);

	TILT_SENSOR_REG = 0x54;		
	boneig_7E7_please_fly(&TILT_SENSOR_REG);
	printf("%X\n", TILT_SENSOR_REG);
    return 0;
}
void boneig_7E7_please_fly(unsigned char * tilt_register){
    unsigned char sens1, sens2, sens3,vert_corr;

	vert_corr = *tilt_register & 0x3;
	sens3 = (*tilt_register >> 2) & 0x3;
	sens2 = (*tilt_register & 0x30) >> 4;
	sens1 = (((*tilt_register & 0xC0) >> 2) | 0x3) >> 4;


	if(sens1 == sens2 || sens2 == sens3 || sens1 == sens3){
		if(sens1 == sens2 && sens1>0x1){
			*tilt_register &= 0xFC;
			*tilt_register += -(0x1-sens1);
		}else if (sens2 == sens3 && sens2 >0x1){
			*tilt_register &= 0xFC;
			*tilt_register += -(0x1-sens2);
		}
		else if (sens1 == sens3 && sens3 >0x1){
			*tilt_register &= 0xFC;
			*tilt_register += -(0x1-sens3);
		}else *tilt_register &= 0xFC;
	}else *tilt_register &= ~0x3;
}