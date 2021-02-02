#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int inp[10], tmp[10], remain[10], temp, fin = 0, savno = 0;
    for (int i = 0; i <= 9; i++) {
        scanf("%d", &temp);
        inp[i] = temp;
        remain[i] = temp % 42;
        //printf("remain[i] = %d\n", remain[i]);
        if (i == 0)fin++;
        for (int k = 0; k < i; k++) {
            if (remain[k] == remain[i]) {
                //printf("있던 수 %d\n", remain[i]);
                break;
            }
            if (k == (i - 1)) {
                //printf("Hit!\n");
                fin++;
            }
        }
    }
    printf("%d\n", fin);
}
