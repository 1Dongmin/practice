#include <stdio.h>
int main ()
{
    int Firsig, Subsig, sig[3],temp;
    scanf("%d %d", &Firsig, &Subsig);
    
    sig[0] = Subsig/100;
    for(temp = Subsig; temp > 100;temp = temp - 100){}
    sig[1] = temp/10;
    sig[2] = temp%10;
    
    printf("%d\n%d\n%d\n%d\n",sig[2] * Firsig, sig[1] * Firsig, sig[0] * Firsig, Firsig * Subsig);
}
