#include <stdio.h>
#include <math.h>

struct skatla{
    float koren;
    float kvadrat;
    float kub;
}typedef skatla;
struct par{
    int levoStevilo;
    int desnoStevilo;
    int skupaj;
}typedef par;
skatla potenciraj(float cifra);
int numWords(char *str);
unsigned int filtriraj(int *d, int *f, unsigned int n, unsigned int nf);
int calc(char *str);

int main(void){
    //potenciraj
        //skatla rezultat;
        //float cifra = 2;
        //rezultat = potenciraj(cifra);
        //printf("Koren=%.1f, kvadrat=%.1f, kub=%.1f.",rezultat.koren,rezultat.kvadrat,rezultat.kub);
    //numWords
        //printf("%d\n", numWords("(a-b)(c-d)"));
        //printf("%d\n", numWords("aa#bb c99!"));
    //filter
        //int data1[]={1,2,5,3,1,6,5,4,3,7,8,9,2,3,5,6,7};
        //int data2[]={1,2,5,3,1,6,5,4,3,7,8,9,2,3,5,6,7};
        //int data3[]={1,2,5,3,1,6,5,4,3,7,8,9,2,3,5,6,7};
        //int data4[]={1,2,5,3,1,6,5,4,3,7,8,9,2,3,5,6,7};//3,6,4,3,7,8,9,3,6,7
        //int data5[]={1,2,5,3,1,6,5,4,3,7,8,9,2,3,5,6,7};
        //int filter[]={1,2,5,6};
        //unsigned int n, i;
        //	
        //n=filtriraj(data2, filter, sizeof(data2)/sizeof(int), 1);
        //printf("%u:", n);
        //for(i=0;i<n;i++) {
        //    printf(" %u" , data2[i]);
        //}
    //calc
    //12*2*6   24*12
    //4*50 + 44 -12*2*6 - 15*2 * 5
    printf("calc= %d\n", calc("4*50 + 44 -12*2*6 - 15*2 * 5"));
    printf("calc= %d\n", calc(" -3 + 2 * 5 "));
    printf("calc= %d\n", calc("15*20+37*5*3-24*14"));
    // par zmnozek;
    // zmnozek.desnoStevilo = getLStevilo(1,"4*5*4");
    // zmnozek.levoStevilo = getRStevilo(1,"4*5*4");
    // zmnozek.skupaj = zmnozek.desnoStevilo*zmnozek.levoStevilo;
    // printf("%d",zmnozek.skupaj);
    return 0;
}
skatla potenciraj(float cifra){
    skatla rezultat;
    skatla *rez = &rezultat;
    rez->koren = sqrt(cifra);
    rez->kvadrat = (cifra*cifra);
    rez->kub = rez->kvadrat*cifra;
    return rezultat;
}
int numWords(char *str){
    int besed = 0;
    int niz = 0;
    int pogoj2 = 1;
    for (int i = 0;str[i]!='\0';i++){
        int st = (int)str[i];
        int pogoj = (( st >=48 && st <= 57) || ((st >= 65 && st <= 90) || (st >= 97 && st <= 122)) || (st == 45 || st == 95));
        if(!pogoj){niz = 0;continue;}
        if(pogoj && !niz){besed++;niz = 1;}
    }
    return besed;
}
unsigned int filtriraj(int *d,int *f,unsigned int n, unsigned int nf){
    int nouN = 0;
    if (nf == 0)return n;
    else{
        for (int i = 0;i<n;i++){
            int seNePojavi = 1;
            for (int j = 0;j<nf;j++){
                if(d[i] == f[j]){
                    seNePojavi = 0;
                    break;
                }
            }
            if(seNePojavi){
                d[nouN] = d[i];
                nouN++;
            }
        }
        return nouN;
    } 
}
int calc(char *str){
    int len = 0;
    for (int i = 0;str[i]!='\0';i++){
        if(str[i]!=' ')len++;
    }
    char brezPresledkov[len];
    for (int i = 0,j = 0;str[i]!='\0';i++){
        if(str[i] != ' '){
            brezPresledkov[j] = str[i];
            j++;
        }
    }
    int vsota = 0;
    int rez = 0;
    int predznak = 0;
    int zmnozek = 0;
    int zadnjiZmnozek = 0;
    int predZmnozek = 0;
    for(int n = 0;brezPresledkov[n] != '\0';n++){
    	if(brezPresledkov[n] >=48 && brezPresledkov[n] <= 57){
    		int stevka = (brezPresledkov[n]-'0');
    		rez = rez*10 + stevka;
    		continue;
    	}else if (brezPresledkov[n] == '*'){
    		if(zmnozek != 0) zmnozek *= rez;
    		else zmnozek = rez;
    		predZmnozek = zmnozek;
    		zadnjiZmnozek = 1;
    		rez = 0;
    		continue;
    	}else if (predznak && (brezPresledkov[n] == '+'  || brezPresledkov[n] == '-' )){
    		predZmnozek = 0;
    		zadnjiZmnozek = 0;
    		if (brezPresledkov[n] == '+')predznak = 0;
    		if(zmnozek != 0) {
    			vsota -= zmnozek*rez;
    			zmnozek = 0;
    		}else vsota -= rez;
    		rez = 0;
    		continue;
    	}else if (brezPresledkov[n] == '+' || brezPresledkov[n] == '-'){
    		predZmnozek = 0;
    		zadnjiZmnozek = 0;
    		if (brezPresledkov[n] == '-') predznak = 1;
    		if(zmnozek != 0) {
    			vsota += zmnozek*rez;
    			zmnozek = 0;
    		}else vsota += rez;
    		rez = 0;
    		continue;
    	}
    }
    if(rez != 0){
    	if(predznak){
    		if(predZmnozek){
    			vsota-=predZmnozek*rez;
    		}else{
    			vsota-=rez;
    		}
    	}else {
    		if(zadnjiZmnozek){
    			vsota+=predZmnozek*rez;
    		}else{
    			vsota+=rez;
    		}
    	}
    }
    return vsota;
}

