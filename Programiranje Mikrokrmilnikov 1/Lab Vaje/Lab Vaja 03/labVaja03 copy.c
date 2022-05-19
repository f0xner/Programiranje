#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bitmap.h"
#include "bitmap.c"
#define DIM 500
#define skrajnaVrednost 1.7
#define razmik 2*(skrajnaVrednost/(DIM))
struct kompleks{
	float re,im;
};
unsigned char dolociBarvo(struct kompleks z, struct kompleks c);
struct kompleks vsota(struct kompleks x, struct kompleks y);
struct kompleks produkt(struct kompleks x, struct kompleks y);
float absKompleks(struct kompleks z);
int map(float num);
unsigned char dolociBarvo(struct kompleks z, struct kompleks c){
	unsigned char barva;
	struct kompleks p;
	float r;
	for (barva = 0;barva<=255;barva++){
		p = produkt(z,z);
		z = vsota(p,c);
		r = absKompleks(z);
		if (r>2){
			return barva;
		}
	}
	return barva; 
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
	struct kompleks z,c;
	z.re = -skrajnaVrednost;
	z.im = skrajnaVrednost;
	c.re = -0.55;
	c.im = 0.5;
	for(int i = 0;i<DIM;i++){
		for (int j = 0;j<DIM;j++){
			slika[i][j]=dolociBarvo(z,c);
			z.re += razmik;
		}
		z.im -= razmik;
		z.re = -skrajnaVrednost;
	}
	shraniBMP(slika,DIM,DIM,"Fraktali/fraktal.bmp");
	return 0;
}
