#include <stdio.h>
#include <stdbool.h>
int culcu(int i);

bool arr[10001] = {false};
int main(void)
{
    arr[0] = true;
    for(int i = 1; i <= 10000; i++){
        culcu(i);
    }
    for(int k = 0; k < 10000; k++){
            if(arr[k] == false){
            printf("%d\n", k);
        }
    }
    return 0;
}
int culcu(int i){
    int sum = 0, temp = 0;

    temp = i;
    sum = 0;
    for(;;){
        if(temp == 0) break;
        sum += temp % 10;
        temp = temp / 10;
    }
    sum = i + sum;
    if(sum > 10000)return 0;
    arr[sum] = true;
    
    return 0;
}
