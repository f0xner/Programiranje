#include <stdlib.h>
#include <stdio.h>

int main(void){
    char znak = 'A';
    if(znak >= 'a' && znak <= 'z'){
        znak = znak -'a' +'A';
    }else if(znak >= 'A' && znak <= 'Z'){
        znak = znak +'a' -'A';
    }

    printf("%c\n",znak);
    return 0;
}