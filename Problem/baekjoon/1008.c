#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%.10lf", (double)a / (double)b);

	return 0;
}
