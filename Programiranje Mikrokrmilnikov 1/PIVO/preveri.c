#include <stdio.h>
#define LEN 4

int preveri(int code[][LEN], int n);
int main(void){

    int c2[][LEN] = {{0, 1, 0, 1}, {1, 1, 1, 0}, {1, 0, 1, 0}, {1, 0, 1, 1}};
    int num = 4;
    printf("%d", preveri(c2, num));

    int c1[][LEN] = {{0, 0, 0, 1}, {1, 1, 1, 1}, {1, 1, 1, 0}, {0, 1, 0, 1}, {0, 1, 0, 0}, {0, 0, 0, 1}};
    num = 6;
    printf("%d", preveri(c1, num));
    return 0;
}
int preveri(int code[][LEN], int n){
    for (int i = 0;i<LEN;i++){
        int stolpSum = 0;
        for (int j = 0;j<n;j++){
            stolpSum += code[j][i];
        }
        if(stolpSum%2!=0) return 0;
    }
    return 1;
}
