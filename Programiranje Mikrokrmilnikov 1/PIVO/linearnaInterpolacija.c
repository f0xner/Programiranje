#include <stdio.h>

int interpoliraj(float *, float *, unsigned int, float, float *);   // Prototip funkcije. 
int main(){
    float x[]={1.0, 2.0, 4.0, 5.0, 9.0};
    float y[]={0.5, 0.1, 0.7, 0.9, 1.2};
    float yt;
    int st;
    yt=0.0;
	st=interpoliraj(x, y, sizeof(x)/sizeof(float), -0.5, &yt);
	printf("%.2f %d\n", yt, st);

	yt=0.0;
	st=interpoliraj(x, y, sizeof(x)/sizeof(float), 9.0, &yt);
	printf("%.2f %d\n", yt, st);
    return 0;
}
int interpoliraj(float * tab1,float * tab2, unsigned int n, float x, float * yt){
	float ya,yb,xa,xb;
	int najI=0;
	for (int i = 0;i<n-1;i++){
		if(x>=tab1[i]&&x<=tab1[i+1])najI = i;
	}
	xa = tab1[najI];
	ya = tab2[najI];
	xb = tab1[najI+1];
	yb = tab2[najI+1];
	*yt = ya + (yb-ya)*(x-xa)/(xb-xa);
	if(x < tab1[0] || x > tab1[n-1]){*yt = 0.0;return 0;} 
	else return 1;
}
