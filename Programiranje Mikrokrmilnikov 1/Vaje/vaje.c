#include <stdlib.h>
#include <stdio.h>
//za predvajanje audio datotek iz terminala poberes apt sox -> play command
int main(void){
    int x;
    while(1==2){
        printf("Vpiši številko(20-99)");
        scanf("%d",&x);
        int enice = x%10;
        int desetice = x/10;
        switch(enice){
            case 1:printf("enain");break;
            case 2:printf("dvain");break;
            case 3:printf("triin");break;
            case 4:printf("štiriin");break;
            case 5:printf("petin");break;
            case 6:printf("šestin");break;
            case 7:printf("sedemin");break;
            case 8:printf("osemin");break;
            case 9:printf("devetin");break;
        }
        switch(desetice){
            case 2:printf("dva");break;
            case 3:printf("tri");break;
            case 4:printf("štiri");break;
            case 5:printf("pet");break;
            case 6:printf("šest");break;
            case 7:printf("sedem");break;
            case 8:printf("osem");break;
            case 9:printf("devet");break;
        }
        if (desetice >= 3){
            printf("deset");
        }
        else if (desetice == 2){
            printf("jset");
        }else if(desetice == 0){
            break;
        }
        printf("\n");
    }
    
}