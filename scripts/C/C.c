#include <stdio.h>
int main(){
	/*
	 to je komentar toooo*/
	//==Spremenljivke==
	/*
	int myVariable;
	int a = 5;
	float b = 0.5;
	char c = 'c';
	printf("Vpiši številko \n");
	scanf("%d",&myVariable);
	printf("You entered %d \n",myVariable);
	printf("You entered %d \n",a);
	printf("You entered %f \n",b);
	printf("You entered %c \n",c);
	*/
	// == if,else if, else stavek
	/*
	int a,b;
	printf("Vpiši dve števili(a,b):\n");
	scanf("%d",&a);
	scanf("%d",&b);
	if (a==b) {
		printf("%d == %d\n",a,b);
		printf("Števili sta enaki\n");
	}
	else if (a<b){
		printf("%d < %d \n",a,b);
		printf("%d != %d\n",a,b);
		printf("Števili nista enaki\n");
	}
	else if (a>b){
		printf("%d > %d \n",a,b);
		printf("%d != %d\n",a,b);
		printf("Števili nista enaki\n");
	}
	else{
		printf("V tem primeru se else ne bo nikoli izvedel, je tu samo zato da vem kako bi izgledal else stavek v C\n");
	}
	*/
	// == zanke
	/*
	int i;
	for (i = 0;i<2;i++){
		printf(i)
	}*/

	//==Funkcije==
	int z = funkcija(1,2);
	printf(z);
	getchar();
	return 0;
}
int funkcija(int x, int y){
	return x+y;
}
