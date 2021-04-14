#include <stdio.h>

int main(void)
{
    char st[15];
    int time = 0;
    scanf("%s", st, 1);
    for (int k = 0; st[k] != 0; k++){
        if(st[k] >= 65 && st[k] <= 67){
            time += 3; //abc 2
        }
        if(st[k] >= 68 && st[k] <= 70){
            time += 4; //def 3
        }
        if (st[k] >= 71 && st[k] <= 73)
        {
            time += 5; //ghi 4
        }
        if (st[k] >= 74 && st[k] <= 76)
        {
            time += 6; //jkl 5
        }
        if (st[k] >= 77 && st[k] <= 79)
        {
            time += 7; //mno 6
        }
        if (st[k] >= 80 && st[k] <= 83)
        {
            time += 8; //pqrs 7
        }
        if (st[k] >= 84 && st[k] <= 86)
        {
            time += 9; //tuv 8
        }
        if (st[k] >= 87 && st[k] <= 90)
        {
            time += 10; //wxyz 9
        }
    }
    printf("%d", time);
    return 0;
}
