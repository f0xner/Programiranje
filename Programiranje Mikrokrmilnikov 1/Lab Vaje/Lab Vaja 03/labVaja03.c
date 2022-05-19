#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bitmap.h"
#include "bitmap.c"
#define DIM 500
#define JulijaSet 2*3
#define skrajnaVrednost 1.7
#define razmik 2*(skrajnaVrednost/(DIM))
struct kompleks{
	float re,im;
};
unsigned char dolociBarvo(struct kompleks z, struct kompleks c,int barvniParam);
struct kompleks vsota(struct kompleks x, struct kompleks y);
struct kompleks produkt(struct kompleks x, struct kompleks y);
float absKompleks(struct kompleks z);
int map(float num);
unsigned char dolociBarvo(struct kompleks z, struct kompleks c,int barvniParam){
	unsigned char barva;
	struct kompleks p;
	float r;
	for (barva = 0;barva<=255;barva++){
		p = produkt(z,z);
		z = vsota(p,c);
		r = absKompleks(z);
		if (r>2){
			return barvniParam-barva;
		}
	}
	return barvniParam-barva; 
}
struct kompleks produkt(struct kompleks x, struct kompleks y){
	struct kompleks z;
	z.re = x.re * y.re - x.im * y.im;
	z.im = x.re * y.im + y.re * x.im;
	return z;
}
struct kompleks vsota(struct kompleks x, struct kompleks y){
	struct kompleks z;
	z.re = x.re+y.re;
	z.im = x.im+y.im;
	return z;
}
float absKompleks(struct kompleks z){
	return sqrt(z.re*z.re + z.im*z.im);
}
int map(float num){
	return (int)(num/2.0*255.0);
}
int main(void){
	unsigned char slika[DIM][DIM];
	float julijaSets[28] = {0.0,1.0,-0.55,0.5,-1.35,0.0,0.31,0.50,0.285,0.0,0.285,0.01,0.45,0.1428,-0.70176,-0.3842,-0.835,-0.2321,-0.8,0.156,-0.7269,0.1889,0.0,-0.8,-0.4,0.6,-0.618,0.0};
	struct kompleks z,c;
	z.re = -skrajnaVrednost;
	z.im = skrajnaVrednost;
	int a = -1;
	scanf("%d",&a);
	if (a != -1){
		c.re = julijaSets[a];
		c.im = julijaSets[a+1];
	}else{
		c.re = julijaSets[JulijaSet];
		c.im = julijaSets[JulijaSet+1];
	}
	
	time_t t;
	srand((unsigned)time(&t));
	int RBarva = rand() % 255;;
	printf("RBarva: %d\n",RBarva);
	for(int i = 0;i<DIM;i++){
		for (int j = 0;j<DIM;j++){
			slika[i][j]=dolociBarvo(z,c,RBarva);
			z.re += razmik;
		}
		z.im -= razmik;
		z.re = -skrajnaVrednost;
	}
	shraniBMP(slika,DIM,DIM,"Fraktali/fraktal.bmp");
	return 0;
}
