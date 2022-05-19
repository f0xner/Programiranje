#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void){
    printf("number | power | \%% | bin\n");
    for (int i = 0;i<24;i++){
        double num = pow(2,i)+1;
        //int dv = (int)(((int)num)/9);
        int ostanek = (int)fmod(num,9);
        //printf("%.0f | ",num);
        printf("%d | ",i);
        printf("%d | \n",ostanek);
        //printf("%d |  ",dv);
        //tobinary(ostanek);
    }

    return 0;
}
/*  
    potenca = ostanke
        0   =   2
        1   =   3
        2   =   5
        3   =   0
        4   =   8
        5   =   6
            .
            .
            .
    se periodično ponavlja, torej če deljenje z ostankom potence z 6 delimo z (1/6), dobimo vrednost med 0 in 5, ta vrednost pa nam pove koliko bo ostanek glede na pozicijo v periodi
    2022 % 6 = 0 / (1/6) = 0 => vrendost izraza (2^2022+1)%9 = 2
*/
void tobinary(int n){
    while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
    }
    printf("\n");
}