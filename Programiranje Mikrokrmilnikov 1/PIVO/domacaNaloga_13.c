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
int Pow(int n);
int operatorjev(char *ns);
int getLStevilo(int i, char *str);
int getRStevilo(int i, char *str);
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
    printf("calc= %d\n", calc("4-4*51 -12*2*6 - 15*2 * 5"));
    //printf("calc= %d\n", calc(" -3 + 2 * 5 "));
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
int Pow(int n){
    if (n == 0)return 1;
    else{
        int ret = 1;
        for (int i = 0;i<n;i++){
            ret = ret*10;
        }
        return ret;
    }

}
int operatorjev(char *ns){
    int oper = 0;
    int len = 0;
    for (int i = 0;ns[i];i++)len+=1;
    for (int i = 0;i<len;i++){
        if(ns[i] == '*')oper++;
    }
    return oper;
}
int getLStevilo(int i, char *str){
    int k = 0,n = i-1,steviloL=0;
    while((str[n]>=48 && str[n]<=57) || str[n] == 45){
        if(str[n]==45)break;
        int s = (str[n]-'0');
        if(s == 0 && n != i-1)s++;
        steviloL += s*(Pow(k));
        if(str[n]!=' '){
            n--;
            k++;
        }
    }
    return steviloL;
}
int getRStevilo(int i, char *str){
    int n = i+1,steviloR=0;
    while((str[n]>=48 && str[n]<=57) || (str[n] == 45 && n == i+1)){
        if(str[n]==45)break;
        int s = (str[n]-'0');
        steviloR = steviloR*10 + s;
        if(str[n]!=' '){
            n++;
        }
    }
    return steviloR;
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
    int i = 0;
    //printf("%s\n",brezPresledkov);
    while(operatorjev(brezPresledkov)){
        if(brezPresledkov[i]=='*'){
            int stevilo1 = getLStevilo(i,brezPresledkov);
            int len1 = (int)((ceil(log10(stevilo1)))*sizeof(char));
            int stevilo2 = getRStevilo(i,brezPresledkov);
            int len2 = (int)((ceil(log10(stevilo2)))*sizeof(char));
            int nstevilo = stevilo1*stevilo2;
            
            //printf("ls=%d ds=%d\n",stevilo1,stevilo2);
            int nLen;
            if(nstevilo%10==0){
                nLen = (int)((ceil(log10(nstevilo+1)))*sizeof(char));
            }else{
                nLen = (int)((ceil(log10(nstevilo)))*sizeof(char));
            }
            int off = nLen-(len1+len2+1);
            char strNou[nLen];
            int a = 0;
            sprintf(strNou, "%d", nstevilo);
            //printf("off=%d nLen=%d\n",off,nLen);
            //printf("j>=%d j<%d\n",(i-len1),(i-len1+nLen));
            //printf("strNou=%s\n",strNou);
            for (int j = (i-len1),k = 0;brezPresledkov[j];j++){
                if(j<(i-len1+nLen) && k<nLen){
                    brezPresledkov[j] = strNou[k];
                    //printf("sN %c",strNou[k]);
                    k++;
                }
                if(j>(i-len1+nLen) && nLen == (-off)){
                    brezPresledkov[j] = brezPresledkov[j-off];
                }
                if(j>(i-len1+nLen) && nLen != (-off)){
                    brezPresledkov[j+off] = brezPresledkov[j];
                }
                a = j;
            }
            brezPresledkov[a] = 0;
            len+=off;
            //printf("\n\n\n");
            //printf("%s\n\n",brezPresledkov);
        }
        i++;
        if(i>len)i=0;
    }
    for(int j = 0;brezPresledkov[j];j++){
        printf("%c",brezPresledkov[j]);
    }
    return 0;
}
// int calc(char *str){
//     int len = 0;
//     int slen = 0;
//     for (int i = 0;str[i]!=0;i++){
//         if(str[i]!=' '){
//             len+=1;
//         }
//         slen+=1;
//     }
//     char ns[len];
//     int j = 0;
//     for(int i = 0;i<slen;i++){
//         if(str[i]!=32){
//             ns[j] = str[i];
//             j++;
//         }
//     }
//     int i = 0;
//     int des = 0;
//     printf("%s\n",ns);
//     while(operatorjev(ns) && des <20){
//         int stevilo1=0,stevilo2=0;
//         if(ns[i]=='*'){
//             stevilo1 = getLStevilo(i,ns);
//             stevilo2 = getRStevilo(i,ns);
//             int enough1 = (int)((ceil(log10(stevilo1)))*sizeof(char));
//             int enough2 = (int)((ceil(log10(stevilo2)))*sizeof(char));
//             int enough = enough1+enough2+1;
//             int novoStevilo = stevilo1 * stevilo2;
//             int novoEnough = (int)((ceil(log10(novoStevilo)))*sizeof(char));
//             char strNou[novoEnough];
//             sprintf(strNou, "%d", novoStevilo);
//             printf("\n");
//             printf("st1=%d st2=%d nst=%s\n****",stevilo1,stevilo2,strNou);
//             printf("\n\n");
//             //printf("j=%d <=%d\n",i-enough1,i+enough2);
//             for(int j = i-enough1,k = 0;j<=(i+enough2);j++,k++){
//                 //printf("%c j=%d\n",ns[j],(i+enough2));
//                 if(j>=(i-enough1+novoEnough))ns[j]='_';
//                 else ns[j] = (char)strNou[k];
//             }
//             printf("\n%s\n",ns);
//         }
//         //if(i>len)i=0;
//         i++;
//         des++;
//     }
//     return 0;
// }