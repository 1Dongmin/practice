#include <stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    for(int i = 1; i <= a; i++){
        for(int b = i; (a - b) > 0; b++){
            printf(" ");
        }
        for(int k = 1; k <= i; k++){
            printf("*");
        }
        printf("\n");
    }
}
