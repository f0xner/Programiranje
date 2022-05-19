#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ime[20];//pri tabelah se kopira cela tabela in ne kazalec, kot bi se če tabela ne bi bila zapakirana v struct
    //int *t;//kazalci se pa se obnašajo, kot če ne bi bili zapakirani v struct
    int vpSt;
} student_t;

//strukturna značka (tag)
//to je enako kot če bi uporabil typedef
struct student{
    char ime[20];
    int vpSt;
    struct student *k;
}; //s tem lahko naredimo tudi povezan seznam


//typedef obstoječi_tip nov_tip;
//typedef int bool;
//bool a;a je tipa bool, a v resnici je tipa int


//=== meni ===

typedef struct {
    int st;
    char tekst[20];
    void (*f)(void);
} postavka_t;

int globalnaStevilka;
char globalniTekst[20];
postavka_t *trenMeni;

void nastaviPodatke(void);
void izpisiPodatke(void);
void izhod(void);
void nastaviTekst(void);
void nastaviStevilko(void);
void nazaj(void);
void izpisiMeni(postavka_t *meni);
void izvediPostavko(postavka_t *meni,int izbira);

postavka_t glavniMeni[4] = {
    {1,"Nastavi podatke",nastaviPodatke},
    {2,"Izpiši podatke",izpisiPodatke},
    {3,"Izhod",izhod},
    {0}
};
postavka_t podMeni[4] = {
    {1,"Nastavi tekst",nastaviTekst},
    {2,"Nastavi številko",nastaviStevilko},
    {3,"Nazaj",nazaj},
    {0}
};

int main(void){
    //scanf("%d",&st1.vpSt);
    //gets(st1.ime);
    /*
    struct student stud = {"ime",7516}, *k;
    k = &stud;
    student_t st1[2] = {{"Will Smith",69},{"Chris Rock",96}},st2 = {"ime",1351};

    printf("%s %d\n",k->ime,k->vpSt);//ker je k kazalec je "->" namesto "."
    */
    // for (int i = 0;i<2;i++){
    //     printf("%s %d\n",st1[i].ime,st1[i].vpSt);
    // }

    //=== meni ===
    int izbira;
    system("chcp 1250");//? poglej kaj to pomeni
    trenMeni = glavniMeni;
    while(1){
        izpisiMeni(trenMeni);
        scanf("%d",&izbira);
        izvediPostavko(trenMeni,izbira);
    }

    return 0;
}

void nastaviPodatke(void){
    trenMeni = podMeni;
}
void izpisiPodatke(void){
    printf("%s %d\n",globalniTekst,globalnaStevilka);
}
void izhod(void){
    exit(0);//kot ce bi dau return v main funkciji, 0 zakljuci aplikacijo brez napak, !=0 zakljuci aplikacijo z napako
}
void nastaviTekst(void){
    printf("Vpiši tekst: ");
    scanf("%s",&globalniTekst);
}
void nastaviStevilko(void){
    printf("Vpiši številko: ");
    scanf("%d",&globalnaStevilka);
}
void nazaj(void){
    trenMeni = glavniMeni;
}
void izpisiMeni(postavka_t *meni){
    for (;meni->st;meni++){
        printf("%2d) %s\n",meni->st,meni->tekst);
    }
}
void izvediPostavko(postavka_t *meni,int izbira){
    for (;meni->st;meni++){
        if(meni->st == izbira){
            meni->f();
        }
    }
}