#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void deljivost(long stevilo);
int main(void){
    //4.2 v učbeniku
    //8-bitni
    char x;//-128...127
    unsigned char y;//0...255

    //16-bitni
    char a;//-32768...32767
    unsigned char b;//0...65535 => 2^16=65535

    //printf("%lu\n",sizeof(a));
    deljivost(912634632466662);
    return 0;
}
void deljivost(long stevilo){
    //Previ deljivosti
    char st[100];
    bool sDVA,zTRI;
    sprintf(st,"%ld",stevilo);
    //Deljivost z 2
    if((st[strlen(st)-1]-'0')%2==0){
        printf("%ld je deljivo z 2,\n",stevilo);
        sDVA = true;
    }
    //Deljivost s 3
    int vsotaTRI = 0;
    for(int i = 0;i<strlen(st);i++){
        vsotaTRI += (st[i]-'0');
    }
    if(vsotaTRI%3==0){
        printf("%ld je deljivo s 3,\n",stevilo);
        zTRI = true;
    }
    //Deljivost s 4
    if(stevilo>99){
        if((stevilo%100)%4==0){
            printf("%ld je deljivo s 4,\n",stevilo);
        }
    }else{
        if(stevilo%4==0){
            printf("%ld je deljivo s 4,\n",stevilo);
        }
    }
    //Deljicost s 5
    if(st[strlen(st)-1]=='0' || st[strlen(st)-1]=='5'){
        printf("%ld je deljivo s 5,\n",stevilo);
    }
    //Deljivost s 6
    if(zTRI==true&&sDVA==true){
        printf("%ld je deljivo s 6,\n",stevilo);
    }
    //Deljivost s 8
    if (stevilo>999){
        if((stevilo%1000)%8==0){
            printf("%ld je deljivo s 8,\n",stevilo);
        }
    }else{
        if(stevilo%8==0){
            printf("%ld je deljivo s 8,\n",stevilo);
        }
    }
    //Delijost s 9
    if(vsotaTRI%9==0){
        printf("%ld je deljivo s 9,\n",stevilo);
    }
    //Delijost s 10
    if(st[strlen(st)-1]=='0'){
        printf("%ld je deljivo s 10,\n",stevilo);
    }
}