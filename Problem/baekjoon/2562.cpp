#include <stdio.h>
int main(){
    int n[9], max, count = 1, temp;
    for(int k = 0; k < 9; k++){
        scanf("%d", &temp);
        n[k] = temp;}
    max = n[0];
    for(int i = 0; i <= 9; i++){
        if(max < n[i]){
            max = n[i];
            count = i + 1;}
    }
    printf("%d\n%d", max, count);
}
