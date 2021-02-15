#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char inpchar[101], temp[101];
	long long sum = 0 ,size;
	scanf("%lld", &size);
	//for (int i = 0; i < size; i++)scanf("%s", &inpchar[i]);
	
	inpchar[0] = getchar();
	for (long long k = 0; k < size; k++) {
		inpchar[k] = getchar();
		sum += atoll(&inpchar[k]);
        if (k == size) inpchar[k] = NULL;
		//printf("\n###%c###\n", inpchar[k]);
	}
	printf("%lld", sum);
	return 0;
}
