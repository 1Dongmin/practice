#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char input_char[1];
	//int N;
	long long sum = 0 ,N;
	scanf("%lld", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		input_char[0] = getchar();
		sum += atoll(input_char);
        if (i == N) NULL;
	}
	//sum++;
	printf("%lld", sum);
	return 0;
}
