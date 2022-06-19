#include <stdio.h>
#include <stdlib.h>
struct vozlisce2{
    int vrednost;
};
typedef struct{
    int vrednost;
    
}vozlisce;

int main()
{
    vozlisce *prvi = NULL;
    struct vozlisce2 *drugi;
    prvi = malloc(1);
    drugi = malloc(1);
    prvi->vrednost = 256;
    drugi->vrednost = 127;
    printf("%d %d\n",prvi->vrednost,drugi->vrednost);
    printf("%d",sizeof(int));
    return 0;
}

