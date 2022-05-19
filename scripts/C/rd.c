#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int poberiInPrenesi(char *link, char *ime);

int main(){
    system("mkdir RojstnoDnevniMemeti");
    system("curl https://imgr.search.brave.com/LnGdrOn0fQpIHxlWBw3tPlE7WQ3HNjtvMPwmUkMrudY/fit/1200/720/ce/1/aHR0cHM6Ly9pLnl0/aW1nLmNvbS92aS96/UVZoZEFJcEZQWS9t/YXhyZXNkZWZhdWx0/LmpwZw --output slika1.png");
    system("mv slika1.png RojstnoDnevniMemeti/slika1.png");
    system("curl https://imgr.search.brave.com/nOCC33ffS-BC2Q5aLqtPoBtLeza3y_3Bn-5E6n2zto8/fit/1017/1070/ce/1/aHR0cHM6Ly9pMi53/cC5jb20vd3d3LnRp/bmFtYXplLmNvbS93/cC1jb250ZW50L3Vw/bG9hZHMvMjAyMC8w/Ni9mdW5ueS1oYXBw/eS1iaXJ0aGRheS1t/ZW1lLmpwZz9maXQ9/MTAxNyUyQzEwNzAm/c3NsPTE --output slika2.png");
    system("mv slika2.png RojstnoDnevniMemeti/slika2.png");
    system("curl https://imgr.search.brave.com/QIa8kGmQGXekX_38-_hxY7ZC_pdpkipCf-u_q_FPEjA/fit/474/225/ce/1/aHR0cHM6Ly90c2U0/Lm1tLmJpbmcubmV0/L3RoP2lkPU9JUC50/OFIzcW1SMnZtSEF2/cHc5Rl9sWHp3SGFI/YSZwaWQ9QXBp --output slika3.png");
    system("mv slika3.png RojstnoDnevniMemeti/slika3.png");
    system("curl https://imgr.search.brave.com/Dn3KS5O7e3zRvLUUQ4aX4UX2K5noihefKVlW9EUCcGU/fit/474/225/ce/1/aHR0cHM6Ly90c2Uz/Lm1tLmJpbmcubmV0/L3RoP2lkPU9JUC5i/VjMtSFZ1NVREZVNl/eUt3Szl5ZUV3SGFI/YSZwaWQ9QXBp --output slika4.png");
    system("mv slika4.png RojstnoDnevniMemeti/slika4.png");
    system("curl https://imgr.search.brave.com/TuebdtKZ545dOPJCFvrBI7qIOFw9MX8pgLbYkhbg0v4/fit/474/225/ce/1/aHR0cHM6Ly90c2Uz/Lm1tLmJpbmcubmV0/L3RoP2lkPU9JUC44/aHdOWjZ1S0hWanhG/UWdNczZGR1dRSGFI/YSZwaWQ9QXBp --output slika5.png");
    system("mv slika5.png RojstnoDnevniMemeti/slika5.png");
    system("curl https://imgr.search.brave.com/BYHIW81a9kL3Qfv4cKU9s3SUF_VvrghxfcYvKbYK3q0/fit/474/225/ce/1/aHR0cHM6Ly90c2Uy/Lm1tLmJpbmcubmV0/L3RoP2lkPU9JUC5Y/blVTWUptT2VIOTZ2/RHFZeUxKdmx3SGFI/YSZwaWQ9QXBp --output slika6.png");
    system("mv slika6.png RojstnoDnevniMemeti/slika6.png");
    printf("Odpri ustvarjeno mapo in vse najboljše!");
    return 0;
}
