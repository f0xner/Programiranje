#include <stdio.h>
#define COLS 4
//sprememba
int toeplitz(int m[][COLS], int rows);
int main(void){
    int m2[][COLS] = 
    {{0, 1, 2, 3},
     {4, 0, 1, 3},
     {5, 4, 0, 1}};
    int rows = 3;
    printf("%d", toeplitz(m2, rows));
    

    int m1[][COLS] = 
    {{0, 1, 2, 3},
     {4, 0, 1, 2},
     {5, 4, 0, 1},
     {3, 5, 4, 0},
     {9, 3, 5, 4}};
    rows = 5;
    printf("%d", toeplitz(m1, rows));
    return 0;
}
int toeplitz(int m[][COLS], int rows){
    for (int i = 1;i<rows;i++){
        for (int j = 1;j<COLS;j++){
            if(m[i][j] != m[i-1][j-1])return 0;
        }
    }
    return 1;
}
