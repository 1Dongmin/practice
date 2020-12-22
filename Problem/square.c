#include <stdio.h>
#define ll long long
int main () {
	unsigned ll min, max, count = 0, squre = 0;
	scanf("%llu", &min);
	scanf("%llu", &max);
	printf("\n%llu %llu \n", min, max); //input check
	for(; min < max; min++){
		for(; (squre * squre) <= min; squre++){
			if ((squre * squre) != min){
				count++;
				printf("count! count: %llu suqre: %llu\n",count,squre * squre) //count check
				
			}
		}
	}
	printf("\n%llu", count);
	return 0;
}
