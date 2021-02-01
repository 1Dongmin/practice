#include <stdio.h>
int main(){
    int a, b, c, sum, tmp[10] = {0}, num[10] = {0}, k = 9, tmp1 = 0, checknum1 = 0;
    scanf("%d %d %d", &a, &b, &c);
    sum = a * b * c;
    tmp1 = sum;
    for(int i = 0; i <= 9; i++){
        tmp[k] = tmp1 % 10;
        tmp1 = tmp1 / 10;
        if(tmp1 < 1) break;
        k--;
    }
    for(k = 0; k <= 9; k++){
        if(tmp[k] == 0){
		if(checknum1 == 0)continue;
	num[0]++; checknum1++;}
        else if(tmp[k] == 1){num[1]++; checknum1++;}
        else if(tmp[k] == 2){num[2]++; checknum1++;}
        else if(tmp[k] == 3){num[3]++; checknum1++;}
        else if(tmp[k] == 4){num[4]++; checknum1++;}
        else if(tmp[k] == 5){num[5]++; checknum1++;}
        else if(tmp[k] == 6){num[6]++; checknum1++;}
        else if(tmp[k] == 7){num[7]++; checknum1++;}
        else if(tmp[k] == 8){num[8]++; checknum1++;}
        else if(tmp[k] == 9){num[9]++; checknum1++;}
	
        //printf("%d",tmp[k]);
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], num[9]);
}
