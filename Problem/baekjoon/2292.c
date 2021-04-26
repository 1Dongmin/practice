#include <stdio.h>

int inp(void);
int cal(int);

int main(void)
{
    printf("%d", cal(inp()));
    return 0;
}

int inp()
{
    int intp;
    scanf("%d", &intp);
    return intp;
}

int cal(int stk)
{
    int cnt = 1, n;
    if(stk == 1){
        return 1;
    }
    for (n = 1; ; n++){
        cnt += n * 6;
        if(cnt >= stk){
            break;
        }
    }
    return n + 1;
}
