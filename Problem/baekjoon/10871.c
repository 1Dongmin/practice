#include <stdio.h>
#include <stdlib.h>
int main()
{
    int na, x;
    scanf("%d %d", &na, &x);
    int *n = malloc(sizeof(int) * na);
    for(int i = 0; i < na; i++)
    {
        scanf("%d", n[i]);
    }
    for (int k = 0; k < na; k++){
        if(n[k] < x){
            printf("%d", n[k]);
        }
    }
}
