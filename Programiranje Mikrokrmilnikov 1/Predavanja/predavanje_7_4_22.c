#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //char t[10] = "test";
    //strcpy(&t[4],"OK");
    //char *t = "test";//kazalec na tabelo
    // printf("%d", t == "test");
    // printf(t);
    // int m[][3] = {{1,2,3},{11,12,13}};
    // printf("%d",sestej(m,2));
    // str 128
    int *k;
    int n;
    scanf("%d",&n);
    k = malloc(n * sizeof (int));//k kaže na en blok polnilnika ki lahko shrani n podatkov po 4 byte -> sizeof(int) = 4
    if (k == NULL){
        printf("NAPAKA");
        return 0;
    }
    for (int i = 0;i<n;i++){
        scanf("%d",&k[i]);
    }
    for (int i = 0;i<n;i++){
        printf("%d ",k[i]);
    }
    free(k);
}

int kajJeTo(char *niz){
    return strlen(niz) == 0  || (niz[0] < '0' || niz[0]>'9') && kajJeTo(&niz[1]);
}