#include <stdlib.h>
#include <stdio.h>
int varnoDeljenje(int a,int b, float *rez){
    if(b==0)return 0;
    else{
        *rez = (float)a/b;
        return 1;
    }
}
int main(void){
    //Kazalci("Pointers")
    // double x = 50.0;//V pomnilniku zasede nasplove npr. 1000-1008
    // double *k;
    // k =&x;//Kaže na naslov 1000
    // *k = 60.0;//v x se vpiše vrednost 60.0. x = 60 je enako vreden izraz x je zamenljiv z *k
    
    //Naloga 5.7
    int x,y;
    float rez;
    // printf("X/Y: ");
    scanf("%d/%d",&x,&y);
    // rez = (float)x/y;
    // printf("Rez = %f\n",rez);

    if(varnoDeljenje(x,y,&rez)){
        printf("%d/%d = %f\n",x,y,rez);
    }else{
        printf("Deljenje z 0.\n");
    }

    return 0;
}