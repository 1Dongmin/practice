#include <stdio.h>
int main() {
    int inp[10], tmp[10], remain[10], temp, fin = 0;
    for (int i = 0; i <= 9; i++) {
        scanf("%d", &temp);
        inp[i] = temp;
        remain[i] = temp % 42;
    }
    for (int i = 0; i <= 9; i++) {
        if (i == 0) {
            fin++;
            tmp[i] = remain[i];
            continue;
        }
        for (int k = 0; k <= i; k++) {
            if (remain[i] == tmp[k]) {
                break;
            }
            if (k == i) {
                fin++;
                break;
            }
        }
    }
    printf("%d", fin);
}
