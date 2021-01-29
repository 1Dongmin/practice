#include <stdio.h>
int main(){
    int a, b, c, sum, tmp[10] = {0}, num[10] = {0}, k = 0, tmp1 = 0;
    scanf("%d %d %d", &a, &b, &c);
    sum = a * b * c;
    for(int i = 1; i <= 100000000; i = i * 10){
        tmp[k] = sum / i
        tmp1 = sum / i;
        
        k++;
    }
    for(k = 0; k <= 9; k++){
        if(k == tmp[k])
            num[k] = num[k] + 1;
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", num[0], num[1], num[2], num[3], num[3], num[4], num[5], num[6], num[7], num[8], num[9]);
}
