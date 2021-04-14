#include <stdio.h>

int main(void)
{
    char st[101];
    scanf("%s", st, 1);
    int alpnumber = 0;
    for (int k = 0; st[k] != 0; k++){
        if(st[k] == 99){    //c=, c- 인식
            if (st[k + 1] == 61 || st[k + 1] == 45)
            {
                alpnumber += 1;
                k++;
                continue;
            }
        }
        if(st[k] == 100){   //dz=, d- 인식
            if((st[k + 1] == 122 && st[k + 2] == 61))
            {
                alpnumber += 1;
                k += 2;
                continue;
            }
            if (st[k + 1] == 45){
                alpnumber += 1;
                k++;
                continue;
            }
        }
        if(st[k] == 108){   //lj 인식
            if(st[k+1] == 106){
                alpnumber += 1;
                k++;
                continue;
            }
        }
        if(st[k] == 110 && st[k+1] == 106){ //nj인식
            alpnumber += 1;
            k++;
            continue;
        }
        if(st[k] == 115 && st[k+1] == 61){  //s= 인식
            alpnumber += 1;
            k++;
            continue;
        }
        if(st[k] == 122 && st[k+1] == 61){
            alpnumber += 1;
            k++;
            continue;
        }    //z= 인식
        else {
            alpnumber += 1;
        }
        
    }
    printf("%d", alpnumber);
    return 0;
}
