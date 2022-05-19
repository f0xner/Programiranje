#include <stdio.h>
#include <string.h>

int UTF8Codes(char *str, char *codes);

int main(int argc, char *argv[]){
	char niz[200], cds[500];
	//strcpy(niz, "Hello world = 你好世界");
	//printf("%d:%s", UTF8Codes(niz, cds), cds);
	strcpy(niz, "€¥$£ rules");
	printf("%d:%s", UTF8Codes(niz, cds), cds);
}
int UTF8Codes(char *str, char *codes){
	int stevec = 0;
	for (int i= 0; str[i];){
			char buff[12];
			strcpy(buff,"");
			strcat(buff,"0x");
			int bajtov = 0;
			if(str[i]&(0x80)){
				for (bajtov;str[i]&(0x80>>bajtov);bajtov++){
					char bajt[4];
					sprintf(bajt,"%X",256+(str[i+bajtov]));
					strcat(buff,bajt);
				}
				i+=bajtov;
			}else{
				char bajt[4];
				sprintf(bajt, "%X",str[i]);
				strcat(buff,bajt);
				i++;
			}
			strcat(buff, " ");
			strcat(codes,buff);
			stevec++;
	}
	return stevec;
}
