#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool arr[20000] = {false};
    int sum = 0, temp = 0;
    for(int i = 1; i < 10000; i++){
        temp = i;
        for(;;){
            if(temp == 0) break;
            sum += temp % 10;
            temp = temp / 10;
        }
        sum = i + sum;
        arr[sum] = true;
        if(arr[i] == false){
            printf("%d\n", i);
        }
        sum = 0;
    }
    return 0;
}
