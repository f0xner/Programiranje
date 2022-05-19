#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	printf("Dobrodošel enei!\n");
	system("curl -X 'GET'   'https://api.coingecko.com/api/v3/simple/price?ids=ripple&vs_currencies=usd'   -H 'accept: application/json'~ | jq '.' | grep -e 'usd' > ripple");
	system("echo 'xrp';cat ripple");
	system("rm ripple");
	return 0;
}
