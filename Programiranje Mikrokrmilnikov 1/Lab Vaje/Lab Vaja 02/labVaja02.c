#include <stdio.h>
#include <stdlib.h>
// #include "../Lab\ Vaja\ 01/lavVaja01.c"


struct kompleks{
	float re,im;
};
struct kompleks vsota(struct kompleks x, struct kompleks y){
	struct kompleks z;
	z.re = x.re+y.re;
	z.im = x.im+y.im;
	return z;
}
struct kompleks razlika(struct kompleks x, struct kompleks y){
	struct kompleks z;
	z.re = x.re-y.re;
	z.im = x.im-y.im;
	return z;
}
struct kompleks produkt(struct kompleks x, struct kompleks y){
	struct kompleks z;
	z.re = x.re * y.re - x.im * y.im;
	z.im = x.re * y.im + y.re * x.im;
	return z;
}
struct kompleks kvocient(struct kompleks x, struct kompleks y){
	struct kompleks z;
	z.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
	z.im = (x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im);
	return z;
}
int vnos(int n,struct kompleks q,struct kompleks w){
	struct kompleks rez;
	switch(n){
		case 2:
			rez = vsota(q,w);
			if (rez.re != 0 && rez.im != 0){
				printf("Vsota: %.1f%+.1fi\n",rez.re,rez.im);
			}else if (rez.re == 0 && rez.im != 0){
				printf("Vsota: %.1fi\n",rez.im);
			}else if (rez.re != 0 && rez.im == 0){
				printf("Vsota: %.1f\n",rez.re);
			}else{
				printf("Vsota: 0\n");
			}
		break;
		case 3:
			rez = razlika(q,w);
			if (rez.re != 0 && rez.im != 0){
				printf("Razlika: %.1f%+.1fi\n",rez.re,rez.im);
			}else if (rez.re == 0 && rez.im != 0){
				printf("Razlika: %.1fi\n",rez.im);
			}else if (rez.re != 0 && rez.im == 0){
				printf("Razlika: %.1f\n",rez.re);
			}else{
				printf("Razlika: 0\n");
			}
		break;
		case 4:
			rez = produkt(q,w);
			if (rez.re != 0 && rez.im != 0){
				printf("Produkt: %.1f%+.1fi\n",rez.re,rez.im);
			}else if (rez.re == 0 && rez.im != 0){
				printf("Produkt: %.1fi\n",rez.im);
			}else if (rez.re != 0 && rez.im == 0){
				printf("Produkt: %.1f\n",rez.re);
			}else{
				printf("Produkt: 0\n");
			}
		break;
		case 5:
			rez = kvocient(q,w);
			if (rez.re != 0 && rez.im != 0){
				printf("Kvocient: %.1f%+.1fi\n",rez.re,rez.im);
			}else if (rez.re == 0 && rez.im != 0){
				printf("Kvocient: %.1fi\n",rez.im);
			}else if (rez.re != 0 && rez.im == 0){
				printf("Kvocient: %.1f\n",rez.re);
			}else{
				printf("Kvocient: 0\n");
			}
		break;
	}
	return 0;
}
int main(){
	int ukaz;
	int operacij = 0;
	struct kompleks q, w;
	printf("\nUkazi ko so na voljo:\n  (1) Vnos\n  (2) Vsota\n  (3) Razlika\n  (4) Produkt\n  (5) Kvocient\n  (6) Izhod\nVnesi št. ukaza:");
	scanf("%d",&ukaz);
	while(ukaz!=6){
		if (ukaz == 1){
			printf("Prvo kompleksno število(a+bi): ");
			scanf("%f%fi",&q.re,&q.im);
			while(getchar()!='\n');

			printf("Drugo kompleksno številob(a+bi): ");
			scanf("%f%fi",&w.re,&w.im);
			while(getchar()!='\n');
		}
		else if (ukaz >= 2 && ukaz < 6){
			vnos(ukaz,q,w);
			operacij++;
		}else{
			printf("Vnesen ukaz ne obstaja.\n");
		}
		printf("\nUkazi ko so na voljo:\n  (1) Vnos\n  (2) Vsota\n  (3) Razlika\n  (4) Produkt\n  (5) Kvocient\n  (6) Izhod\nVnesi št. ukaza:");
		scanf("%d",&ukaz);
	}
	printf("Program se je kočal, izvedenih je bilo %d operacij, adijo.\n",operacij);
	return 0;
}
