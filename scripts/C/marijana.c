#include <stdlib.h>
#include <stdio.h>
#define GRWG 10.30
#define VFF 5.93
#define HYFM 16.79
#define treshold 5.1
int main(void){
    double vsote[] = {0,0,0};
    double vsota = 0;
    for(int i = 1;i<500;i++){
        vsote[0] = (i/100.0)*GRWG;
        for(int j = 1;j<500;j++){
            vsote[1] = (j/100.0)*VFF;
            for(int k = 1;k<500;k++){
                vsote[2] = (k/100.0)*HYFM;
                vsota = vsote[0]+vsote[1]+vsote[2];
                if(abs(vsote[0]-vsote[1])<treshold && abs(vsote[0]-vsote[2])<treshold && abs(vsote[1]-vsote[2])<treshold && (vsota <=100 && vsota>98)){
                    printf("GRWG: %.2f %.2f\nVFF: %.2f %.2f\nHYFM: %.2f %.2f\nVsota: %.2f\n",vsote[0],(i/100.0),vsote[1],(j/100.0),vsote[2],(k/100.0),vsota);
                    return 0;
                }
            }
        }
    }
    printf("Ni resitve\n");
    return 1;
}