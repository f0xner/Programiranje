#include <stdio.h>

char * razlomiNiz(char niz[], char locilo, char locilo2, char locilo3){
    static char * k_znak; // Kazalec na nek znak.
    if(niz != NULL) k_znak = niz; // Usmerimo ga na začetek niza.
    
    char *k_start; // Kazalec na začetek niza 
    k_start = k_znak;
    
    if(*k_znak == 0){return NULL;} // če smo na koncu... 
    
    while(*k_znak != locilo && *k_znak != locilo2 && *k_znak != locilo3){
        if(*k_znak == 0){
            break;
        }
        k_znak++; // kaži na naslednji pod. blok
    }
    *k_znak = 0; // Zamenjaj ločilo z varuhom
    k_znak++; // Prestavi se za en korak naprej, da ne gledaš varuha, ki si ga ravno postavil
    
    return k_start; // Vrni začetek niza
}


int main(){
    char seznam[] = "4*10*2-2+1";
    char *k;
    
    k = razlomiNiz(seznam, '*','+','-');
    while(k){
        printf("%s\n", k);
        k = razlomiNiz(NULL, '*','+','-');
    }
    
	return 0;
}

