#include <stdio.h>
#include <stdlib.h>
int mian(){
    int size, max = 0, min = 100;
    scanf("%d", &size);
    double* score =(double*)malloc(sizeof(double) * size);
    for(int i = 0; i < size; i++){
        scanf("%d", score[i]);
    }
    for(int i = 0; i < size; i++){
        if(score[i] > max)max = score[i];
        if(score[i] < min)min = score[i];
    }
    for(int i = 0; i < size; i++){
        score[i] = (double*)score[i] / max * 100;
        int sum;
    }
    
}
