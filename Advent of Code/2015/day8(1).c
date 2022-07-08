#include <stdio.h>
#include <string.h>
int main(void){
    char buffer[200];
    int stringLit = 0;//the number of characters of code for string literals
    int stringMemory = 0;//the number of characters in memory for the values of the strings
    do{
        strcpy(buffer,"\0");
        gets(buffer);
        printf("%s\n",buffer);
        if(buffer){
            for (int i = 0;buffer[i];i++){
                //printf("%c %d\n",buffer[i],i);
                if(buffer[i] == 34)stringMemory+=1;
                else if(buffer[i] == 92){
                    if(buffer[i+1] == 34 || buffer[i+1] == 110 || buffer[i+1] == 116 || buffer[i+1] == 97 || buffer[i+1] == 98 || buffer[i+1] == 101 || buffer[i+1] == 102 || buffer[i+1] == 114 || buffer[i+1] == 118 || buffer[i+1] == 92 || buffer[i+1] == 39 || buffer[i+1] == 63){
                        stringLit+=1;
                        stringMemory+=1;
                    }
                    if(buffer[i+1] == 120){
                        stringLit+=1;
                        stringMemory+=4;
                        i+=3;
                    }
                }else{
                    stringLit+=1;
                    stringMemory+=1;
                }
            }
            //printf("stringLit: %d\nstringMemory: %d\n",stringLit,stringMemory);
        }
    }while(strlen(buffer));
    printf("%d\n",stringMemory-stringLit);
    return 0;
}