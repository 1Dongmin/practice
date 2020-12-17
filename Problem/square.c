#include <stdio.h>
#define ll long long
int main ()
{
	unsigned ll min, max, count = 0, squre = 1;
	scanf("%d", &min);
	scanf("%d", &max);
	printf("\n %d %d \n", min, max);
	for(min; min < max; min++)
	{
		for(squre; (squre*squre) < max; squre++)
		{
			if ((min - (squre * squre)) == 0){count++;}
		}
	}
	printf("\n%d", count);
	return 0;
}
