#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void dvojiskiKomplement(char* vnos);
void trikotnik(int n);
void pisi(int x, int y);
int main(){
    // int x = 5,y = 2;
    // scanf("%d",&x);
    // printf("%d | %d\n",-7/6,y);
    trikotnik(6);
    return 0;
}
void pisi(int x, int y) {
    
    for (int i = x; i <= y; i++) {
        printf("%d ",i);
    }
    
}
void trikotnik(int n){
    for (int i = 0; i <= n; i++) {
        int ex = 0;
        printf("%*s",i*2+(i>10?1:0),"");//10<x<100 -> 1, 100<x<100-> 2 
        pisi(i, n);
        printf("\n");
    }

}
void dvojiskiKomplement(char* vnos){
    char negativ[strlen(vnos)];
    char c;
    printf("%s\n",vnos);
    for(int i = 0;i<strlen(vnos);i++){
        c = abs((vnos[i]-'0')-1)+'0';
        // printf("%d",i);
        negativ[i] = c;
    }
    printf("%s\n",negativ);
    int naprej = 1;

    for(int i = strlen(vnos)-1;i>=0;i--){
        int sestevek = (negativ[i]-'0')+naprej;
        if(sestevek == 2){
            naprej = 1;
            negativ[i] = '0';
        }else{
            naprej = 0;
            negativ[i] = '1';
        }
        
    }
    printf("%s\n",vnos);


}