int Pow(int n);
int operatorjev(char *ns);
int getLStevilo(int i, char *str);
int getRStevilo(int i, char *str);
int getRStevilo(int i, char *str){
    int n = i+1,steviloR=0,negativ=0;
    while((str[n]>=48 && str[n]<=57) || (str[n] == 45 && n==i+1)){
        if(str[n]==45){negativ=1;n++;}
        if(str[n]!=45){
			int s = (str[n]-'0');
			steviloR = steviloR*10 + s;
			if(str[n]!=' '){
				n++;
			}
		}
    }
    return negativ==0?steviloR:steviloR*-1;
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
int operatorjev(char *ns){
    int oper = 0;
    int len = 0;
    for (int i = 0;ns[i];i++)len+=1;
    for (int i = 0;i<len;i++){
        if(ns[i] == '*')oper++;
    }
    return oper;
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
                if(j<=(i-len1+nLen) && k<nLen){
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
            brezPresledkov[a] = '\0';
            len+=off;
        }
        i++;
        if(i>len)i=0;
    }
