#include <stdio.h>
#define N 5
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

int prim(const void *a, const void *b){
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    return (a1>b1)-(a1<b1);
}

int main(void){
    int t[N] = {3,-5,2000000000,48,-1000000000};
    // printf("%d %d %d\n",t[2],t[4],t[2]-t[4]);
    qsort(t, N, sizeof(int),prim);
    for (int i = 0;i<5;i++){
        printf("%d ",t[i]);
    }
    return 0;
}