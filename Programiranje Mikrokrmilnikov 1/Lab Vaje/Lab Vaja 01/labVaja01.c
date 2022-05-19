#include <stdio.h>
#include <stdlib.h>
int izracun(){
	static float rez[2];
	float a,b;//(a+bi)
	float c,d;//(c+di)
	
	printf("Prvo kompleksno število(a+bi): ");
	scanf("%f%fi",&a,&b);
	while(getchar()!='\n');

	printf("Drugo kompleksno številob(a+bi): ");
	scanf("%f%fi",&c,&d);
	while(getchar()!='\n');

	rez[0] = a+c;
	rez[1] = b+d;
	printf("Vsota: %.1f%+.1fi\n",rez[0],rez[1]);

	rez[0] = a-c;
	rez[1] = b-d;
	printf("Razlika: %.1f%+.1fi\n",rez[0],rez[1]);

	rez[0] = a * c - b * d;
	rez[1] = a * d + c * b;
	printf("Produkt: %.1f%+.1fi\n",rez[0],rez[1]);

	rez[0] = (a * c + b * d) / (c * c + d * d);
	rez[1] = (b * c - a * d) / (c * c + d * d);
	printf("Kvocient: %.1f%+.1fi\n",rez[0],rez[1]);

	return 0;
}
int main(){
	int rez;
	rez = izracun();
	return 0;
}

