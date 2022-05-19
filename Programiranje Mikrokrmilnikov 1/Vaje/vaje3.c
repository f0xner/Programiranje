#include <stdio.h>
#include <math.h>
void koren(int x);

int main(void){
    //double sonce = 1.989e30;//masa v kg
    //double luna = 7.348e22;//masa v kg

    //printf("Sonce:         %40.1lf\n",sonce);
    //printf("Luna:          %40.1lf\n",luna);
    //printf("Sonce + Luna:  %40.1lf\n",(sonce + luna));

    //Program ki izračuna kvadratni koren pozitivnega števila, po newtonovi metodi
    koren(8);

    return 0;
}
void koren(int x){
    double y = 1, avg = 0;
    printf("y\t\tx/y\t\tavg\n");
    avg = (x/y+y)/2;
    printf("%lf\t%lf\t%lf\n",y,x/y,avg);
    y=avg;
    while(1){
        avg = (x/y+y)/2;
        printf("%lf\t%lf\t%lf\n",y,x/y,avg);
        if(fabs(avg-y)<0.000001*y)break;
        y=avg;
    }
}