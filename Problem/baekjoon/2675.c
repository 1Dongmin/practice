#include <stdio.h>

int main(void)
{
    char s[1001];
    int r, rep;
    scanf("%d", &rep, 4);
    for(int j = 0; j < rep; j++){
        scanf("%d", &r, 4);
        scanf("%s", s, 1);
        for(int i = 0; s[i] != 0; i++){
            for(int k = 1; k <= r; k++){
                printf("%c",s[i]);
            }
        }printf("\n");
    }
    return 0;
}
