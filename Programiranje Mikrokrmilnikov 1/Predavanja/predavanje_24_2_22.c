#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846
int main(void){
    for (float i = 0;i<=90;i+=15){
        float kot = i*M_PI/180.0;
        float x = sin(kot);
        if (x == 0.5){
            printf("Polovica\n");
        }
        // float y = cos(3.1415/3.0);
        printf("%.4f %.4f\n", x,i);
    }
    // program ki izpiše pravilnostno tabelo (truth table)
    // x | y | x&y | !x | !y | x||y |
    // -----------------------
    // 1 | 0 |  0  | 0  | 1  | ...
    // 0 | 1 |  0  | 1  | 0  | ...
    // 0 | 0 |  0  | 1  | 1  | ...
    // 1 | 1 |  1  | 0  | 0  | ...

    //kratko stično računanje
    //(x!=0)&&(y%x==0)
    // če bo x 0 ne rabiš računati naprej/drugega izraza, bo vse skupaj 0

    //exprassion statement
    //izraz;

    int in;
    scanf("%d",&in);
    float kot = in*M_PI/180.0;
    printf("Kot %d v radianih je %.3f\n",in,kot);
    return 0;
}