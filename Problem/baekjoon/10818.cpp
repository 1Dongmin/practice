#include <stdio.h>
#include <stdlib.h>
int main(){
    int size, temp, min, max;
    scanf("%d", &size);
    int* n = (int*)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        scanf("%d", &temp);
        n[i] = temp;
    }
    min = n[0];
    max = n[0];
    for(int k = 0; k < size; k++){
        if(min > n[k]) min = n[k];
        if(max < n[k]) max = n[k];
    }
    printf("%d %d", min, max);
}
