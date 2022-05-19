#include <stdio.h>
#define xrpInitialBalance 860.582434
#define yearlyRate 0.0525
#define monthlyRate yearlyRate/12.0

int main(void){
    int nMonths;
    float xrp_price;
    printf("N months: ");
    scanf("%d",&nMonths);
    printf("XRP price: ");
    scanf("%f",&xrp_price);
    float prevMGain = 0;
    float newBalance = xrpInitialBalance;
    for (int i = 0;i<nMonths;i++){
        prevMGain = newBalance*monthlyRate;
        newBalance+=prevMGain;
    }
    printf("New balance after %d months: %.3f\n",nMonths,newBalance);
    printf("XRP value: %.2f\n",newBalance*xrp_price);
    return 0;
}
