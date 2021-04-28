#include <stdio.h>

int inp(void);
int cal(int);

int main(void)
{
    cal(inp());
    
    return 0;
}

int inp(){
    int a;
    scanf("%d", &a);
    return a;
}

int cal(int in){                                        //repNum: 반복해서 더해지는 숫자, in: 입력받은 값, i: 반복한 횟수
    int repNum = 1, i, NrdNumber;
    for (i = 2; repNum < in; i++){
        repNum += i;
    }
    NrdNumber = i- 1 - (repNum - in);
    if(i%2==0){                                             //짝수일때 분모는 i - NrdNumber, 분자는 NrdNumber
        printf("%d/%d", i - NrdNumber, NrdNumber);
    }
    else{
        printf("%d/%d", NrdNumber, i - NrdNumber);          //홀수일때 분모는 NrdNumber, 분자는 i - NrdNumber
    }
    //printf("repNum: %d in: %d i: %d, NrdNumber: %d\n", repNum, in, i, NrdNumber);
    
    return 0;
}
