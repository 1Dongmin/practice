#include <stdio.h>

int main(void)
{
    int aph[26];
    char sary[101];
    scanf("%s", sary, 1);
    for(int alp = 0; alp < 26; alp++){
        for(int strng = 0; strng < 101; strng ++){
            if (sary[strng] == 0){
                aph[alp] = -1;
                break;
            }
            if(alp + 97 == sary[strng]){
                aph[alp] = strng;
                break;
            }
        }
        printf("%d ",aph[alp]);
    }
    return 0;
}
