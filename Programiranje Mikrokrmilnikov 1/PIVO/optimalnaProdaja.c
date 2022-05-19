#include <stdio.h>

int optimalnaProdaja(float *, unsigned int, unsigned int);

int main(void){
    float c[]={10.1, 11.2, 12.4, 15.6, 14.0, 12.1, 14.2, 16.3, 17.4, 16.1, 16.9, 14.1, 10.0, 8.0, 7.0};
    printf("%d\n", optimalnaProdaja(c, sizeof(c)/sizeof(float), 15));
    printf("%d\n", optimalnaProdaja(c, sizeof(c)/sizeof(float), 1));
    return 0;
}
int optimalnaProdaja(float *tab, unsigned int lenTab, unsigned int index){
    if(index >= lenTab-1 || index < 0) return -1;
    float maxdobicek = 0,maxizguba = -tab[index], trenutniDobicek = 0;
    int maxI = -1;
    int minI = -1;
    for (int i = index+1;i<lenTab;i++){
        trenutniDobicek = tab[i]-tab[index];
        if(tab[i]>tab[index]){
            if(trenutniDobicek>maxdobicek){
                maxdobicek = trenutniDobicek;
                maxI = i;
            }
        }else{
            if(trenutniDobicek>maxizguba){
                maxizguba = trenutniDobicek;
                minI = i;
            }
        }
    }
    return maxI != -1 ? maxI : minI;
}