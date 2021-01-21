#include <stdio.h>
int main()
{
    int si, boon;
    scanf("%d %d", &si, &boon);
    if(si < 1 && boon < 45)
        si += 24;
    if(boon < 45)
    {
        boon += 60;
        si -= 1;
    }
    boon -= 45;
    printf("%d %d", si ,boon);
}
