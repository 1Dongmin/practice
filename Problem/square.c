#include <stdio.h>
#define ll long long
int main ()
{
	ll min, max, count = 0, square = 0;
	scanf("%lld %lld", &min, &max);
	for(square = 1; square <= max; square++)
	{
		che1:
		if ((square * square) <= (min-1)){square++;goto che1;}
		if (min <= (square * square) && (square * square) <= max) 
		{
			count++;
			printf("count! square: %lld max:%lld \n", square, max);
		}
		printf("min: %lld square: %lld\n", min, square);
	}
	printf("count: %lld\n", count);
	printf("%lld",(max - min + 1)- count);
	return 0;
}
