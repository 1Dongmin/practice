#include <stdio.h>
#define ll long long
int main ()
{
	unsigned ll min, max, count = 0, squre = 0;
	scanf("%llu", &min);
	scanf("%llu", &max);
	printf("\n%llu %llu \n", min, max);
	for(; min < max; min++)
	{
		for(; (squre * squre) <= min; squre++)
		{
			if ((squre * squre) != min){count++;}
		}
	}
	printf("\n%d", count);
	return 0;
}
