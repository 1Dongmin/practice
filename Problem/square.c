#include <stdio.h>
#define ll long long
int main ()
{
	unsigned ll min, max, count = 0, squre = 0;
	scanf("%llu", &min);
	scanf("%llu", &max);
	printf("\n%llu %llu \n", min, max);
	for(int a = min; a < max; a++)
	{
		for(squre = 0; (a - squre*squre) >= 0; squre++)
		{
			if ((a * a) != min){count++;}
		}
	}
	printf("\n%d", count);
	return 0;
}
