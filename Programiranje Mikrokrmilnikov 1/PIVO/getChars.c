#include <stdio.h>
#include <string.h>

int getChars(char *str);
int vrstniRed(char *znaki);
int main(void){
    char niz[100];
    strcpy(niz, "");
    printf("%d%s\n", getChars(niz), niz);
     	
    strcpy(niz, "Blah blah blah!");
    printf("%d%s\n", getChars(niz), niz);

    return 0;
}
int vrstniRed(char *znaki){
    int len = strlen(znaki);
    for (int i = 0;i<len-1;i++){
        if(!(znaki[i]<znaki[i+1]))return 0;
    }
    return 1;
}
int getChars(char *str){
    
    if (str[0] == '\0') return 0;
    
    int len = strlen(str);
    char znaki[len];
    strcpy(znaki,"");
    int znakov = 0;
    
    for (int i = 0;i<len;i++){
        int najden = 0;
        for(int j = 0;j<znaki[j];j++){
            if(str[i]==znaki[j]){ 
                najden = 1;
                break;
            }
        }
        char c[2] = "\0";
        c[0] = str[i];
        if(!najden) {
            strcat(znaki,c);
            znakov++;
        }

    }
    len = strlen(znaki);
    while(!vrstniRed(znaki)){
        for(int i = 0;i<len-1;i++){
            if(znaki[i]>znaki[i+1]){
                char tmp = znaki[i];
                znaki[i] = znaki[i+1];
                znaki[i+1] = tmp;
            }
        }
    }
    strcpy(str,znaki);
    return znakov;
}