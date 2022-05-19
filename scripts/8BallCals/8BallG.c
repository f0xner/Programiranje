#include <stdio.h>
#include <stdlib.h>
#include <cmath>
int main(int argc, char *argv[]){
	int c_sum;
	int target_sum;
	int iters = 0;
	int point;
	c_sum = atoi(argv[2]);
	target_sum = atoi(argv[3]);
	iters = 0;
	point = pow(2,atoi(argv[1]));
	while (c_sum <= target_sum){
		iters+=1;
		c_sum += point;
		if(point<4096){
			point*=2;
		}
	}
	printf("Games to play %d\n",iters);
	printf("Total points %d\n",c_sum);
	return 0;
}
