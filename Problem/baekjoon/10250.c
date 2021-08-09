#include <stdio.h>

int main(void)
{
    int BulHight, W, CustNum, rep;
    scanf("%d", &rep);

    for (int i = 0; i < rep; i++)
    {
        scanf("%d %d %d", &BulHight, &W, &CustNum);
        if (BulHight == 1){
            printf("%d\n", CustNum * 1 + 100);
            continue;
        }
        if(CustNum % BulHight == 0){
            printf("%d\n", CustNum / BulHight + BulHight * 100);
            continue;
        }
        else{
            //be the one
            printf("%d\n", (CustNum / BulHight + 1) + ((CustNum % BulHight) * 100));
        }
    }
    return 0;
}
