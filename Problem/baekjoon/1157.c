#include <stdio.h>

int main(void)
{
    char wd[1000001];
    int max = 0, alp[26] = {0}, wbhi = 0, manyalp = 0;
    scanf("%s", wd, 1);
    for(int i = 0; wd[i] != 0; i++){
        for (int k = 0; k < 26; k++)
        {
            if (k + 97 == wd[i]) { alp[k] += 1; }
            if (k + 65 == wd[i]) { alp[k] += 1; }
        }
    }
    for (int k = 0; k < 26; k++){
        if(alp[k] > max){
            max = alp[k];
            manyalp = k;
        }
    }
    for (int k = 0; k < 26; k++){
        if(alp[k] == max){
            wbhi += 1;
        }
    }
    if(wbhi > 1)
        {
            printf("?");
        }
    else{
        printf("%c", manyalp + 65);
    }
    //printf("\nMax: %d\nwbhi: %d\nmanyalp: %d\n", max, wbhi, manyalp);
    return 0;
}
