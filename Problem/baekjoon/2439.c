#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    for(int i = 0; i <= a; i++){
        for(int b = i; (a - i) >= 0; b++){
            printf(" ");
        }
        for(;;){
            printf("*");
        }
        printf("\n");
    }
}
