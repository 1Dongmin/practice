#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool arr[10001] = {false};
    int sum = 0, temp = 0;
    for(int i = 1; i <= 10000; i++){
        temp = i;
        sum = 0;
        for(;;){
            if(temp == 0) break;
            sum += temp % 10;
            temp = temp / 10;
        }
        sum = i + sum;
        if(sum > 10000)continue;
        arr[sum] = true;
    }
    for(int k = 0; k <= 10000; k++){
            if(arr[k] == false){
            printf("%d\n", k);
        }
    }
    return 0;
}
