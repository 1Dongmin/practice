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
		printf("\nListen...");
		inpchar[k] = getchar();
		sum += atoll(&inpchar[k]);

        /*if (k == size) {
			inpchar[k] = '\0';
			printf("\n###  NULL!!!  ###\n");
		}*/
		printf("\n### times: %u ###\n### data: %c ###\n", k, inpchar[k]);
	}
	printf("%u", sum);
	return 0;
}