#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 29.5.2022 vse vaje
int main(void){
    int a;
    float b;
    scanf("%d",&a);
    a = a*a;
    b = sqrt(a);
    printf("%d %.2f\n",a,b);
    return 0;
}