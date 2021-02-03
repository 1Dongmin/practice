#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
    double temp, sum = .0, max = 0, size = 0;
    scanf("%lf", &size);
    double* score = (double*)malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++) {
        scanf("%lf", temp);
        score[i] = temp;
        if (temp > max) { max = temp; }
    }
    for (int i = 0; i < size; i++) {
        score[i] = (double)score[i] / max * 100;
        sum += score[i];
    }
    printf("%lf", sum / size);
    free(score);
    return 0;
}
