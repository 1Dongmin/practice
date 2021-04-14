#include <stdio.h>

int main(void)
{
    char wd[1000001];
    int spacebar = 0;
    scanf("%[^\n]", wd, 1);
    for(int i = 0; wd[i] != 0; i++){

        if (((wd[i] >= 65 && wd[i] <= 90) || (wd[i] >= 97 && wd[i] <= 122)))
        {
            if(wd[i+1] == 32 || wd[i+1] == 0)
            {
                spacebar += 1;
            }
        }
    }
    printf("%d\n", spacebar);
    return 0;
}
