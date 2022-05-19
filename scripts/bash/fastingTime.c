#include <stdio.h>
int main(){
	int startedfasting;
	int timefasting;
	int endfasting;
	printf("Started fasting at(in HHMM format): ");
	scanf("%d",&startedfasting);
	printf("Time fasing(in HHMM format): ");
	scanf("%d",&timefasting);
	endfasting = startedfasting+timefasting;
	if (endfasting/100==0){
		
	}
	if (endfasting > 2359){
		printf("End on next day");
	}
	printf("Started fasting at %d, fasting time %d, end fasting %d\n",startedfasting,timefasting,endfasting);
}
