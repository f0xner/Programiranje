#include <stdio.h>
#include "lib.h"
#include <string.h>
int x = 120;
int *k;
void f1(int k){
    printf("%d",k);
}
void f2(void){
    int x = 140;
    k=&x;
    f1(*k);
    printf("%d",x);
}
void menjaj(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int *maks(int *a, int *b){
    return *a>*b?a:b;
}
int test(int x){
    return x+10;
}

int main(void){
    // int c = 20;
    // printf("%d %d %d",c++,c--,c++);
    /*
    Območje(Scope)
        Lokalne spremenljivke
            območje funkcije
        Globalne spremenljivke
            območje datoteke
        Območje bloka

    */
	// int x = 123,y = 456;int x = 123,y = 456;
	// printf("%d %d\n",x,y);
	// menjaj(&x,&y);
	// printf("%d %d\n",x,y);
    // *maks(&x,&y) = 330;
    // printf("%d\n",y);
    //poglej str. 83, 87 v ucbeniku
    // kazalec tipa void lahko kaze kamor koli
    //void *kazalec;
    //preden uporabis void kazalec moras uporabit type cast, npr (int *)
    int x = 10;
    void *p;
    p = &x;
    //              | type cast
    //              ˇ 
    printf("%d",*(int *)p);
    int (*foo)(int);//kazalec na funkcijo
    foo = &test;
    printf("%d\n",foo(12));

    return 0;
}
