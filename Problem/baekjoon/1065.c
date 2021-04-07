#include <stdio.h>

int main(void)
{
    int inp, hannum = 0, temp, cah ;
    scanf("%d", &inp, 4);
    for(int i = 1; i <= inp; i++){
        if(inp < 100){
            hannum++;
            continue;
        }
        else if(i < 110){
            hannum = 99;
            continue;
        }
        if(inp == 1000){
            hannum = 144;
            break;
        }
        temp = i;
        
        if((temp / 10) % 10 - temp % 10 == (temp / 100) % 10 - (temp / 10) % 10) hannum++;
        
    }
    printf("%d", hannum);
    return 0;
}
