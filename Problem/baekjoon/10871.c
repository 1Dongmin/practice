#include <stdio.h>
#include <stdlib.h>
int main()
{
    int na, x, temp;
    scanf("%d %d", &na, &x);
    int* n = (int*)malloc(sizeof(int) * na);
    for (int i = 0; i < na; i++)
    {
        scanf("%d", &temp);
        n[i] = temp;
    }
    for (int k = 0; k < na; k++) {
        if (n[k] < x) {
            printf("%d ", n[k]);
        }
    }
    free(n);
}
//배열 동적할당 기본
