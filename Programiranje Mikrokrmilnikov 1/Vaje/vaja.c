#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *kopiraj(char *izvor){
char *pom;
int i;
for (i = 0; izvor[i]; i++) {}
pom = malloc(i + 1);

for (i = 0; izvor[i]; i++) {
  pom[i] = izvor[i];
}
pom[i] = 0;
return pom;
}

int main(void){
    //char *k;
    //k = kopiraj("Testiram...");
    //printf(k);

     return 0;
}