#include <stdlib.h>
#include <stdio.h>

char TEKST[100] = "";
char *k_TEKST = TEKST;

void vstaviZnak(char znak);
int main(void){
	vstaviZnak('a');
}
void vstaviZnak(char znak){
	printf("%x\n",(unsigned int)&k_TEKST);
	*k_TEKST++;
	printf("%x\n",(unsigned int)&k_TEKST);
}
