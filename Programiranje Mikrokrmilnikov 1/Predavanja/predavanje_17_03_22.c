#include <stdio.h>
#include <ctype.h>

//prototip, deklaracija 
double absolutno(double x);//glava funkcije brez telesa


//funkcija za telesom
double absolutno(double x){
    return x >= 0 ? x : -x;
}

int main(void){
    //Pretvorbe tipov -> Promotion / Napredovanje
    float x,*k=NULL;
    
    k=&x;
    if(k != NULL){
        *k = absolutno(-3.2e-3);//* operator posredovanja / indirekcije. 
                  //Operacijo izvajam na nad spremenljivko na katero k kaže
                  // x se priredi vrednost 3.14
        printf("%f",*k);//Naslovni operator = &
    }
    





        //unsigned short y = 1000000.0;
        //printf("%hu\n",y);//Ostanek pri evklidovem deljenju -> modulo -> % -> ostanek pri deljenju
        // char znak;
        // int velik = 0;
        // while(1){
        //     scanf("%c",&znak);
        //     if(znak == '\n'){
        //         break;
        //     }
        //     if(znak == '.'){
        //         velik=1;
        //     }else if (!isspace(znak) && velik == 1){//isalpha() preveri ali je znak črka
        //         velik = 0;
        //         znak = toupper(znak);
        //     }
        //     printf("%c",znak);
        // }
        // printf("\n");
    return 0;
}