#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char inpchar[101], temp[101];
    int size, sum = 0;
	scanf("%d", &size,4);
    scanf("%s",inpchar,1);

    for(int i = 0; i < size; i ++){
        //printf("%d\n",inpchar[i]-48);
        sum += inpchar[i] - 48;
    }
	printf("%d", sum);
	return 0;
}
